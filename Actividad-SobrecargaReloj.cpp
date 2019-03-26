#include <iostream>
using namespace std;


//Class Reloj
class Reloj {
private:
    int hora;
    int minuto;
public:
    Reloj();
    Reloj(int h);
    Reloj(int h, int m);
    void setHora(int h);
    void setMin(int m);
    int getHora();
    int getMin();
    void muestra();
    void operator++();  // incrementa un minuto al reloj
    void operator--();  // decrementa un minuto al reloj
    void operator+=(int);
    void operator-=(int);
    Reloj operator+(int m);  // suma un Reloj con una cantidad de minutos y regresa el nuevo Reloj
    Reloj operator+(Reloj r);  // suma un Reloj con otro Reloj y regresa un nuevo Reloj
    Reloj operator-(int m);  // a un Reloj le resta una cantidad de minutos y regresa el nuevo Reloj
    Reloj operator-(Reloj r); // a un Reloj le resta otro Reloj y regresa el nuevo Reloj
    bool operator>(Reloj r);  // regresa true/false si el primer Reloj es > el segundo
    bool operator<(Reloj r); // regresa true/false si el primer Reloj es < el segundo
    bool operator==(Reloj r); // regresa true/false si ambos relojes son iguales
};

Reloj::Reloj(){
    hora = 0;
    minuto = 0;
}
Reloj::Reloj(int h){
    hora = h;
    minuto = 0;
}
Reloj::Reloj(int h, int m){
    hora = h;
    minuto = m;
}

void Reloj::setHora(int h){
    hora = h;
}

void Reloj::setMin(int m){
    minuto = m;
}

int Reloj::getHora(){
    return hora;
}

int Reloj::getMin(){
    return minuto;
}


void Reloj::muestra(){
    if (hora<10)
        cout << "0";
    cout <<hora<<":";
    if (minuto<10)
        cout << "0";
    cout <<minuto<<endl;
}


//Operator Overloading
void Reloj::operator--(){
    minuto--;
    if(minuto == -1){
        minuto = 59;
        hora--;
        if(hora == -1){
            hora = 23;
        }
    }
}

void Reloj::operator += (int minuto){
    this -> minuto  = this-> minuto + minuto;
    while(this -> minuto >= 60){
        this->minuto = this->minuto -60;
        this->hora++;
        if(this->hora == 24){
            this->hora = 0;
        }
    }
}

void Reloj::operator-=(int minuto){
    this -> minuto = this -> minuto - minuto;
    while(this -> minuto < 0){
        this -> minuto = this -> minuto +60;
        this -> hora = this -> hora - 1;
        if(this -> hora == 0){
            this -> hora = 23;
        }
    }
}

Reloj Reloj::operator+(int minuto){
    Reloj r = *this;
    r.minuto = r.minuto + minuto;
    while(r.minuto >= 60){
        r.minuto = r.minuto - 60;
        r.hora = r.hora + 1;
        if(r.hora == 24){
            r.hora = 0;
        }
    }
    return r;
}

Reloj Reloj::operator-(int minuto){
    Reloj r = *this;
    r.minuto = r.minuto - minuto;
    while(r.minuto < 0){
        r.minuto = r.minuto + 60;
        r.hora = r.hora -1;
        if(r.hora < 0){
            r.hora = 23;
        }
    }
    return r;
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