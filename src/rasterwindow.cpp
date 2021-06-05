
#include <QApplication>
#include "rasterwindow.h"

constexpr unsigned WINDOW_WIDTH  = 400;
constexpr unsigned WINDOW_HEIGHT = 400;

RasterWindow::RasterWindow(QWindow* parent)
    : QWindow(parent),
      _backingStore(new QBackingStore(this)),
      _scene(std::make_unique<GameScene>(RectF{0, 0, float(WINDOW_WIDTH ), float(WINDOW_HEIGHT)}))
{
    setMinimumSize(QSize(400, 400));
    _updateTimer.start();
}

RasterWindow::~RasterWindow()
{
    delete _backingStore;
    _scene->close();
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
        close();
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
    if (!isExposed())
        return;

    updateScene();
    renderScene();

    renderLater();
}

void RasterWindow::updateScene()
{
    const float elapsedSeconds = float(_updateTimer.elapsed()) / 350.f;

    if (elapsedSeconds > 0) {
        _updateTimer.restart();
        _scene->ballHitLet(elapsedSeconds);
    }
}

void RasterWindow::renderScene()
{
    QRect rect(0, 0, width(), height());

    _backingStore->beginPaint(rect);
    QPaintDevice *device = _backingStore->paintDevice();
    QPainter painter;

    painter.begin(device);
    painter.fillRect(rect, QColor(0x00, 0xbf, 0xff));
    _scene->redraw(painter);

    painter.end();

    _backingStore->endPaint();
    _backingStore->flush(rect);
}
