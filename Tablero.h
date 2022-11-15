//
// Created by HP on 12/11/2022.
//

#ifndef TAREA_TABLERO_H
#define TAREA_TABLERO_H

#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <cmath>

const int limit=5;
const int tamanhiotablero=20;
const char Cdraw = '*';
const char blank= ' ';

class Tablero{
    char** tablero=nullptr;
public:
    Tablero();

    void drawLine(vector<Point *> puntos);
    void drawCircle(vector<Point *> puntos,int radio);
    void drawRectangle(vector<Point *> puntos);
    void drawTringle(vector<Point *> puntos);
    void imprimir();
    void vaciartablero();

    //linea
    void compararcolumnas(Point* P1, Point* P2,char draw);
    void compararfilas(Point* P1, Point* P2,char draw);
    void compararDiagonal(Point* P1, Point* P2,char draw);

};



#endif //TAREA_TABLERO_H
