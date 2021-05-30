#include <QApplication>

#include "pooltablescene.h"

namespace  {
//! ball
constexpr float BALL_SPEED_X = 150;
constexpr float BALL_SPEED_Y = 150;
constexpr float BALL_SIZE = 30;

//! platform
constexpr float PLATFORM_SPEED_X = 10;
constexpr float PLATFORM_SPEED_Y = 0;

constexpr float PLATFORM_POS_X = 400;
constexpr float PLATFORM_POS_Y = 750;

constexpr float PLATFORM_WIDTH = 150;
constexpr float PLATFORM_HEIGHT = 50;
}

PoolTableScene::PoolTableScene(const RectF &bounds)
    : _ballPosition(400, 400),
      _ballSpeed(-BALL_SPEED_X, -BALL_SPEED_Y),
      _ballSize(BALL_SIZE, BALL_SIZE),
      _bounds(bounds),
      _platform({PLATFORM_POS_X, PLATFORM_POS_Y}, {PLATFORM_WIDTH, PLATFORM_HEIGHT}, {PLATFORM_SPEED_X, PLATFORM_SPEED_Y})
{
}

void PoolTableScene::updateCurrentPosBall(const float &x, const float &y)
{
    _ballPosition._x += x;
    _ballPosition._y += y;
}

void PoolTableScene::ballHitPlatform(const float &deltaSeconds)
{
    updateCurrentPosBall(_ballSpeed._x * deltaSeconds,  _ballSpeed._y * deltaSeconds);

    int tmpRightSidePlatfrom = _platform.getXPos() + _platform.getSize().width() - _ballSize._x;
    int tmpLeftSidePlatfrom  = _platform.getXPos();

    // Hit platform
    if (_ballPosition._y > _platform.getYPos() - _ballSize._y
               && _ballPosition._x < tmpRightSidePlatfrom && _ballPosition._x > tmpLeftSidePlatfrom) {
        _ballPosition._y = _platform.getYPos() - _ballSize._y;
        _ballSpeed._y = -_ballSpeed._y;
    }
}

void PoolTableScene::ballHitWall(const float &deltaSeconds)
{
    updateCurrentPosBall(_ballSpeed._x * deltaSeconds,  _ballSpeed._y * deltaSeconds);

    // Hit wall
    if (_ballPosition._x < _bounds.leftEdge())
    {
        _ballPosition._x = _bounds.leftEdge();
       _ballSpeed._x = -_ballSpeed._x;
    }
    else if (_ballPosition._x > _bounds.rightEdge() - _ballSize._x)
    {
        _ballPosition._x = _bounds.rightEdge() - _ballSize._x;
        _ballSpeed._x = -_ballSpeed._x;
    } else if (_ballPosition._y > _bounds.bottomEdge() - _ballSize._y) {
        _ballPosition._y = _bounds.bottomEdge() - _ballSize._y;
        _ballSpeed._y = -_ballSpeed._y;
    } else if (_ballPosition._y < _bounds.topEdge()) {
        // lose
        _ballPosition._y = _bounds.topEdge();
        _ballSpeed._y = -_ballSpeed._y;
    }
}

void PoolTableScene::redraw(QPainter &painter)
{
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QBrush(QColor(0x00, 0x00, 0x00)));
    painter.drawEllipse(QRectF(_ballPosition._x, _ballPosition._y , BALL_SIZE, BALL_SIZE));

    painter.setBrush(QBrush(QColor(0xff, 0xab, 0x00)));
    painter.drawRect(QRectF(_platform.getXPos(), _platform.getYPos(), _platform.getSize().width(), _platform.getSize().height()));
}

void PoolTableScene::movePlatform(const int &x)
{
    if ((_platform.getXPos() < _bounds.leftEdge()) && x < 0)
        return;
    else if ((_platform.getXPos() > _bounds.rightEdge() - _platform.getSize().width()) && x > 0)
        return;

    _platform.movePlatform(x);
}


