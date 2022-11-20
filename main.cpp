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
        cout<<"Ingresar fila y columna de punto inicial: ";
        cin >> x1;
        cin >> y1;
        cout<<"Ingresar fila y columna de punto final: ";
        cin >> x2;
        cin >> y2;
        --x1;--y1;
        --x2;--y2;
        bool cortafuego= x1<0||x1>tamanhiotablero||
                         y1<0||y1>tamanhiotablero||
                         x2<0||x2>tamanhiotablero||
                         y2<0||y2>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            Line* l= new Line(x1, y1, x2, y2,"Line");
            figuras.push_back(l);
        }
    }
    else if(f=="Rectangle"){
        int x1,y1,x2,y2;
        cout<<"Ingresar fila y columna de punto inicial: ";
        cin>>x1;cin>>y1;
        cout<<"Ingresar fila y columna de punto final: ";
        cin>>x2;cin>>y2;
        --x1;--y1;
        --x2;--y2;
        bool cortafuego= x1<0||x1>tamanhiotablero||
                         y1<0||y1>tamanhiotablero||
                         x2<0||x2>tamanhiotablero||
                         y2<0||y2>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            Rectangle* rec=new Rectangle(x1,y1,x2,y2,"Rectangle");
            figuras.push_back(rec);
        }

    }
    else if(f=="Triangle"){
        int x1,y1,x2,y2,x3,y3;
        cout<<"Ingresar fila y columna de punto 1: ";
        cin>>x1;cin>>y1;
        cout<<"Ingresar fila y columna de punto 2: ";
        cin>>x2;cin>>y2;
        cout<<"Ingresar fila y columna de punto 3: ";
        cin>>x3;cin>>y3;
        --x1;--y1;
        --x2;--y2;
        --x3;--y3;
        bool cortafuego= x1<0||x1>tamanhiotablero||
                         y1<0||y1>tamanhiotablero||
                         x2<0||x2>tamanhiotablero||
                         y2<0||y2>tamanhiotablero||
                         x3<0||x3>tamanhiotablero||
                         y3<0||y3>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            Triangle* tr=new Triangle(x1, y1, x2, y2, x3, y3, "Triangle");
            figuras.push_back(tr);
        }
    }
    else if(f=="Circle"){
        int x,y,r;
        cout<<"Ingresar fila y columna de punto : ";
        cin>>x;cin>>y;cin>>r;
        --x;--y;
        bool cortafuego=x<0||x>tamanhiotablero||
                        y<0||y>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            Circle* c=new Circle(r,x,y,"Circle");
            figuras.push_back(c);
        }
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
        cout<<"Ingresar fila y columna de punto inicial: ";
        cin >> x1;cin >> y1;
        cout<<"Ingresar fila y columna de punto final: ";
        cin >> x2;cin >> y2;
        --x1;--y1;
        --x2;--y2;
        bool cortafuego= x1<0||x1>tamanhiotablero||
                         y1<0||y1>tamanhiotablero||
                         x2<0||x2>tamanhiotablero||
                         y2<0||y2>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            figuras[n]->GetPoints()[0]->SetPoint(x1,y1);
            figuras[n]->GetPoints()[1]->SetPoint(x2,y2);
        }
    }else if(figuras[n]->NombreFigura()=="Rectangle"){
        int x1,y1,x2,y2;
        cout<<"Ingresar fila y columna de punto inicial: ";
        cin>>x1;cin>>y1;
        cout<<"Ingresar fila y columna de punto final: ";
        cin>>x2;cin>>y2;
        --x1;--y1;
        --x2;--y2;
        bool cortafuego= x1<0||x1>tamanhiotablero||
                         y1<0||y1>tamanhiotablero||
                         x2<0||x2>tamanhiotablero||
                         y2<0||y2>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            figuras[n]->GetPoints()[0]->SetPoint(x1,y1);
            figuras[n]->GetPoints()[1]->SetPoint(x2,y2);
        }
    }else if(figuras[n]->NombreFigura()=="Triangle"){
        int x1,y1,x2,y2,x3,y3;
        cout<<"Ingresar fila y columna de punto 1: ";
        cin>>x1;cin>>y1;
        cout<<"Ingresar fila y columna de punto 2: ";
        cin>>x2;cin>>y2;
        cout<<"Ingresar fila y columna de punto 3: ";
        cin>>x3;cin>>y3;
        --x1;--y1;
        --x2;--y2;
        --x3;--y3;
        bool cortafuego= x1<0||x1>tamanhiotablero||
                         y1<0||y1>tamanhiotablero||
                         x2<0||x2>tamanhiotablero||
                         y2<0||y2>tamanhiotablero||
                         x3<0||x3>tamanhiotablero||
                         y3<0||y3>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            figuras[n]->GetPoints()[0]->SetPoint(x1,y1);
            figuras[n]->GetPoints()[1]->SetPoint(x2,y2);
            figuras[n]->GetPoints()[2]->SetPoint(x3,y3);
        }
    }else{
        int x,y,r;
        cout<<"Ingresar fila y columna de punto: ";
        cin>>x;cin>>y;cin>>r;
        --x;--y;
        bool cortafuego= x<0||x>tamanhiotablero||
                         y<0||y>tamanhiotablero;
        if(cortafuego){
            cout<<"COORDENADAS NO VALIDAS, NO SE CREO LA FIGURA"<<endl;
        }else{
            figuras[n]->GetPoints()[0]->SetPoint(x,y);
            figuras[n]->SetR(r);
        }
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
                bool corta=newx1<0||newx2<0||
                           newx1>tamanhiotablero||newx2>tamanhiotablero||
                           newy1<0||newy1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx2,newy1);
                }
            }else{
                int newy1=puntos[1]->GetY()+calcular;
                bool corta=newx1<0||newx2<0||
                           newx1>tamanhiotablero||newx2>tamanhiotablero||
                           newy1<0||newy1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx2,newy1);
                    puntos[1]->SetPoint(newx1,newy1);
                }
            }
        }
        else if(puntos[0]->GetY()==puntos[1]->GetY()){
            int calcular= abs(puntos[0]->GetX()-puntos[1]->GetX())/2;
            int newy2=puntos[1]->GetY()-calcular;
            int newy1=puntos[0]->GetY()+calcular;
            if(puntos[0]->GetX()<puntos[1]->GetX()){
                int newx1=puntos[0]->GetX()+calcular;
                bool corta=newy1<0||newy2<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1<0||newx1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx1,newy2);
                }
            }else{
                int newx1=puntos[1]->GetX()+calcular;
                bool corta=newy1<0||newy2<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1<0||newx1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy2);
                    puntos[1]->SetPoint(newx1,newy1);
                }
            }
        }
        else{
            if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY() ||
                puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY() ){
                int newx1=puntos[0]->GetX();
                int newy1=puntos[1]->GetY();
                int newx2=puntos[1]->GetX();
                int newy2=puntos[0]->GetY();
                bool corta=newy1<0||newy2<0||newx2<0||newx1<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1>tamanhiotablero||newx2>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx2,newy2);
                }
            }else{
                int newx1=puntos[1]->GetX();
                int newy1=puntos[0]->GetY();
                int newx2=puntos[0]->GetX();
                int newy2=puntos[1]->GetY();
                bool corta=newy1<0||newy2<0||newx2<0||newx1<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1>tamanhiotablero||newx2>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx2,newy2);
                }
            }
        }
    }


    else if(nombre=="Rectangle"){
        if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[0]->GetX()+1;
            int newy1=puntos[1]->GetY()+1;
            int newx2=puntos[1]->GetX()-1;
            int newy2=puntos[0]->GetY()-1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }else if(puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY()){
            int newx1=puntos[0]->GetX()-1;
            int newy1=puntos[1]->GetY()-1;
            int newx2=puntos[1]->GetX()+1;
            int newy2=puntos[0]->GetY()+1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }
        else if(puntos[0]->GetX()>puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[1]->GetX()-1;
            int newy1=puntos[0]->GetY()+1;
            int newx2=puntos[0]->GetX()+1;
            int newy2=puntos[1]->GetY()-1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }else{
            int newx1=puntos[1]->GetX()+1;
            int newy1=puntos[0]->GetY()-1;
            int newx2=puntos[0]->GetX()-1;
            int newy2=puntos[1]->GetY()+1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }
    }

    else if(nombre=="Triangle"){
        if(puntos[0]->GetX()!=puntos[1]->GetX()&& puntos[0]->GetY()!=puntos[1]->GetY()){
            if(puntos[0]->GetY()!=puntos[2]->GetY()){
                int calculate= abs(puntos[0]->GetY()-puntos[2]->GetY());
                int newy=puntos[2]->GetY();
                int newx=0;
                if(puntos[0]->GetY()>puntos[2]->GetY()){
                    newx=puntos[2]->GetX()+calculate;
                }else {
                    newx=puntos[2]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[0]->GetX()-puntos[2]->GetX());
                int newx=puntos[2]->GetX();
                int newy=0;
                if(puntos[0]->GetX()<puntos[2]->GetX()){
                    newy=puntos[2]->GetY()+calculate;
                }else {
                    newy=puntos[2]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
            }
            if(puntos[1]->GetY()!=puntos[2]->GetY()){
                int calculate= abs(puntos[1]->GetY()-puntos[2]->GetY());
                int newy=puntos[2]->GetY();
                int newx=0;
                if(puntos[1]->GetY()>puntos[2]->GetY()){
                    newx=puntos[2]->GetX()+calculate;
                }else {
                    newx=puntos[2]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[1]->GetX()-puntos[2]->GetX());
                int newx=puntos[2]->GetX();
                int newy=0;
                if(puntos[1]->GetX()<puntos[2]->GetX()){
                    newy=puntos[2]->GetY()+calculate;
                }else {
                    newy=puntos[2]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }
        }
        else if(puntos[0]->GetX()!=puntos[2]->GetX()&& puntos[0]->GetY()!=puntos[2]->GetY()){// punto 1
            if(puntos[0]->GetY()!=puntos[1]->GetY()){
                int calculate= abs(puntos[0]->GetY()-puntos[1]->GetY());
                int newy=puntos[1]->GetY();
                int newx=0;
                if(puntos[0]->GetY()>puntos[1]->GetY()){
                    newx=puntos[1]->GetX()+calculate;
                }else {
                    newx=puntos[1]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[0]->GetX()-puntos[1]->GetX());
                int newx=puntos[1]->GetX();
                int newy=0;
                if(puntos[0]->GetX()<puntos[1]->GetX()){
                    newy=puntos[1]->GetY()+calculate;
                }else {
                    newy=puntos[1]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
            }
            if(puntos[2]->GetY()!=puntos[1]->GetY()){
                int calculate= abs(puntos[2]->GetY()-puntos[1]->GetY());
                int newy=puntos[1]->GetY();
                int newx=0;
                if(puntos[2]->GetY()>puntos[1]->GetY()){
                    newx=puntos[1]->GetX()+calculate;
                }else {
                    newx=puntos[1]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[2]->GetX()-puntos[1]->GetX());
                int newx=puntos[1]->GetX();
                int newy=0;
                if(puntos[2]->GetX()<puntos[1]->GetX()){
                    newy=puntos[1]->GetY()+calculate;
                }else {
                    newy=puntos[1]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }
        }
        else{// punto 0
            if(puntos[1]->GetY()!=puntos[0]->GetY()){
                int calculate= abs(puntos[1]->GetY() - puntos[0]->GetY());
                int newy= puntos[0]->GetY();
                int newx=0;
                if(puntos[1]->GetY()>puntos[0]->GetY()){
                    newx=puntos[0]->GetX()+calculate;
                }else{
                    newx=puntos[0]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[1]->GetX()-puntos[0]->GetX());
                int newx=puntos[0]->GetX();
                int newy=0;
                if(puntos[1]->GetX()<puntos[0]->GetX()){
                    newy=puntos[0]->GetY()+calculate;
                }else{
                    newy=puntos[0]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }
            if(puntos[2]->GetY()!=puntos[0]->GetY()){
                int calculate= abs(puntos[2]->GetY() - puntos[0]->GetY());
                int newy= puntos[0]->GetY();
                int newx=0;
                if(puntos[2]->GetY()>puntos[0]->GetY()){
                    newx=puntos[0]->GetX()+calculate;
                }else{
                    newx=puntos[0]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[2]->GetX()-puntos[0]->GetX());
                int newx=puntos[0]->GetX();
                int newy=0;
                if(puntos[2]->GetX()<puntos[0]->GetX()){
                    newy=puntos[0]->GetY()+calculate;
                }else{
                    newy=puntos[0]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }
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
                bool corta=newx1<0||newx2<0||
                           newx1>tamanhiotablero||newx2>tamanhiotablero||
                           newy1<0||newy1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx2,newy1);
                    puntos[1]->SetPoint(newx1,newy1);
                }
            }else{
                int newy1=puntos[1]->GetY()+calcular;
                bool corta=newx1<0||newx2<0||
                           newx1>tamanhiotablero||newx2>tamanhiotablero||
                           newy1<0||newy1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx2,newy1);
                }
            }
        }
        else if(puntos[0]->GetY()==puntos[1]->GetY()){
            int calcular= abs(puntos[0]->GetX()-puntos[1]->GetX())/2;
            int newy2=puntos[1]->GetY()-calcular;
            int newy1=puntos[0]->GetY()+calcular;
            if(puntos[0]->GetX()<puntos[1]->GetX()){
                int newx1=puntos[0]->GetX()+calcular;
                bool corta=newy1<0||newy2<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1<0||newx1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy2);
                    puntos[1]->SetPoint(newx1,newy1);
                }
            }else{
                int newx1=puntos[1]->GetX()+calcular;
                bool corta=newy1<0||newy2<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1<0||newx1>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx1,newy2);
                }
            }
        }
        else{
            if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY() ||
               puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY() ){
                int newx1=puntos[1]->GetX();
                int newy1=puntos[0]->GetY();
                int newx2=puntos[0]->GetX();
                int newy2=puntos[1]->GetY();
                bool corta=newy1<0||newy2<0||newx1<0||newx2<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1>tamanhiotablero||newx2>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx2,newy2);
                }
            }else{
                int newx1=puntos[0]->GetX();
                int newy1=puntos[1]->GetY();
                int newx2=puntos[1]->GetX();
                int newy2=puntos[0]->GetY();
                bool corta=newy1<0||newy2<0||newx1<0||newx2<0||
                           newy1>tamanhiotablero||newy2>tamanhiotablero||
                           newx1>tamanhiotablero||newx2>tamanhiotablero;
                if(corta){
                    cout<<"No es posible rotar"<<endl;
                }else{
                    puntos[0]->SetPoint(newx1,newy1);
                    puntos[1]->SetPoint(newx2,newy2);
                }
            }
        }
    }

    else if(nombre=="Rectangle"){
        if(puntos[0]->GetX()<puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[1]->GetX()-1;
            int newy1=puntos[0]->GetY()-1;
            int newx2=puntos[0]->GetX()+1;
            int newy2=puntos[1]->GetY()+1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }
        else if(puntos[1]->GetX()<puntos[0]->GetX()&&puntos[1]->GetY()<puntos[0]->GetY()) {
            int newx1 = puntos[1]->GetX() + 1;
            int newy1 = puntos[0]->GetY() + 1;
            int newx2 = puntos[0]->GetX() - 1;
            int newy2 = puntos[1]->GetY() - 1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }

        }
        else if(puntos[0]->GetX()>puntos[1]->GetX()&&puntos[0]->GetY()<puntos[1]->GetY()){
            int newx1=puntos[0]->GetX()+1;
            int newy1=puntos[1]->GetY()-1;
            int newx2=puntos[1]->GetX()-1;
            int newy2=puntos[0]->GetY()+1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
        }else{
            int newx1=puntos[0]->GetX()-1;
            int newy1=puntos[1]->GetY()+1;
            int newx2=puntos[1]->GetX()+1;
            int newy2=puntos[0]->GetY()-1;
            bool corta=newx1<0||newy1<0||newx2<0||newy2<0||
                       newx1>tamanhiotablero||newy1>tamanhiotablero||newx2>tamanhiotablero||newy2>tamanhiotablero;
            if(corta){
                cout<<"No es posible rotar"<<endl;
            }else{
                puntos[0]->SetPoint(newx1,newy1);
                puntos[1]->SetPoint(newx2,newy2);
            }
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
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[0]->GetX()-puntos[2]->GetX());
                int newx=puntos[2]->GetX();
                int newy=0;
                if(puntos[0]->GetX()>puntos[2]->GetX()){
                    newy=puntos[2]->GetY()+calculate;
                }else {
                    newy=puntos[2]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
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
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[1]->GetX()-puntos[2]->GetX());
                int newx=puntos[2]->GetX();
                int newy=0;
                if(puntos[1]->GetX()>puntos[2]->GetX()){
                    newy=puntos[2]->GetY()+calculate;
                }else {
                    newy=puntos[2]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }
        }
        else if(puntos[0]->GetX()!=puntos[2]->GetX()&& puntos[0]->GetY()!=puntos[2]->GetY()){// punto 1
            if(puntos[0]->GetY()!=puntos[1]->GetY()){
                int calculate= abs(puntos[0]->GetY()-puntos[1]->GetY());
                int newy=puntos[1]->GetY();
                int newx=0;
                if(puntos[0]->GetY()<puntos[1]->GetY()){
                    newx=puntos[1]->GetX()+calculate;
                }else {
                    newx=puntos[1]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[0]->GetX()-puntos[1]->GetX());
                int newx=puntos[1]->GetX();
                int newy=0;
                if(puntos[0]->GetX()>puntos[1]->GetX()){
                    newy=puntos[1]->GetY()+calculate;
                }else {
                    newy=puntos[1]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[0]->SetPoint(newx,newy);
                }
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
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[2]->GetX()-puntos[1]->GetX());
                int newx=puntos[1]->GetX();
                int newy=0;
                if(puntos[2]->GetX()>puntos[1]->GetX()){
                    newy=puntos[1]->GetY()+calculate;
                }else {
                    newy=puntos[1]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }
        }
        else{// punto 0
            if(puntos[1]->GetY()!=puntos[0]->GetY()){
                int calculate= abs(puntos[1]->GetY() - puntos[0]->GetY());
                int newy= puntos[0]->GetY();
                int newx=0;
                if(puntos[1]->GetY()<puntos[0]->GetY()){
                    newx=puntos[0]->GetX()+calculate;
                }else{
                    newx=puntos[0]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[1]->GetX()-puntos[0]->GetX());
                int newx=puntos[0]->GetX();
                int newy=0;
                if(puntos[1]->GetX()>puntos[0]->GetX()){
                    newy=puntos[0]->GetY()+calculate;
                }else{
                    newy=puntos[0]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[1]->SetPoint(newx,newy);
                }
            }
            if(puntos[2]->GetY()!=puntos[0]->GetY()){
                int calculate= abs(puntos[2]->GetY() - puntos[0]->GetY());
                int newy= puntos[0]->GetY();
                int newx=0;
                if(puntos[2]->GetY()<puntos[0]->GetY()){
                    newx=puntos[0]->GetX()+calculate;
                }else{
                    newx=puntos[0]->GetX()-calculate;
                }
                if(newx<0||newx>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }else{
                int calculate= abs(puntos[2]->GetX()-puntos[0]->GetX());
                int newx=puntos[0]->GetX();
                int newy=0;
                if(puntos[2]->GetX()>puntos[0]->GetX()){
                    newy=puntos[0]->GetY()+calculate;
                }else{
                    newy=puntos[0]->GetY()-calculate;
                }
                if(newy<0||newy>tamanhiotablero){
                    cout<<"No es posible Rotar "<<endl;
                }else{
                    puntos[2]->SetPoint(newx,newy);
                }
            }
        }
    }
}

