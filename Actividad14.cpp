#include <iostream>
#include <string>

using namespace std;

class Persona{
    public: 
    Persona();

    private:
    string nombre, numCel;

};


class Taxi{
    public:
    Taxi();
    private:
    Persona responsable;
    int ident;


};



int main(){

    Taxi arrTaxi[10];

    cout<<"Bienvenido al Sistema de Taxis"<<endl;



    return 0; 
}