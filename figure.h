//
// Created by HP on 12/11/2022.
//

#ifndef TAREA_FIGURE_H
#define TAREA_FIGURE_H

#include "Point.h"


class figure{
protected:
    vector<Point*>cord;
    string nombre;
    int radio;
public:
    figure(string n);
    virtual void imprimirDatos()=0;
    virtual void SetR(int &r){this->radio=r;}
    virtual int GetR(){return radio;}
    virtual vector<Point*> GetPoints(){return cord;}
    virtual string NombreFigura()=0;
    virtual ~figure();
};



#endif //TAREA_FIGURE_H
