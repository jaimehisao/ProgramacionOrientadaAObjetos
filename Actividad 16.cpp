#include <iostream>

/*
*  Multiplicación de dos fracciones
>Compara si la primera fracción es mayor que la segunda
++ Suma el valor 1/1 a una fracción y regresa la nueva fracción
-       Operador unitario – (negativo), regresa una fracción que contiene la fracción original con el numerador con el signo cambiado.
-       Operador resta  - . Para implementar este método realiza una suma del valor de la primera fracción con el valor negativo de la segunda fracción (usando el operador negativo que hiciste en el punto anterior).
*/

using namespace std;

class Fraccion{
	friend double operator !(Fraccion f);
    friend Fraccion operator + (Fraccion, Fraccion);
    friend Fraccion operator > (Fraccion, Fraccion);
    friend Fraccion operator - (Fraccion);
    friend Fraccion operator - (Fraccion, Fraccion);
    friend Fraccion operator ++ (Fraccion);
public:
	// Constructores
	Fraccion();
	Fraccion(int n, int d);
	// metodos de acceso
	int getNum();
	int getDen();
	// metodos de modificacion
	void setNum(int n);
	void setDen(int d);
	// metodos

	void muestra();
	
private:
	int num, den;
};

Fraccion::Fraccion()
{
    num = 1;
    den = 2;
}

Fraccion::Fraccion(int n, int d)
{
    num = n;
    den = d;
}

int Fraccion::getNum()
{
    return num;
}

int Fraccion::getDen()
{
    return den;
}

void Fraccion::setNum(int n)
{
    num = n;
}

void Fraccion::setDen(int d)
{
    den = d;
}

void Fraccion::muestra()
{
	cout << num << "/" << den;
}

double operator !(Fraccion f)
{
    return  (double)f.num/f.den;
}

Fraccion operator + (Fraccion f, Fraccion f2){ 
    Fraccion res;
    res.num = f2.num * f.den + f2.den * f.num;
    res.den = f2.den * f.den;
    return res;
}


Fraccion operator > (Fraccion f, Fraccion f2){

}

Fraccion operator - (Fraccion f){

}

Fraccion operator - (Fraccion f, Fraccion f2){

}

Fraccion operator ++(Fraccion f1){
    Fraccion retrn(1,1);
    retrn = f1+retrn;
    return retrn;
}




int main(){
    Fraccion f1(1,3), f2(3,4), f3(1,5), f4;
	
    // la suma de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La suma de las fracciones 1 y 2:m " << endl;
	f4 = f1 + f2;
    f4.muestra();
    
    // el valor en decimal de la fracciÃ³n 1/3
    cout << endl;
    cout << "El valor decimal de la fraccion 1: "<< endl;
    cout << !f1;
    
    return 0;
}