#include <iostream>
#include <cmath>
using namespace std;

class Cuadratica {
public:
    Cuadratica();
    Cuadratica(int, int, int);
    void muestra();
    Cuadratica operator+(Cuadratica);
    Cuadratica operator*(int);
    bool operator==(Cuadratica);
    friend Cuadratica operator-(Cuadratica, Cuadratica);
    friend Cuadratica operator+=(Cuadratica &c1, Cuadratica c2);
    friend Cuadratica operator++(Cuadratica &c1);
private:
    int iCoefA, iCoefB, iCoefC;
    
};

Cuadratica::Cuadratica() {
    iCoefA = 1;
    iCoefB = 1;
    iCoefC = 1;
}

Cuadratica::Cuadratica(int iA, int iB, int iC) {
    iCoefA = iA;
    iCoefB = iB;
    iCoefC = iC;
}

void Cuadratica::muestra() {
    if(iCoefA != 0){
        cout << iCoefA;
        cout << "x^2 ";
    }
    if (iCoefB != 0) {
        if(iCoefB > 0) {
            cout << " + ";
        }
        cout << iCoefB;
        cout << "x ";
    }
    if (iCoefC != 0){
        if(iCoefC > 0) {
            cout << " + ";
        }
        cout << iCoefC << endl;
    }
}

//Operator overloading Non-Friend


Cuadratica Cuadratica::operator+ (Cuadratica cuad){
  Cuadratica cReturned;
  cReturned.iCoefA = this->iCoefA + cuad.iCoefA;
  cReturned.iCoefB = this->iCoefB + cuad.iCoefB;
  cReturned.iCoefC = this->iCoefC + cuad.iCoefC;
  return cReturned;
}

Cuadratica Cuadratica::operator* (int num){
  Cuadratica cReturned;
  cReturned.iCoefA = this->iCoefA * num;
  cReturned.iCoefB = this->iCoefB * num;
  cReturned.iCoefC = this->iCoefC * num;
  return cReturned;
}

bool Cuadratica::operator == (Cuadratica c){
  return
  (this->iCoefA == c.iCoefA && 
   this->iCoefB == c.iCoefB && 
   this->iCoefC == c.iCoefC
  );
}


//Friend Operator Overloading
Cuadratica operator-(Cuadratica c1, Cuadratica c2){
  Cuadratica cResult;
  cResult.iCoefA = c1.iCoefA - c2.iCoefA;
  cResult.iCoefB = c1.iCoefB - c2.iCoefB;
  cResult.iCoefC = c1.iCoefC - c2.iCoefC;
  return cResult;
}

Cuadratica operator+=(Cuadratica &c1, Cuadratica c2){
  c1.iCoefA += c2.iCoefA;
  c1.iCoefB += c2.iCoefB;
  c1.iCoefC += c2.iCoefC;
  return c1;
}

Cuadratica operator++(Cuadratica &c1){
  c1.iCoefC = c1.iCoefC + 1;
  return c1;
}


int main(){
    int iA, iB, iC;
    Cuadratica ec1(5,3,2), ecRes;
    Cuadratica ec3 = ec1; // ec1 y ec3 tienen los mismos valores.
    cout << "Teclea los coeficientes para la segunda ecuación" << endl;
    cin >> iA >> iB >> iC;
    Cuadratica ec2(iA, iB, iC);
    
    /*********************************/
    
    cout << endl;
    cout << "=== Suma de Ecuaciónes 1 y 2" << endl;
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    
    // Usa la sobrecarga para hacer la suma
    
    cout << "Resultado :";
    ecRes.muestra();
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    cout << endl;
    
    /*********************************/
    
    cout << endl;
    cout << "=== Resta de Ecuaciónes 1 y 2" << endl;
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    
    // Usa la sobrecarga para hacer la resta
    cout << "Resultado :";
    ecRes.muestra();
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    cout << endl;
    
    /*********************************/
    
    cout << endl;
    cout << "=== Multiplica Ecuación 1 por valor entero 2" << endl;
    cout << "Ecuación 1 :";
    ec1.muestra();
    
    // Usa la sobrecarga para hacer la multiplicación
    
    cout << "Resultado :";
    ecRes.muestra();
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << endl;
    
    /*********************************/
    
    cout << endl;
    cout << "=== Compara con == ecuación 1 y ecuación 2, deben serdiferentes" << endl;
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    if ( ec1 == ec2) { // agrega la comparación que hace falta
        cout << "Son iguales" << endl;
    } else {
        cout << "Son diferentes " << endl;
    }
    
    /*********************************/
    
    cout << endl;
    cout << "=== Compara con == ecuación 1 y ecuación 3, deben ser iguales" << endl;
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    
    if (ec1 == ec2) { // agrega la comparación que hace falta)
        cout << "Son iguales" << endl;
    } else {
        cout << "Son diferentes " << endl;
    }
    
    /*********************************/
    
    cout << endl;
    cout << "=== Aplica += para sumar Ecuaciónes 1 y 2" << endl;
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    
    // Usa la sobrecarga para hacer el +=
    cout << "Ecuación 1 :";
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    cout << endl;
    
    /*********************************/
    
    cout << endl;
    cout <<  "=== Aplica ++ a Ecuación 1 " << endl;
     cout << "Ecuación 1 :";
    ec1.muestra();
    
    // Usa la sobrecarga para hacer el incremento
    
    cout << "Regresa :";
    ecRes.muestra();
    cout << "Ecuación 1 :";
    ec1.muestra();
    
    return 0;
    
}
