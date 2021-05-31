#include <QApplication>
#include "gamescene.h"

const QString YOU_WIN   = "Вы выиграли!";
const QString YOU_LOSE  = "Вы проиграли!";

namespace  {

constexpr float MIDDLE = 400;

//! ball
constexpr float BALL_SPEED_X = 10;
constexpr float BALL_SPEED_Y = -50;
constexpr float BALL_SIZE = 10;

//! platform
constexpr float PLATFORM_SPEED_X = 10;
constexpr float PLATFORM_SPEED_Y = 0;

constexpr float PLATFORM_POS_X = 200;
constexpr float PLATFORM_POS_Y = 390;

constexpr float PLATFORM_WIDTH = 75;
constexpr float PLATFORM_HEIGHT = 10;
}

GameScene::GameScene(const RectF& bounds)
    : _ballPosition(200, 200),
      _ballSpeed(BALL_SPEED_X, -BALL_SPEED_Y),
      _ballSize(BALL_SIZE, BALL_SIZE),
      _boundsScene(bounds)
{
    _gameWin  = false;
    _gameLose = false;

    _platform = new Platform({PLATFORM_POS_X, PLATFORM_POS_Y}, {PLATFORM_WIDTH, PLATFORM_HEIGHT}, {PLATFORM_SPEED_X, PLATFORM_SPEED_Y});

    int k = 0;
    for (int i=0; i<5; i++) {
      for (int j=0; j<6; j++) {
        bricks[k] = new Bricks(j * 50 + 40, i * 30 + 40);
        k++;
      }
    }
}

GameScene::~GameScene()
{
    delete _platform;
    for (int i = 0; i < NUMBER_BRICKS; ++i)
        delete bricks[i];
}

void GameScene::updateCurrentPosBall(const float &x, const float &y)
{
    _ballPosition.setX(_ballPosition.x() + x);
    _ballPosition.setY(_ballPosition.y() + y);
}

void GameScene::ballHitLet(const float &deltaSeconds)
{
    updateCurrentPosBall(_ballSpeed.x() * deltaSeconds,  _ballSpeed.y() * deltaSeconds);

    this->ballHitBricks();
    this->ballHitWall();
    this->ballHitPlatform();
}

void GameScene::ballHitWall()
{
    if (_ballPosition.x() < _boundsScene.leftEdge())
    {
        _ballPosition.setX(_boundsScene.leftEdge());
       _ballSpeed.setX(-_ballSpeed.x());
    }
    else if (_ballPosition.x() > _boundsScene.rightEdge() - _ballSize.x())
    {
        _ballPosition.setX(_boundsScene.rightEdge() - _ballSize.x());
        _ballSpeed.setX(-_ballSpeed.x());
    } else if (_ballPosition.y() > _boundsScene.bottomEdge())
        _gameLose = true;
    else if (_ballPosition.y() < _boundsScene.topEdge()) {
        _ballPosition.setY(_boundsScene.topEdge());
        _ballSpeed.setY(-_ballSpeed.y());
    }
}

void GameScene::ballHitPlatform()
{
    int tmpRightSidePlatfrom = _platform->getXPos() + _platform->getSize().width() - _ballSize.x();
    int tmpLeftSidePlatfrom  = _platform->getXPos();

    if (_ballPosition.y() > _platform->getYPos() - _ballSize.y()
               && _ballPosition.x() < tmpRightSidePlatfrom && _ballPosition.x() > tmpLeftSidePlatfrom) {
        _ballPosition.setY(_platform->getYPos() - _ballSize.y());
        _ballSpeed.setY(-_ballSpeed.y());
    }
}

void GameScene::ballHitBricks()
{
    for (int i = 0; i < NUMBER_BRICKS; ++i) {
        if (bricks[i]->getRect().contains(_ballPosition.x(), _ballPosition.y())) {
            bricks[i]->setDestroyes(true);
            _ballSpeed.setX(-_ballSpeed.x());
            _ballSpeed.setY(-_ballSpeed.y());
        }
    }
}

void GameScene::redraw(QPainter &painter)
{
    if (_gameWin) {
        finishGame(&painter, YOU_WIN);
    } else if (_gameLose) {
        finishGame(&painter, YOU_LOSE);
    } else {
        painter.setRenderHint(QPainter::Antialiasing);

        // Мячик
        painter.setBrush(QBrush(QColor(0x00, 0x00, 0x00)));
        painter.drawEllipse(QRectF(_ballPosition.x(), _ballPosition.y() , BALL_SIZE, BALL_SIZE));

        // Плафторма
        painter.setBrush(QBrush(QColor(0xff, 0xff, 0xff)));
        painter.drawRect(QRectF(_platform->getXPos(), _platform->getYPos(), _platform->getSize().width(), _platform->getSize().height()));

        // Работа с кирпичами
        int k = 0;
        for (int i = 0; i < NUMBER_BRICKS; ++i) {
            if (!bricks[i]->isDestroyed()) {
                ++k;
                painter.drawRect(bricks[i]->getRect());
            } else if (k == NUMBER_BRICKS)
                _gameWin = true;
        }
    }
}

void GameScene::movePlatform(const int &x)
{
    if ((_platform->getXPos() < _boundsScene.leftEdge()) && x < 0)
        return;
    else if ((_platform->getXPos() > _boundsScene.rightEdge() - _platform->getSize().width()) && x > 0)
        return;

    _platform->movePlatform(x);
    int tmpVel = _ballPosition.y();
    int tmpPos = _platform->getYPos();
    if (_platform->getYPos() - _ballPosition.y() == _ballPosition.y())
        _ballSpeed.setY(_ballSpeed.y() + _platform->getYVeclocity());
}

void GameScene::finishGame(QPainter *painter, const QString &message)
{
    QFont font("Helvetica", 10, QFont::Bold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    painter->setFont(font);
    int h = MIDDLE;
    int w = MIDDLE;

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);
}
