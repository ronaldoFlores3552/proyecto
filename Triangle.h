//
// Created by HP on 13/11/2022.
//

#ifndef TAREA_TRIANGLE_H
#define TAREA_TRIANGLE_H

#include "figure.h"

class Triangle: public figure{
    Point* p1;
    Point* p2;
    Point* p3;
public:
    Triangle(int&x1x, int&y1, int&x2, int&y2, int&x3, int&y3, string nombre);
    virtual void imprimirDatos();
    virtual ~Triangle();
    virtual string NombreFigura();
};


#endif //TAREA_TRIANGLE_H
