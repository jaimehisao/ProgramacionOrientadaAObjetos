#include<iostream>
#include<fstream>

using namespace std;

string ponAsterisco(string frase4, string palabra4){
    int longF4, position;
   do{
       position = frase4.find(palabra4);
       if(position != -1){
           frase4.erase(position, palabra4.length());
           frase4.insert(position,"*");
       }

   }while(position != -1);
    return frase4;
   }
    

int main(){

    ifstream archRead("/Users/hisao/ResilioSync/MacSync/Tec MTY/Maze/frases.txt");
    fstream archWrite("/Users/hisao/ResilioSync/MacSync/Tec MTY/Maze/salida.txt");

    string frase, palabra, fraseInv;

    cout<<"Dame una palabra..."<<endl;
    cin>>palabra;

    if (archRead.is_open()){
     while (!archRead.eof()){
        getline(archRead,frase);
        if (frase != "") {
            fraseInv = ponAsterisco(frase, palabra);
            archWrite << fraseInv << endl; // escribo la frase en el arch de salida
            cout << fraseInv << endl;
        }
    }
        
    archRead.close();
    }else{
        cout<<"File couldn´t be read..."<<endl;
        archWrite.close();
    }

    //  cout<<"Inserte una palabra..."<<endl;
    // getline(cin,frase4);

    //  cout<<"Inserte una palabra..."<<endl;
    // getline(cin,palabra4);


    return 0;
}
