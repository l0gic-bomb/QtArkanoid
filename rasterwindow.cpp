
#include <QApplication>
#include "rasterwindow.h"

constexpr unsigned WINDOW_WIDTH  = 800;
constexpr unsigned WINDOW_HEIGHT = 800;

RasterWindow::RasterWindow(QWindow* parent)
    : QWindow(parent),
      _backingStore(new QBackingStore(this)),
      _scene(std::make_unique<PoolTableScene>(RectF{0, 0, float(WINDOW_WIDTH ), float(WINDOW_HEIGHT)}))
{
    setMinimumSize(QSize(800, 800));
    _updateTimer.start();
}

bool RasterWindow::isAnimating() const
{
    return _isAnimating;
}

void RasterWindow::setAnimating(const bool &isAnimating)
{
    _isAnimating = isAnimating;
    if (isAnimating)
        renderLater();
}

bool RasterWindow::event(QEvent* event)
{
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void RasterWindow::resizeEvent(QResizeEvent* resizeEvent)
{
    _backingStore->resize(resizeEvent->size());
    if (isExposed())
        renderNow();
}

void RasterWindow::exposeEvent(QExposeEvent *)
{
    if (isExposed())
        renderNow();
}

void RasterWindow::keyPressEvent(QKeyEvent *event)
{
    int x;
    switch (event->key()) {
    case Qt::Key_Escape:
        qApp->exit();
        break;
    case Qt::Key_Left:
        x = 5;
        _scene->movePlatform(-x);
        break;
    case Qt::Key_Right:
        x = 5;
        _scene->movePlatform(x);
        break;
    default:
        QWindow::keyPressEvent(event);

    }
}

void RasterWindow::renderLater()
{
    requestUpdate();
}

void RasterWindow::renderNow()
{
    // Метод в котором реализуется двойная буферизация
    if (!isExposed())
        return;

    updateScene();
    renderScene();

    if (_isAnimating)
        renderLater();
}

void RasterWindow::updateScene()
{
    //Считаем количество секунд
    const float elapsedSeconds = float(_updateTimer.elapsed()) / 350.f;

    if (elapsedSeconds > 0) {
        // перезапускаем таймер
        _updateTimer.restart();
        // обновляем сцену
        _scene->ballHitWall(elapsedSeconds);
        _scene->ballHitPlatform(elapsedSeconds);
    }
}

void RasterWindow::renderScene()
{
    QRect rect(0, 0, width(), height()); // Область на которой будем рисовать

    _backingStore->beginPaint(rect); // начниаем рисовать
    QPaintDevice *device = _backingStore->paintDevice(); // Задаем координатную сетку на квадрате
    QPainter painter;

    painter.begin(device); // Задаем девайс
    painter.fillRect(rect, Qt::red); // Разукрашиваем
    _scene->redraw(painter); // применяем к сцене

    painter.end();

    _backingStore->endPaint();
    _backingStore->flush(rect);
}
