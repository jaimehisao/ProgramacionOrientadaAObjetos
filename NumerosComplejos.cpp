/*
NumerosComplejos.cpp -- Class Assignment
This program generates complex number objects and has methods to add and subtract them with other objects.
By: Jaime Hisao Yesaki Hinojosa -- A01720044 -- Use under your own risk and responsabilities
Work from: Object Oriented Programming Class at Tec de Monterrey at Campus Monterrey
*/
#include<iostream>

using namespace std;

class NumerosComplejos{
public:
    NumerosComplejos();
    NumerosComplejos(double real, double fake);
    int getReal();
    int getImaginary();
    void setReal(double);
    void setImaginary(double);
    NumerosComplejos suma(NumerosComplejos);
    NumerosComplejos resta(NumerosComplejos);

private:
    double real;
    double imaginary;
};

NumerosComplejos::NumerosComplejos(){
    real = 0;
    imaginary = 0;
}

NumerosComplejos::NumerosComplejos(double real1, double imaginary1){
    real = real1;
    imaginary = imaginary1;
}

int NumerosComplejos::getReal(){
    return real;
}

int NumerosComplejos::getImaginary(){
    return imaginary;
}

void NumerosComplejos::setReal(double really){
    real = really;
}

void NumerosComplejos::setImaginary(double imag){
    imaginary = imag;
}

NumerosComplejos NumerosComplejos::suma(NumerosComplejos num){
    double realTemp = real + num.getReal();
    double imagTemp = imaginary + num.getImaginary();
    NumerosComplejos temp(realTemp, imagTemp);
    return temp;
}

NumerosComplejos NumerosComplejos::resta(NumerosComplejos num){
    double realTemp = real - num.getReal();
    double imagTemp = imaginary - num.getImaginary();
    NumerosComplejos temp(realTemp, imagTemp);
    return temp;
}

int main(){
    NumerosComplejos a;
    NumerosComplejos b(1,3);
    NumerosComplejos c(4,5);
    NumerosComplejos d = b.suma(c);
    NumerosComplejos e = b.resta(c);

    cout<<"NC1: "<<"("<<a.getReal()<<","<<a.getImaginary()<<")"<<endl;
    cout<<"NC2: "<<"("<<b.getReal()<<","<<b.getImaginary()<<")"<<endl;
    cout<<"NC3: "<<"("<<c.getReal()<<","<<c.getImaginary()<<")"<<endl;
    cout<<"NC4: "<<"("<<d.getReal()<<","<<d.getImaginary()<<")"<<endl;
    cout<<"NC5: "<<"("<<e.getReal()<<","<<e.getImaginary()<<")"<<endl;

}
