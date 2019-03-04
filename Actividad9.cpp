/*
Actividad9.cpp 
Distancia en Pulgadas y Pies
Este programa recibe dos valores de distancia para crear dos objetos de Distancia y crea objetos con la suma y resta de los mismos
Por Jaime Hisao Yesaki Hinojosa A01720044
Para la clase de Programacion Orientada a Objetos en el Tec de Monterrey  
*/

#include <iostream>
using namespace std;

//Clase de Distancia con sus constructores y metodos
class Distance{
private:
    int feet, inches;
public:
    Distance();
    Distance(int, int);
    int getFeet();
    int getInches();
    void setFeet(int);
    void setInches(int);
    Distance add(Distance);
    Distance subtract(Distance);
    double convierteMetros();
};

//Constructor Default
Distance::Distance(){
feet = 0;
inches = 0;
}

//Constructor con Valores
Distance::Distance(int feet1, int inches1){
    if(inches1 >= 12){
        int inchTemp = inches1%12;
        int feetTemp  = inches1/12;
        inches1 = inchTemp;
        feet1 -= feetTemp;
    }
    feet = feet1;
    inches = inches1;
}

int Distance::getFeet(){
   return feet; 
}

int Distance::getInches(){
    return inches;
}

Distance Distance::add(Distance obj2){
    int feetR = feet + obj2.getFeet();
    int inchesR = inches + obj2.getInches();

    while(inchesR >= 12){
        int inchTemp = inchesR%12;
        int feetTemp  = inchesR/12;
        inchesR = inchTemp;
        feetR += feetTemp;
    }

    Distance distance(feetR, inchesR);
    return distance;
}

Distance Distance::subtract(Distance obj2){
    int feetR = feet - obj2.getFeet();
    int inchesR = inches - obj2.getInches();

     while(inchesR < 0){
        int inchTemp = inchesR%12;
        int feetTemp  = inchesR/12;
        inchesR = 12 - abs(inchTemp);
        feetR -= 1;
    }

    Distance distance(feetR, inchesR);
    return distance;
}

double Distance::convierteMetros(){
    double metros = (feet*12+inches)*2.54/100;
    return metros;
}


int main(){

int temp1, temp2;
Distance a; //Default Constructor
cout<<"Dame el valor de pies del primer objeto..."<<endl;
cin>>temp1;
cout<<"Dame el valor de pulgadas del primer objeto..."<<endl;
cin>>temp2;
Distance b(temp1, temp2);
cout<<"Dame el valor de pies del segundo objetos..."<<endl;
cin>>temp1;
cout<<"Dame el valor de pulgadas del segundo objeto..."<<endl;
cin>>temp2;
Distance c(temp1, temp2);
Distance d = b.add(c);
Distance e = b.subtract(c);

cout<<endl<<endl;

cout<<"Objeto A tiene los valores de pies: "<<a.getFeet()<<" Valor de pulgadas de: "<<a.getInches()<<endl;
cout<<"Objeto B tiene los valores de pies: "<<b.getFeet()<<" Valor de pulgadas de: "<<b.getInches()<<endl;
cout<<"Objeto C tiene los valores de pies: "<<c.getFeet()<<" Valor de pulgadas de: "<<c.getInches()<<endl;
cout<<"Objeto D tiene los valores de pies: "<<d.getFeet()<<" Valor de pulgadas de: "<<d.getInches()<<endl;
cout<<"Objeto E tiene los valores de pies: "<<e.getFeet()<<" Valor de pulgadas de: "<<e.getInches()<<endl;

}