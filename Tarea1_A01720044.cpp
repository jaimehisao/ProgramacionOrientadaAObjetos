/*
Tarea #1 -- Programacion Orientada a Objetos
Por: Jaime Hisao Yesaki Hinojosa - A01720044
Este programa recibe los primeros digitos del ISBN de un libro y genera el ultimo digito (digito de control)
El programa se ejecuta tantas veces que el usuario quiera.
*/


#include <iostream>
#include <string>

using namespace std;

int main(){

    cout<<"Bienvenido a la calculadora del ultimo digito del ISBN..."<<endl;

    //Sets option val to "s" so the loop starts, then declares the entry string.
    char option = 's';
    string entry;

    //Loop that repeats itself as long as the user doesn't enter "n" when prompted.
    while(option != 'n'){
        cout<<"Dame el ISBN..."<<endl;
        cin>>entry;
        int isbnSum = 0;

        //Make the sum
        for(int i = 1; i<= 9; i++){
            isbnSum += i*(int(entry[i-1])-48);
        }

        //Calculate the residual value
        int residualVal = isbnSum%11;

        //Compare Values to determine what message to print
        if(residualVal < 10){
            cout<<"El ISBN es: "<<entry<<"-"<<residualVal<<endl;
        }else{
            cout<<"El ISBN es: "<<entry<<"-X"<<endl;
        }
        cout<<"Si quieres calcular otro ISBN pon \"s\", de lo contrario pon \"n\""<<endl;
        cin>>option;
    } //END of Loop -- Loop runs while "n" is not pressed when prompted.

        cout<<"Gracias! Adios!"<<endl;
    return 0;
}

/*

    Casos de prueba utilizados
            842053211 = 842053211-8

            032130332 = 032130332-6

            043935806 = 043935806-X
*/