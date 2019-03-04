/*
Fraccion -- Class Assignment
This program generates fraction objects and has funcitons to calculate the real value.
It showcases the usefulness of Objects and how to create them.
By: Jaime Hisao Yesaki Hinojosa -- A01720044 -- Use under your own risk and responsabilities
Work from: Object Oriented Programming Class at Tec de Monterrey at Campus Monterrey
*/

#include<iostream>

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
    Fraccion frac1;
    Fraccion frac2(3,4);

    cout<<"El valor de la fraccion 1 es: "<<frac1.getNumerator()<<"/"<<frac1.getDenominator()<<endl;
    cout<<"El valor de la fraccion 1 es: "<<frac2.getNumerator()<<"/"<<frac2.getDenominator()<<endl;

    cout<<"El valor real de la fraccion 1 es: "<<frac1.calcValorReal()<<endl;
    cout<<"El valor real de la fraccion 2 es: "<<frac2.calcValorReal()<<endl;
}
