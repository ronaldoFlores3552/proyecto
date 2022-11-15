//
// Created by HP on 12/11/2022.
//

#ifndef TAREA_LINE_H
#define TAREA_LINE_H

#include "figure.h"

class Line: public figure{
    Point* p1;
    Point* p2;
public:
    Line(int&x1,int&y1,int&x2,int&y2,string s);
    virtual string NombreFigura();
    virtual void imprimirDatos();
    virtual ~Line();
};

#endif //TAREA_LINE_H
