//
// Created by HP on 12/11/2022.
//

#ifndef TAREA_POINT_H
#define TAREA_POINT_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Point{
protected:
    int X;
    int Y;
public:
    Point();
    Point(int _x, int _y);

    void SetPoint(int& _x,int& _y);
    int GetX();
    int GetY();

    ~Point();
};

#endif //TAREA_POINT_H
