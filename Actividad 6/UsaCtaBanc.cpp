#include "CtaBanc.h"
#include <iostream>

using namespace std;

int main(){

    int option = 1;

    CtaBanc cuenta = CtaBanc("Cuenta", 0.0);

    while(option != 0){
        cout<<"Para DEPOSITAR presiona 1"<<endl;
        cout<<"Para RETIRAR presiona 2"<<endl;
        cout<<"Para CONSULTAR SALDO presiona 3"<<endl;
        cout<<"Para TERMINAR presiona 4"<<endl;

        cin>>option;
        int cantidad;

    switch(option){

        case 1:{
            cout<<"Cuanto quieres depositar?"<<endl;
            cin>>cantidad;
            cuenta.deposit(cantidad);
            break;
        }
        case 2:{
            cout<<"Cuanto quieres retirar?"<<endl;
            cin>>cantidad;
            if(cuenta.withdraw(cantidad)){
            cout<<"Se retiro la cantidad de: $"<<cantidad<<" , y el saldo actual es: $"<<cuenta.getBalance()<<endl;
            }else{
            cout<<"No hay suficiente dinero para retirar..."<<endl;
            }
            break;
        }
        case 3:{
            cout<<"Tu saldo al dia de hoy es...$"<<cuenta.getBalance()<<endl;
            break;
        }
        case 4:{
            cout<<"Adios!"<<endl;
            option = 0;
            break;
        }

    };

    }
    return 0;
}