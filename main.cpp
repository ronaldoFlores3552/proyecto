#include "Tablero.h"


void imprimirTablero(vector<figure*>&figure,Tablero& ta){
    ta.vaciartablero();
    for(auto& f:figure){
        if(f->NombreFigura()=="Line"){
            ta.drawLine(f->GetPoints());
        }else if(f->NombreFigura()=="Rectangle"){
            ta.drawRectangle(f->GetPoints());
        }else if(f->NombreFigura()=="Triangle"){
            ta.drawTringle(f->GetPoints());
        }else if (f->NombreFigura()=="Circle"){
            ta.drawCircle(f->GetPoints(),f->GetR());
        }
    }
}
void Show(vector<figure*>&figure){
    int i=1;
    for(auto f:figure){
        cout<<i<<". ";
        cout<<f->NombreFigura()<<" ";
        f->imprimirDatos();
        i++;
    }

}

void Add(vector<figure*>&figuras,Tablero& ta){
    string f="";
    cout<<"Figure? Rectangle - Triangle - Line - Circle"<< endl;
    cin>>f;
    if(f=="Line"){
        int x1, y1, x2, y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        --x1;--y1;
        --x2;--y2;
        Line* l= new Line(x1, y1, x2, y2,"Line");
        figuras.push_back(l);
    }
    else if(f=="Rectangle"){
        int x1,y1,x2,y2;
        cin>>x1;cin>>y1;
        cin>>x2;cin>>y2;
        --x1;--y1;
        --x2;--y2;
        Rectangle* rec=new Rectangle(x1,y1,x2,y2,"Rectangle");
        figuras.push_back(rec);

    }
    else if(f=="Triangle"){
        int x1,y1,x2,y2,x3,y3;
        cin>>x1;cin>>y1;
        cin>>x2;cin>>y2;
        cin>>x3;cin>>y3;
        --x1;--y1;
        --x2;--y2;
        --x3;--y3;
        Triangle* tr=new Triangle(x1, y1, x2, y2, x3, y3, "Triangle");
        figuras.push_back(tr);
    }
    else if(f=="Circle"){
        int x,y,r;
        cin>>x;cin>>y;cin>>r;
        --x;--y;
        Circle* c=new Circle(r,x,y,"Circle");
        figuras.push_back(c);
    }

}

void Delete(vector<figure*>&figuras){
    int n=0;
    Show(figuras);
    cin>>n;
    delete figuras[n-1];
    figuras.erase(figuras.begin()+n-1);
}

void Resize(vector<figure*>&figuras){
    int n=0;
    Show(figuras);
    cin>>n;
    --n;
    if(figuras[n]->NombreFigura()=="Line"){
        int x1, y1, x2, y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        --x1;--y1;
        --x2;--y2;
        figuras[n]->GetPoints()[0]->SetPoint(x1,y1);
        figuras[n]->GetPoints()[1]->SetPoint(x2,y2);
    }else if(figuras[n]->NombreFigura()=="Rectangle"){
        int x1,y1,x2,y2;
        cin>>x1;cin>>y1;
        cin>>x2;cin>>y2;
        --x1;--y1;
        --x2;--y2;
        figuras[n]->GetPoints()[0]->SetPoint(x1,y1);
        figuras[n]->GetPoints()[1]->SetPoint(x2,y2);
    }else if(figuras[n]->NombreFigura()=="Triangle"){
        int x1,y1,x2,y2,x3,y3;
        cin>>x1;cin>>y1;
        cin>>x2;cin>>y2;
        cin>>x3;cin>>y3;
        --x1;--y1;
        --x2;--y2;
        --x3;--y3;
        figuras[n]->GetPoints()[0]->SetPoint(x1,y1);
        figuras[n]->GetPoints()[1]->SetPoint(x2,y2);
        figuras[n]->GetPoints()[2]->SetPoint(x3,y3);
    }else{
        int x,y,r;
        cin>>x;cin>>y;cin>>r;
        figuras[n]->GetPoints()[0]->SetPoint(x,y);
        figuras[n]->SetR(r);
    }
}

