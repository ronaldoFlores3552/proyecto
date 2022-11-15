//
// Created by HP on 12/11/2022.
//

#ifndef TAREA_CIRCLE_H
#define TAREA_CIRCLE_H

#include "figure.h"
class Circle: public figure{
    Point* p;
public:
    Circle(int& r,int&x,int&y,string nombre);
    virtual string NombreFigura();
    virtual void imprimirDatos();
    virtual ~Circle();
};


#endif //TAREA_CIRCLE_H
