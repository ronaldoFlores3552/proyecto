//
// Created by HP on 12/11/2022.
//

#include "Point.h"

Point::Point(){}
Point::Point(int _x, int _y) {
    this->X = _x;
    this->Y = _y;
}

void Point::SetPoint(int &_x, int &_y) {
    this->X = _x;
    this->Y = _y;
}

int Point::GetX() { return X; }

int Point::GetY() { return Y; }

Point::~Point(){cout<<"Punto destruido "<<endl;}