void Rotar90Horario(vector<Point*>puntos,string nombre){
    if(nombre=="Line"){
        if(puntos[0]->GetX()==puntos[1]->GetX()){
            int calcular= abs(puntos[0]->GetY()-puntos[1]->GetY())/2;
            int newx1=puntos[0]->GetX()-calcular;
            int newx2=puntos[1]->GetX()+calcular;
            if(puntos[0]->GetY()<puntos[1]->GetY()){
                int newy1=puntos[0]->GetY()+calcular;
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy1);
            }else{
                int newy1=puntos[1]->GetY()+calcular;
                puntos[0]->SetPoint(newx2,newy1);
                puntos[1]->SetPoint(newx1,newy1);
            }
        }
        else if(puntos[0]->GetY()==puntos[1]->GetY()){
            int calcular= abs(puntos[0]->GetX()-puntos[1]->GetX())/2;
            int newy2=puntos[1]->GetY()-calcular;
            int newy1=puntos[0]->GetY()+calcular;
            if(puntos[0]->GetX()<puntos[1]->GetX()){
                int newx1=puntos[0]->GetX()+calcular;
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx1,newy2);
            }else{
                int newx1=puntos[1]->GetX()+calcular;
                puntos[0]->SetPoint(newx1,newy2);
                puntos[1]->SetPoint(newx1,newy1);
            }
        }
        else{
            if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY() ||
                puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY() ){
                int newx1=puntos[0]->GetX();
                int newy1=puntos[1]->GetY();
                int newx2=puntos[1]->GetX();
                int newy2=puntos[0]->GetY();
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }else{
                int newx1=puntos[1]->GetX();
                int newy1=puntos[0]->GetY();
                int newx2=puntos[0]->GetX();
                int newy2=puntos[1]->GetY();
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }
    }


    else if(nombre=="Rectangle"){
        if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[0]->GetX()+1;
            int newy1=puntos[1]->GetY()+1;
            int newx2=puntos[1]->GetX()-1;
            int newy2=puntos[0]->GetY()-1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }else if(puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY()){
            int newx1=puntos[0]->GetX()-1;
            int newy1=puntos[1]->GetY()-1;
            int newx2=puntos[1]->GetX()+1;
            int newy2=puntos[0]->GetY()+1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }
        else if(puntos[0]->GetX()>puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[1]->GetX()-1;
            int newy1=puntos[0]->GetY()+1;
            int newx2=puntos[0]->GetX()+1;
            int newy2=puntos[1]->GetY()-1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }else{
            int newx1=puntos[1]->GetX()+1;
            int newy1=puntos[0]->GetY()-1;
            int newx2=puntos[0]->GetX()-1;
            int newy2=puntos[1]->GetY()+1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }
    }


}
void Rotar90AntiHorario(vector<Point*>puntos,string nombre){
    if(nombre=="Line"){
        if(puntos[0]->GetX()==puntos[1]->GetX()){
            int calcular= abs(puntos[0]->GetY()-puntos[1]->GetY())/2;
            int newx1=puntos[0]->GetX()-calcular;
            int newx2=puntos[1]->GetX()+calcular;
            if(puntos[0]->GetY()<puntos[1]->GetY()){
                int newy1=puntos[0]->GetY()+calcular;
                puntos[0]->SetPoint(newx2,newy1);
                puntos[1]->SetPoint(newx1,newy1);
            }else{
                int newy1=puntos[1]->GetY()+calcular;
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy1);
            }
        }
        else if(puntos[0]->GetY()==puntos[1]->GetY()){
            int calcular= abs(puntos[0]->GetX()-puntos[1]->GetX())/2;
            int newy2=puntos[1]->GetY()-calcular;
            int newy1=puntos[0]->GetY()+calcular;
            if(puntos[0]->GetX()<puntos[1]->GetX()){
                int newx1=puntos[0]->GetX()+calcular;
                puntos[0]->SetPoint(newx1,newy2);
                puntos[1]->SetPoint(newx1,newy1);
            }else{
                int newx1=puntos[1]->GetX()+calcular;
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx1,newy2);
            }
        }
        else{
            if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY() ||
               puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY() ){
                int newx1=puntos[1]->GetX();
                int newy1=puntos[0]->GetY();
                int newx2=puntos[0]->GetX();
                int newy2=puntos[1]->GetY();
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }else{
                int newx1=puntos[0]->GetX();
                int newy1=puntos[1]->GetY();
                int newx2=puntos[1]->GetX();
                int newy2=puntos[0]->GetY();
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }
    }

    else if(nombre=="Rectangle"){
        if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[1]->GetX()-1;
            int newy1=puntos[0]->GetY()-1;
            int newx2=puntos[0]->GetX()+1;
            int newy2=puntos[1]->GetY()+1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }else if(puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY()){
            int newx1=puntos[1]->GetX()+1;
            int newy1=puntos[0]->GetY()+1;
            int newx2=puntos[0]->GetX()-1;
            int newy2=puntos[1]->GetY()-1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }
        else if(puntos[0]->GetX()>puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[0]->GetX()+1;
            int newy1=puntos[1]->GetY()-1;
            int newx2=puntos[1]->GetX()-1;
            int newy2=puntos[0]->GetY()+1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }else{
            int newx1=puntos[0]->GetX()-1;
            int newy1=puntos[1]->GetY()+1;
            int newx2=puntos[1]->GetX()+1;
            int newy2=puntos[0]->GetY()-1;
            puntos[0]->SetPoint(newx1,newy1);
            puntos[1]->SetPoint(newx2,newy2);
        }
    }

    else if(nombre=="Triangle"){
        if(puntos[0]->GetX()!=puntos[1]->GetX()&& puntos[0]->GetY()!=puntos[1]->GetY()){//punto 2 el del medio
            if(puntos[0]->GetY()!=puntos[2]->GetY()){
                int calculate= abs(puntos[0]->GetY()-puntos[2]->GetY());
                int newy=puntos[2]->GetY();
                int newx=0;
                if(puntos[0]->GetY()<puntos[2]->GetY()){
                    newx=puntos[2]->GetX()+calculate;
                }else {
                    newx=puntos[2]->GetX()-calculate;
                }
                puntos[0]->SetPoint(newx,newy);
            }else{
                int calculate= abs(puntos[0]->GetX()-puntos[2]->GetX());
                int newx=puntos[2]->GetX();
                int newy=0;
                if(puntos[0]->GetX()>puntos[2]->GetX()){
                    newy=puntos[2]->GetY()+calculate;
                }else {
                    newy=puntos[2]->GetY()-calculate;
                }
                puntos[0]->SetPoint(newx,newy);
            }
            if(puntos[1]->GetY()!=puntos[2]->GetY()){
                int calculate= abs(puntos[1]->GetY()-puntos[2]->GetY());
                int newy=puntos[2]->GetY();
                int newx=0;
                if(puntos[1]->GetY()<puntos[2]->GetY()){
                    newx=puntos[2]->GetX()+calculate;
                }else {
                    newx=puntos[2]->GetX()-calculate;
                }
                puntos[1]->SetPoint(newx,newy);
            }else{
                int calculate= abs(puntos[1]->GetX()-puntos[2]->GetX());
                int newx=puntos[2]->GetX();
                int newy=0;
                if(puntos[1]->GetX()>puntos[2]->GetX()){
                    newy=puntos[2]->GetY()+calculate;
                }else {
                    newy=puntos[2]->GetY()-calculate;
                }
                puntos[1]->SetPoint(newx,newy);
            }
        }
        else if(puntos[0]->GetX()!=puntos[2]->GetX()&& puntos[0]->GetY()&& puntos[2]->GetY()){// punto 1
            if(puntos[0]->GetY()!=puntos[1]->GetY()){
                int calculate= abs(puntos[0]->GetY()-puntos[1]->GetY());
                int newy=puntos[1]->GetY();
                int newx=0;
                if(puntos[0]->GetY()<puntos[1]->GetY()){
                    newx=puntos[1]->GetX()+calculate;
                }else {
                    newx=puntos[1]->GetX()-calculate;
                }
                puntos[0]->SetPoint(newx,newy);
            }else{
                int calculate= abs(puntos[0]->GetX()-puntos[1]->GetX());
                int newx=puntos[1]->GetX();
                int newy=0;
                if(puntos[0]->GetX()>puntos[1]->GetX()){
                    newy=puntos[1]->GetY()+calculate;
                }else {
                    newy=puntos[1]->GetY()-calculate;
                }
                puntos[0]->SetPoint(newx,newy);
            }
            if(puntos[2]->GetY()!=puntos[1]->GetY()){
                int calculate= abs(puntos[2]->GetY()-puntos[1]->GetY());
                int newy=puntos[1]->GetY();
                int newx=0;
                if(puntos[2]->GetY()<puntos[1]->GetY()){
                    newx=puntos[1]->GetX()+calculate;
                }else {
                    newx=puntos[1]->GetX()-calculate;
                }
                puntos[2]->SetPoint(newx,newy);
            }else{
                int calculate= abs(puntos[2]->GetX()-puntos[1]->GetX());
                int newx=puntos[1]->GetX();
                int newy=0;
                if(puntos[2]->GetX()>puntos[1]->GetX()){
                    newy=puntos[1]->GetY()+calculate;
                }else {
                    newy=puntos[1]->GetY()-calculate;
                }
                puntos[2]->SetPoint(newx,newy);
            }
        }
        else{// punto 0

        }
    }
}

void Rotate(vector<figure*>&figuras){
    int n=0;
    string rotar;
    Show(figuras);
    cin>>n;
    --n;
    cin>>rotar;
    if(rotar=="90"){
        Rotar90Horario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
    }else if (rotar=="-90"){
        Rotar90AntiHorario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
    }
}
void menu(){
    string opcion;
    vector<figure*>figuras;
    Tablero ta;

    while(opcion!="stop"){
        ta.imprimir();
        cout<<" Operations: Shows, Add, Delete, Rotate or Resize"<<endl;
        cin>>opcion;
        if(opcion=="Show"){
            Show(figuras);
        }else if(opcion=="Add"){
            if(figuras.size()<limit)
                Add(figuras,ta);
            else{
                cout<<"Limite excedido"<<endl;
            }
        }else if(opcion=="Delete"){
            Delete(figuras);
        }else if(opcion=="Rotate"){
            Rotate(figuras);
        }else if(opcion=="Resize"){
            Resize(figuras);
        }
        imprimirTablero(figuras,ta);
    }
    system("cls");
}

int main() {
    menu();
    //srand(time(0));
}