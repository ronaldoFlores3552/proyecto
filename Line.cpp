//
// Created by HP on 12/11/2022.
//

#include "Line.h"

Line::Line(int &x1, int &y1, int &x2, int &y2, string s) : figure(s) {
    p1 = new Point(x1, y1);
    p2 = new Point(x2, y2);
    cord.push_back(p1);cord.push_back(p2);
}
void Line::imprimirDatos() {
    cout << "P.inicial (" << p1->GetX() + 1 << " " << p1->GetY() + 1 << ") ";
    cout << "P.final (" << p2->GetX() + 1 << " " << p2->GetY() + 1 << ")\n";
}
Line::~Line() {
    delete p1;
    delete p2;
    cout << "Linea destruida" << endl;
}
string Line::NombreFigura() {
    return "Line";
}