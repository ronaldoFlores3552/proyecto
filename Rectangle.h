//
// Created by HP on 12/11/2022.
//

#ifndef TAREA_RECTANGLE_H
#define TAREA_RECTANGLE_H

#include "figure.h"

class Rectangle: public figure{
    Point* p1;
    Point* p2;
public:
    Rectangle(int&x1,int&y1,int&x2,int&y2,string nombre);
    virtual string NombreFigura();
    virtual void imprimirDatos();

    virtual ~Rectangle();
};


#endif //TAREA_RECTANGLE_H
