#include <iostream>

using namespace std;

class Rectangulo{
    public: 
        double calcArea();
        void setLargo(double);
        void setAncho(double);
        Rectangulo(double, double);
        Rectangulo();
        Rectangulo(double , double , Rectangulo* sigiente);

    private:
        double largo, ancho;
        Rectangulo* siguiente;
};

Rectangulo::Rectangulo(){
    this -> largo = 0;
    this -> ancho = 0;
    this -> siguiente = NULL;
}

Rectangulo::Rectangulo(double ancho, double largo){
    this -> largo = largo;
    this -> ancho = ancho;
    this -> siguiente = NULL;
}

Rectangulo::Rectangulo(double ancho, double largo, Rectangulo* siguiente){
    this -> largo = largo;
    this -> ancho = ancho;
    this -> siguiente = siguiente;
}

double Rectangulo::calcArea(){
    return largo*ancho;
}

void Rectangulo::setAncho(double ancho){
    this -> ancho = ancho;
}

void Rectangulo::setLargo(double largo){
    this -> largo = largo;
}

int main(){

    int largo, ancho;

    double arr[20];
    int cont = 0;

    Rectangulo* rect = new Rectangulo();

    char op = 's';

    while(op == 's'){
        cout<<"Largo: "<<endl;
        cin>>largo;
        cout<<"Ancho: "<<endl;
        cin>>ancho;

        rect -> setAncho(ancho);
        rect -> setLargo(largo);

        arr[cont] = rect -> calcArea();
        cont++;

        cout<<"Quieres agregar más rectangulos? s/n"<<endl;
        cin>>op;
    }

    cout<<"Las Areas Son:"<<endl;
    for(int i = 0; i < cont; i++){
        cout<<arr[i]<<endl;
    }


    return 0;
}
