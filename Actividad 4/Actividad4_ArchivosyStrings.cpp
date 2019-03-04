#include<iostream>
#include<fstream>

using namespace std;

string agregaComas(string numero){
    int counter = numero.length()-3;
    while(counter > 0){
        numero.insert(counter,",");
        counter -= 3;
    }
return numero;
}

int main(){

    ifstream archRead("/Users/hisao/ResilioSync/MacSync/Tec MTY/Maze/OOP Clase/entradaNumeros.txt");
    fstream archWrite("//Users/hisao/ResilioSync/MacSync/Tec MTY/Maze/OOP Clase/salidaNumeros.txt");

    string fraseToWrite, frase;
    
    if (archRead.is_open()){
     while (!archRead.eof()){
        getline(archRead,frase);
        if (frase != "") {
            fraseToWrite = agregaComas(frase);
            archWrite << frase<<" = " <<fraseToWrite << endl; // escribo la frase en el arch de salida
            cout << fraseToWrite << endl;
        }
    }
        
    archRead.close();
    }else{
        cout<<"File couldn´t be read..."<<endl;
        archWrite.close();
    }

    return 0;
}
