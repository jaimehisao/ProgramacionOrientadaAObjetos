#include <iostream>
#include <stdio.h>
#include <string.h>
 
using namespace std;

int main(){
    //Ejercicio 1

    char n1[50] = "", n2[20], salida[50]="Hola ";
    int pos=0;
    cout<<"Ejercicio 1"<<endl;
    cout<<"Hola, dame tu nombre(s)..."<<endl;
    cin.getline(n1,50);
    for(int i=0; i<50; i++) {
        if (n1[i] == ' ') {
            pos = i;
            i=50;
        }
    }

    strncpy(n2,n1,pos);
    strcat(salida, n2);
    strcat(salida," !!!");
    cout << salida << endl << endl;

/*-------------------------------------------------------------------------------
                                    EJERCICIO 2
-------------------------------------------------------------------------------*/
    

    cout<<endl<<endl<<endl;
    cout<<"Ejercicio 2"<<endl;

    char palabra1[50];
    char palabra2[50];
    char palabra3[50];

    cout<<"Dame la palabra 1: "<<endl;
    cin>>palabra1;
     cout<<"Dame la palabra 2: "<<endl;
    cin>>palabra2;
     cout<<"Dame la palabra 3: "<<endl;
    cin>>palabra3;

    int size1 = strlen(palabra1);
    int size2 = strlen(palabra2);
    int size3 = strlen(palabra3);

    if(size2 <= size1){
        char tempArr[50];
        strcpy(tempArr, palabra1);
        strcpy(palabra1, palabra2);
        strcpy(palabra2, tempArr);
    }

     if(size3 <= size2){
        char tempArr[50];
        strcpy(tempArr, palabra2);
        strcpy(palabra2, palabra3);
        strcpy(palabra3, tempArr);
    }

    cout<<"Palabra 1: "<<palabra1<<endl;
    cout<<"Palabra 2: "<<palabra2<<endl;
    cout<<"Palabra 3: "<<palabra3<<endl;

    /*

 comparo las primeras 2 y guardo la menor en palabra1 y la otra en palabra2

 comparo la menor (palabra1) con palabra3 y guardo la menor en palabra1 y la otra en palabra3

 ahora comparo palabra2 y palabra3 y dejo la menor en palabra2 y la otra en palabra3

 Muestro las palabras en orden.


    */



    return 0;
}
