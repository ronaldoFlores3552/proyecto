//
// Created by HP on 12/11/2022.
//

#include "circle.h"

Circle::Circle(int& r,int&x,int&y,string nombre): figure(nombre) {
    p=new Point(x,y);
    radio=r;
    cord.push_back(p);
}

string Circle::NombreFigura() {
    return nombre;
}


void Circle::imprimirDatos() {
    cout<<"P. ("<<p->GetX()+1<<" "<<p->GetY()+1<<") radio: "<<radio<<endl;
}

Circle::~Circle() {
    delete p;
    cout<<"Circulo destruido"<<endl;
}
