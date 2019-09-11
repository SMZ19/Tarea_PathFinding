//
// Created by smz on 6/9/19.
//

#ifndef PATHFINDING_KNIGHT_H
#define PATHFINDING_KNIGHT_H


#pragma once

#include <QWidget>
#include <QKeyEvent>
#include "crusader.h"

class knight : public QWidget {

public:
    knight(QWidget *parent = 0);





protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void drawLines(QPainter *qp);

private:
    QRect crusaderRect;
    QImage knightImg;

    QImage shieldImg;

    crusader crusaderList[19];
    static const int filas = 15;
    static const int columnas = 15;
    int mapMatrix[columnas][filas];

    static const int B_WIDTH = 800;
    static const int B_HEIGHT = 800;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 50;
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

    int dimX =0;
    int dimY=0;
    int maxDivX  = 0;
    int maxDivY  = 0;
    int squareSize = 50;
    QRect knightRect;
    QRect shieldRect;
    void loadImages();
    void initGame();
    void locateCrusader();
    void locateShield();
    void checkPositions();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);
    void getDimensions(int , int);
    int generateRnd();
};



#endif //PATHFINDING_KNIGHT_H
