//
// Created by danium on 12/9/19.
//

#include "Bresenham.h"
#include <iostream>

Bresenham::Bresenham(int x0, int y0, int x1, int y1) : x0(x0), x1(x1), y0(y0), y1(y1) {
    drawLine(x0,y1,x1,y1);
}

void Bresenham::drawLine(int x0, int y0, int x1, int y1) {
    int dx, dy, p, x, y;

    dx=x1-x0;
    dy=y1-y0;

    x=x0;
    y=y0;

    p=2*dy-dx;

    while(x<x1)
    {
        if(p>=0)
        {
            std::cout<<"("<<x<<","<<y<<")"<<std::endl;
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            std::cout<<"("<<x<<","<<y<<")"<<std::endl;
            p=p+2*dy;
        }
        x=x+1;
    }

}


