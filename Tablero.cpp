//
// Created by HP on 12/11/2022.
//

#include "Tablero.h"

Tablero::Tablero() {
    tablero = new char *[tamanhiotablero];
    for (int i = 0; i < tamanhiotablero; i++) {
        tablero[i] = new char[tamanhiotablero];
    }
    for (int i = 0; i < tamanhiotablero; i++) {
        for (int j = 0; j < tamanhiotablero; j++) {
            tablero[i][j] = blank;
        }
    }
}

void Tablero::compararfilas(Point *P1, Point *P2,char draw) {
    if (P1->GetX() < P2->GetX()) {
        for (int i = P1->GetX(); i <= P2->GetX(); ++i) {
            tablero[i][P1->GetY()] = draw;
        }
    } else {
        for (int i = P2->GetX(); i <= P1->GetX(); ++i) {
            tablero[i][P2->GetY()] = draw;
        }
    }
}
void Tablero::compararcolumnas(Point *P1, Point *P2,char draw) {
    if (P1->GetY() < P2->GetY()) {
        for (int i = P1->GetY(); i <= P2->GetY(); i++)
            tablero[P1->GetX()][i] = draw;
    } else {
        for (int i = P2->GetY(); i <= P1->GetY(); i++)
            tablero[P2->GetX()][i] = draw;
    }
}
void Tablero::compararDiagonal(Point *P1, Point *P2,char draw) {
    int cont=0;
    if (P1->GetX() < P2->GetX() &&
        P1->GetY() < P2->GetY()) {//p1x < p2x && p1y<p2y
        for (int i = P1->GetX(); i <= P2->GetX(); i++,cont++) {
            tablero[i][P1->GetY()+ cont] = draw;
        }
    } else if (P2->GetX() < P1->GetX() && P2->GetY() < P1->GetY()) {
        for (int i = P2->GetX(); i <= P1->GetX(); i++,cont++) {
            tablero[i][P2->GetY() + cont] = draw;
        }
    } else if (P1->GetX() > P2->GetX() && P1->GetY() < P2->GetY()) {

        for (int i = P2->GetX(); i <= P1->GetX(); i++, ++cont) {
            tablero[i][P2->GetY() - cont] = draw;
        }
    } else if (P2->GetX() > P1->GetX() && P2->GetY() < P1->GetY()) {
        for (int i = P1->GetX(); i <= P2->GetX(); i++, ++cont) {
            tablero[i][P1->GetY() - cont] = draw;
        }
    }
}

void Tablero::drawLine(vector<Point *> puntos) {
    //misma fila
    if (puntos[0]->GetX() == puntos[1]->GetX()) {
        compararcolumnas(puntos[0], puntos[1],Cdraw);
    }
        //misma columna
    else if (puntos[0]->GetY() == puntos[1]->GetY()) {
        compararfilas(puntos[0], puntos[1],Cdraw);
    }
        //diagonal
    else {
        compararDiagonal(puntos[0],puntos[1],Cdraw);
    }
}



void Tablero::drawCircle(vector<Point *> puntos, int radio) {

    int pun =radio / 2 ;
    tablero[puntos[0]->GetX() -radio][puntos[0]->GetY()] = Cdraw;
    tablero[puntos[0]->GetX() +radio][puntos[0]->GetY()] = Cdraw;
    tablero[puntos[0]->GetX()][puntos[0]->GetY() -radio] = Cdraw;
    tablero[puntos[0]->GetX()][puntos[0]->GetY() +radio] = Cdraw;
    for (int i = 1; i <= pun; i++) {
        tablero[puntos[0]->GetX() -radio][puntos[0]->GetY() + i] = Cdraw;
        tablero[puntos[0]->GetX() -radio][puntos[0]->GetY() - i] = Cdraw;
        tablero[puntos[0]->GetX() +radio][puntos[0]->GetY() + i] = Cdraw;
        tablero[puntos[0]->GetX() +radio][puntos[0]->GetY() - i] = Cdraw;
        tablero[puntos[0]->GetX() + i][puntos[0]->GetY() -radio] = Cdraw;
        tablero[puntos[0]->GetX() - i][puntos[0]->GetY() -radio] = Cdraw;
        tablero[puntos[0]->GetX() + i][puntos[0]->GetY() +radio] = Cdraw;
        tablero[puntos[0]->GetX() - i][puntos[0]->GetY() +radio] = Cdraw;
    }
    tablero[puntos[0]->GetX() -radio + 1][puntos[0]->GetY() +radio - 1] = Cdraw;
    tablero[puntos[0]->GetX() -radio + 1][puntos[0]->GetY() -radio + 1] = Cdraw;
    tablero[puntos[0]->GetX() +radio - 1][puntos[0]->GetY() +radio - 1] = Cdraw;
    tablero[puntos[0]->GetX() +radio - 1][puntos[0]->GetY() -radio + 1] = Cdraw;
}


