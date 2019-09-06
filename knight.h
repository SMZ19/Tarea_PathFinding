//
// Created by smz on 6/9/19.
//

#ifndef PATHFINDING_KNIGHT_H
#define PATHFINDING_KNIGHT_H


#pragma once

#include <QWidget>
#include <QKeyEvent>

class knight : public QWidget {

public:
    knight(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);


private:
    QImage knightImg;
    QImage crusaderImg;
    QImage shieldImg;


    static const int B_WIDTH = 800;
    static const int B_HEIGHT = 800;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 29;
    static const int DELAY = 140;

    int timerId;
    int dots;
    int crusaderImg_x;
    int crusaderImg_y;
    int shieldImg_x;
    int shieldImg_y;
    int x;
    int y;

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    void loadImages();
    void initGame();
    void locateCrusader();
    void locateShield();
    void checkPositions();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);
};



#endif //PATHFINDING_KNIGHT_H