void Rotate(vector<figure*>&figuras){
    int n=0;
    string rotar;
    Show(figuras);
    cout<<"Ingresar numero figura: ";
    cin>>n;
    --n;
    cout<<"Rotar (90 180 270 360) (-90 -180 -270 -360): ";
    cin>>rotar;
    if(rotar=="90"){
        Rotar90Horario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
    }else if(rotar=="180"){
        for(int i=0;i<2;i++){
            Rotar90Horario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
        }
    }else if(rotar=="270"){
        for(int i=0;i<3;i++){
            Rotar90Horario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
        }
    }else if(rotar=="360"){
        for(int i=0;i<4;i++){
            Rotar90Horario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
        }
    }
    else if (rotar=="-90"){
        Rotar90AntiHorario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
    }else if(rotar=="-180"){
        for(int i=0;i<2;i++){
            Rotar90AntiHorario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
        }
    }else if(rotar=="-270"){
        for(int i=0;i<3;i++){
            Rotar90AntiHorario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
        }
    }else if(rotar=="-360"){
        for(int i=0;i<4;i++){
            Rotar90AntiHorario(figuras[n]->GetPoints(),figuras[n]->NombreFigura());
        }
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
        cout<<endl;
        imprimirTablero(figuras,ta);
    }

}

int main() {
    menu();
}