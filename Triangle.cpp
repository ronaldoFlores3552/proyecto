//
// Created by HP on 13/11/2022.
//

#include "Triangle.h"

Triangle::Triangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, string nombre): figure(nombre) {
    p1=new Point(x1,y1);
    p2=new Point(x2,y2);
    p3=new Point(x3,y3);
    cord.push_back(p1);cord.push_back(p2);cord.push_back(p3);
}

string Triangle::NombreFigura() {return nombre;}

void Triangle::imprimirDatos() {
    cout<<"P. 1 ("<<p1->GetX()+1<<" "<<p1->GetY()+1<<") ";
    cout<<"P. 2 ("<<p2->GetX()+1<<" "<<p2->GetY()+1<<") ";
    cout<<"P. 3 ("<<p3->GetX()+1<<" "<<p3->GetY()+1<<")\n";
}

Triangle::~Triangle() {
    delete p1;
    delete p2;
    delete p3;
    cout<<"Triangulo destruido"<<endl;
}

/*Point *Triangle::punto1() {
    return p1;
}

Point *Triangle::punto2() {
    return p2;
}

Point *Triangle::punto3() {
    return p3;
}*/
