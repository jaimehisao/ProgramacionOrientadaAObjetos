/*
Agrega a la clase lo siguiente:
• Métodos de acceso y modificación para sus atributos
• Método retira que recibe como parámetro la cantidad a retirar y verifica si hay suficiente saldo para retirar. El método regresa como valor de retorno True si pudo retirar y False si no se pudo.
• Método deposita que recibe como parámetro una cantidad y la agrega al saldo.
*/

#ifndef Reloj_h
#define Reloj_h
#include <iostream>
#include <string>

using namespace std;

class CtaBanc{
    private:
        string name;
        double balance;
    public:
        CtaBanc();
        CtaBanc(string name, double balance);
        void setBalance(double);
        double getBalance();
        void setName(string);
        string getName();
        void deposit(double);
        bool withdraw(double);
};

CtaBanc::CtaBanc(){

}

CtaBanc::CtaBanc(string name1, double balance1){
    name = name1;
    balance = balance1;
}

void CtaBanc::setBalance(double balance1){
     balance = balance1;
}

void CtaBanc::setName(string name1){
    name = name1;
}

string CtaBanc::getName(){
    return name;
}

void CtaBanc::deposit(double toDeposit){
    balance += toDeposit;
}

bool CtaBanc::withdraw(double toWithdraw){
    if(toWithdraw <= balance){
        balance -= toWithdraw;
        return true;
    }else{
        return false;
    }
}

double CtaBanc::getBalance(){
    return balance;
}

#endif