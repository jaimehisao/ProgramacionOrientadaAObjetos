#include <iostream>

using namespace std;

class Fraccion{
	friend double operator !(Fraccion f);
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
	Fraccion operator + (Fraccion f);
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

Fraccion Fraccion:: operator + (Fraccion f){ 
    Fraccion res;
    res.num = this->num * f.den + this->den * f.num;
    res.den = this->den * f.den;
    return res;
}


int main(){
    Fraccion f1(1,3), f2(3,4), f3(1,5), f4;
	
    // la suma de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La suma de las fracciones 1 y 2 " << endl;
	f4 = f1 + f2;
    f4.muestra();
    
    // el valor en decimal de la fracciÃ³n 1/3
    cout << endl;
    cout << "El valor decimal de la fracciÃ³n 1 "<< endl;
    cout << !f1;
    
    return 0;
}