void Tablero::drawRectangle(vector<Point *> puntos) {
    if (puntos[0]->GetX() < puntos[1]->GetX() && puntos[0]->GetY() < puntos[1]->GetY()) {
        for (int i = puntos[0]->GetX(); i <= puntos[1]->GetX(); i++) {
            tablero[i][puntos[0]->GetY()] = Cdraw;
            tablero[i][puntos[1]->GetY()] = Cdraw;
        }
        for (int i = puntos[0]->GetY(); i <= puntos[1]->GetY(); ++i) {
            tablero[puntos[0]->GetX()][i] = Cdraw;
            tablero[puntos[1]->GetX()][i] = Cdraw;
        }
    } else if (puntos[1]->GetX() < puntos[0]->GetX() && puntos[1]->GetY() < puntos[0]->GetY()) {
        for (int i = puntos[1]->GetX(); i <= puntos[0]->GetX(); i++) {
            tablero[i][puntos[1]->GetY()] = Cdraw;
            tablero[i][puntos[0]->GetY()] = Cdraw;
        }
        for (int i = puntos[1]->GetY(); i <= puntos[0]->GetY(); ++i) {
            tablero[puntos[1]->GetX()][i] = Cdraw;
            tablero[puntos[0]->GetX()][i] = Cdraw;
        }
    } else if (puntos[0]->GetX() > puntos[1]->GetX() && puntos[0]->GetY() < puntos[1]->GetY()) {
        for (int i = puntos[1]->GetX(); i <= puntos[0]->GetX(); i++) {
            tablero[i][puntos[1]->GetY()] = Cdraw;
            tablero[i][puntos[0]->GetY()] = Cdraw;
        }
        for (int i = puntos[0]->GetY(); i <= puntos[1]->GetY(); ++i) {
            tablero[puntos[0]->GetX()][i] = Cdraw;
            tablero[puntos[1]->GetX()][i] = Cdraw;
        }
    } else if (puntos[1]->GetX() > puntos[0]->GetX() && puntos[1]->GetY() < puntos[0]->GetY()) {
        for (int i = puntos[0]->GetX(); i <= puntos[1]->GetX(); i++) {
            tablero[i][puntos[0]->GetY()] = Cdraw;
            tablero[i][puntos[1]->GetY()] = Cdraw;
        }
        for (int i = puntos[1]->GetY(); i <= puntos[0]->GetY(); ++i) {
            tablero[puntos[1]->GetX()][i] = Cdraw;
            tablero[puntos[0]->GetX()][i] = Cdraw;
        }
    }
}


void Tablero::drawTringle(vector<Point *> puntos) {
    //misma fila
    if (puntos[0]->GetX() == puntos[1]->GetX()) {
        compararcolumnas(puntos[0], puntos[1],Cdraw);
    } else if (puntos[0]->GetX() == puntos[2]->GetX()) {
        compararcolumnas(puntos[0], puntos[2],Cdraw);
    } else if (puntos[1]->GetX() == puntos[2]->GetX()) {
        compararcolumnas(puntos[1], puntos[2],Cdraw);
    }
    //misma columna
    if (puntos[0]->GetY() == puntos[1]->GetY()) {
        compararfilas(puntos[0], puntos[1],Cdraw);
    } else if (puntos[0]->GetY() == puntos[2]->GetY()) {
        compararfilas(puntos[0], puntos[2],Cdraw);
    } else if (puntos[1]->GetY() == puntos[2]->GetY()) {
        compararfilas(puntos[1], puntos[2],Cdraw);
    }
    //diagonal
    if(puntos[0]->GetX() != puntos[1]->GetX() && puntos[0]->GetY() != puntos[1]->GetY()){
        compararDiagonal(puntos[0],puntos[1],Cdraw);
    }else if(puntos[0]->GetX() != puntos[2]->GetX() && puntos[0]->GetY() != puntos[2]->GetY()){
        compararDiagonal(puntos[0],puntos[2],Cdraw);
    }else if(puntos[1]->GetX() != puntos[2]->GetX() && puntos[1]->GetY() != puntos[2]->GetY()){
        compararDiagonal(puntos[1],puntos[2],Cdraw);
    }
}

void Tablero::imprimir() {
    for (int i = 0; i < tamanhiotablero; i++) {
        for (int j = 0; j < tamanhiotablero; j++)
            cout << setw(1) << this->tablero[i][j] << " ";
        cout << endl;
    }
}
void Tablero::vaciartablero() {
    for (int i = 0; i < tamanhiotablero; i++) {
        for (int j = 0; j < tamanhiotablero; j++)
             this->tablero[i][j]=blank;
    }
}




