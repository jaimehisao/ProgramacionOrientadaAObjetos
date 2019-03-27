#include <iostream>
using namespace std;


//Class Reloj
class Reloj {
private:
    int hora;
    int minu;
public:
    Reloj();
    Reloj(int hora);
    Reloj(int hora, int minu);
    void setHora(int hora);
    void setMin(int minu);
    int getHora();
    int getMin();
    void muestra();
    void operator++();  // incrementa un minuto al reloj
    void operator--(); // decrementa un minuto al reloj
    void operator +=(int minuto);
    void operator -=(int minuto);
    Reloj operator+(int m);  // suma un Reloj con una cantidad de minutos y regresa el nuevo Reloj
    friend Reloj operator+(Reloj r1, Reloj r2);  // suma un Reloj con otro Reloj y regresa un nuevo Reloj
    Reloj operator-(int m);  // a un Reloj le resta una cantidad de minutos y regresa el nuevo Reloj
    friend Reloj operator-(Reloj r1, Reloj r2); // a un Reloj le resta otro Reloj y regresa el nuevo Reloj
    bool operator>(Reloj r);  // regresa true/false si el primer Reloj es > el segundo
    bool operator<(Reloj r); // regresa true/false si el primer Reloj es < el segundo
    bool operator==(Reloj r); // regresa true/false si ambos relojes son iguales
};

Reloj::Reloj(){
    hora = 0;
    minu = 0;
}
Reloj::Reloj(int hora){
    this->hora = hora;
    minu = 0;
}
Reloj::Reloj(int hora, int minu){
    this->hora = hora;
    this->minu = minu;
}

void Reloj::setHora(int hora){
    this->hora = hora;
}

void Reloj::setMin(int minu){
    this->minu = minu;
}

int Reloj::getHora(){
    return hora;
}

int Reloj::getMin(){
    return minu;
}


void Reloj::muestra(){
    if (hora<10)
        cout << "0";
    cout <<hora<<":";
    if (minu<10)
        cout << "0";
    cout <<minu<<endl;
}

//////////////////////////////////
//  Aqui va tu codigo
//////////////////////////////////

void Reloj::operator ++ () {
    minu++;
    if (minu == 60) {
        hora++;
        minu=0;
        if (hora == 24) {
            hora = 0;
        }
    }
}

void Reloj::operator -- () {
    minu--;
    if (minu == -1) {
        minu = 59;
        hora--;
        if (hora == -1) {
            hora = 23;
        }
    }
}

void Reloj::operator += (int minuto) {
    minu = minu + minuto;
    while (minu >= 60) {
        minu = minu - 60;
        hora = hora + 1;
        if (hora == 24) {
            hora = 0;
        }
    }
}

void Reloj::operator -= (int minuto) {
    minu = minu - minuto;
    while (minu < 0) {
        minu = minu + 60;
        hora  = hora - 1;
        if (hora < 0) {
            hora = 23;
        }
    }
}

Reloj Reloj:: operator + (int m) {
    Reloj r = *this;
    r.minu = r.minu + m;
    while (r.minu >= 60) {
        r.minu = r.minu - 60;
        r.hora = r.hora + 1;
        if (hora == 24) {
            hora = 0;
        }
    }
    return r;
}

Reloj Reloj:: operator - (int m) {
    Reloj r = *this;
    r.minu = r.minu - m;
    while (r.minu < 0) {
        r.minu = r.minu + 60;
        r.hora = r.hora - 1;
        if (hora < 20) {
            r.hora = 23;
        }
    }
    return r;
}

Reloj operator + (Reloj r1, Reloj r2) {
    Reloj r;
    r = r1;
    r += (r2.minu + (r2.hora*60));
    return r;
}

Reloj operator - (Reloj r1, Reloj r2) {
    Reloj r;
    r = r1;
    r -= (r2.minu + (r2.hora*60));
    return r;
}

bool Reloj::operator > (Reloj r) {
    int min1, min2;
    min1 = hora*60 + minu;
    min2 = r.hora*60 + r.minu;
    return (min1 > min2);
}

bool Reloj::operator < (Reloj r) {
    int min1, min2;
    min1 = hora*60 + minu;
    min2 = r.hora*60 + r.minu;
    return (min1 < min2);
}

bool Reloj::operator == (Reloj r) {
    int min1, min2;
    min1 = hora*60 + minu;
    min2 = r.hora*60 + r.minu;
    return (min1 == min2);
}





//Main Part of Code
int main() {
    int a1, a2, b2, a3, b3, op;
    cin >> op;
    cin >> a1 >> a2 >> b2 >> a3 >> b3;
    Reloj r1(a1), r2(a2,b2), r3(a3,b3), r4, r5, r6;
    
    switch (op){
        case 1:{
            ++r1;
            ++r2;
            ++r3;
            r1.muestra();
            r2.muestra();
            r3.muestra();
            break;
        }
        case 2:{
            --r1;
            --r2;
            --r3;
            r1.muestra();
            r2.muestra();
            r3.muestra();
            break;
        }
        case 3:{
            r4=r1+r2;
            r5=r1+r3;
            r6=r2+r3;
            r4.muestra();
            r5.muestra();
            r6.muestra();
            break;
        }
        case 4:{
            r4=r1+20;
            r5=r2+60;
            r6=r3+100;
            r4.muestra();
            r5.muestra();
            r6.muestra();
            break;
        }
        case 5:{
            r4=r1-r2;
            r5=r1-r3;
            r6=r2-r3;
            r4.muestra();
            r5.muestra();
            r6.muestra();
            break;
        }
        case 6:{
            r4=r1-20;
            r5=r2-60;
            r6=r3-100;
            r4.muestra();
            r5.muestra();
            r6.muestra();
            break;
        }
        case 7:{
            if (r1>r2)
                cout << "r1 SI es mayor a r2"<<endl;
            else
                cout << "r1 NO es mayor a r2" <<endl;
            if (r1>r3)
                cout << "r1 SI es mayor a r3"<<endl;
            else
                cout << "r1 NO es mayor a r3" <<endl;
            if (r2>r3)
                cout << "r2 SI es mayor a r3"<<endl;
            else
                cout << "r2 NO es mayor a r3" <<endl;
            break;
        }
        case 8:{
            if (r1<r2)
                cout << "r1 SI es menor a r2"<<endl;
            else
                cout << "r1 NO es menor a r2" <<endl;
            if (r1<r3)
                cout << "r1 SI es menor a r3"<<endl;
            else
                cout << "r1 NO es mayor a r3" <<endl;
            if (r2<r3)
                cout << "r2 SI es menor a r3"<<endl;
            else
                cout << "r2 NO es menor a r3" <<endl;
            break;
        }
        case 9:{
            if (r1==r2)
                cout << "r1 SI es igual a r2"<<endl;
            else
                cout << "r1 NO es igual a r2"<<endl;
            if (r1==r3)
                cout << "r1 SI es igual a r3"<<endl;
            else
                cout << "r1 NO es igual a r3"<<endl;
            if (r2==r3)
                cout << "r2 SI es igual a r3"<<endl;
            else
                cout << "r2 NO es igual a r3"<<endl;
            break;
        }
    }
    return 0;
}