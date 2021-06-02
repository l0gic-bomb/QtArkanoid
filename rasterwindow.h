#ifndef RASTERWINDOW_H
#define RASTERWINDOW_H

#include <QWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QExposeEvent>
#include <QBackingStore>
#include <QElapsedTimer>
#include <QDialog>

#include <memory>

#include "gamescene.h"

//! Класс отрисовки изображений
class RasterWindow : public QWindow
{
    Q_OBJECT
public:
    //! Конструктор
    explicit RasterWindow(QWindow* parent = nullptr);
    //! Деструктор
    ~RasterWindow();

protected:
    //! Обработчик событий
    bool event(QEvent* event) override;
    //! Вызывается при изменении размера окна
    void resizeEvent(QResizeEvent* resizeEvent) override;
    //! Вызывается при показе окна
    void exposeEvent(QExposeEvent *) override;
    //! Вызывается при нажатии кнопок
    void keyPressEvent (QKeyEvent* event) override;

private:
    //! Добавляет в очередь событий, событие обновление экрана
    void renderLater();
    //! Запуск буфера, очищение буфера
    void renderNow();
    //! Обновление состояния сцены
    void updateScene();
    //! рисуем сцену
    void renderScene();

private:
    QBackingStore* _backingStore;

    std::unique_ptr<GameScene> _scene;
    QElapsedTimer _updateTimer;

    bool _gameFinish;
    bool _gameWon;

};

#endif // RASTERWINDOW_H
