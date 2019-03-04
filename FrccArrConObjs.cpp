/*
Fracciones en Arreglos de Objetos -- Class Assignment
This program generates fraction objects and has funcitons to calculate the real value, this objects are then stored in an Array.
It showcases the usefulness of Objects and how to create them, and the "flexibility" of storing them in Arrays
By: Jaime Hisao Yesaki Hinojosa -- A01720044 -- Use under your own risk and responsabilities
Work from: Object Oriented Programming Class at Tec de Monterrey at Campus Monterrey
*/

#include <iostream>

using namespace std;

class Fraccion{
public:
    Fraccion();
    Fraccion(int num, int denom);
    int getNumerator();
    int getDenominator();
    void setNumerator(int);
    void setDenominator(int);
    double calcValorReal();

private:
    int numerator;
    int denominator;
};

Fraccion::Fraccion(){
    numerator = 1;
    denominator = 2;
}

Fraccion::Fraccion(int num, int den){
    numerator = num;
    denominator = den;
}

int Fraccion::getNumerator(){
    return numerator;
}

int Fraccion::getDenominator(){
    return denominator;
}

void Fraccion::setDenominator(int denom){
    denominator = denom;
}

void Fraccion::setNumerator(int numerom){
    numerator = numerom;
}

double Fraccion::calcValorReal(){
    return double(numerator)/double(denominator);
}

int main(){

    int manyObjects;
    cout<<"Cuantos objetos quieres crear?"<<endl;
    cin>>manyObjects;
    Fraccion arr[manyObjects];

    for(int i = 0; i < manyObjects; i++){
        int num, denom;
        cout<<"Dame el Numerador..."<<endl;
        cin>>num;
        cout<<"Dame el Denominador..."<<endl;
        cin>>denom;
        arr[i].setNumerator(num);
        arr[i].setDenominator(denom);
    }

    for(int i = 0; i < manyObjects; i++){
        cout<<"El valor de la fraccion #"<<i+1<<" tiene un valor de..." <<arr[i].getNumerator()<<"/"<<arr[i].getDenominator()<<" que equivale a "<<arr[i].calcValorReal()<<endl;
    }


    return 0;
}