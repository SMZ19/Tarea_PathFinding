//
// Created by smz on 6/9/19.
//

#include "knight.h"

#include <QPainter>
#include <QTime>


knight::knight(QWidget *parent) : QWidget(parent) {

    setStyleSheet("background-color:white;");
    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;

    resize(B_WIDTH, B_HEIGHT);
    loadImages();
    initGame();
}

void knight::loadImages() {

    knightImg.load("/home/smz/CLionProjects/pathfinding/Images/helmet.png");
    crusaderImg.load("/home/smz/CLionProjects/pathfinding/Images/crusader.png");
    shieldImg.load("/home/smz/CLionProjects/pathfinding/Images/shield.png");
}

void knight::initGame() {


    x = 300;
    y = 600;

    locateShield();
    locateCrusader();


    timerId = startTimer(DELAY);
}

void knight::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doDrawing();
}

void knight::doDrawing() {

    QPainter qp(this);

    if (inGame) {

        qp.drawImage(crusaderImg_x, crusaderImg_y, crusaderImg);
        qp.drawImage(shieldImg_x,shieldImg_y,shieldImg);
        qp.drawImage(x, y, knightImg);


    } else {

        gameOver(qp);
    }
}

void knight::gameOver(QPainter &qp) {

    QString message = "Game over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}

void knight::checkPositions() {

    if ((x == crusaderImg_x) && (y == crusaderImg_y)) {
        locateCrusader();
    }else if((x == shieldImg_x) && (y == shieldImg_y)){
        locateShield();
    }
}

void knight::move() {
    if(shieldImg_x > x){
        x += DOT_SIZE;

    }else {
        if(shieldImg_x == x){

        }else{
            x -= DOT_SIZE;
        }
    }
    y -= DOT_SIZE;

}

void knight::checkCollision() {

    if (y < 0) {
        x = 300;
        y = 600;
    }

}

void knight::locateCrusader() {

    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % RAND_POS;
    crusaderImg_x = (r * DOT_SIZE);

    r = qrand() % RAND_POS;
    crusaderImg_y = (r * DOT_SIZE+100);
}
void knight::locateShield() {

    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % RAND_POS;
    shieldImg_x = (r * DOT_SIZE);
    shieldImg_y=0;

}

void knight::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (inGame) {

        checkPositions();
        checkCollision();
        move();
    }

    repaint();
}
