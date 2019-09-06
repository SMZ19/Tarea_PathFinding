//
// Created by smz on 6/9/19.
//

#include <QApplication>

#include "knight.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    knight game;

    game.setWindowTitle("Knight vs Crusader");
    game.show();

    return app.exec();
}


