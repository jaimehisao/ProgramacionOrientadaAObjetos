/*
Actividad 14 -- Class Assignment
This is a program to have a system of Taxis, it showcases the usability of 
Arrays of Objects and also uses OOP Composition, which is the competency evaluated in this homework.
By: Jaime Hisao Yesaki Hinojosa -- A01720044 -- Use under your own risk and responsabilities
Work from: Object Oriented Programming Class at Tec de Monterrey at Campus Monterrey
*/

#include <iostream>
#include <string>

using namespace std;

//START OF CLASS PERSONA

class Persona{
    public: 
    Persona();
    Persona(string, string);
    string getNombre();
    string getNumCel();
    void setNombre(string);
    void setNumCel(string);

    private:
    string _nombre, _numCel;
};

Persona::Persona(){
    _nombre = "";
    _numCel = "";
}

Persona::Persona(string nombre, string cel){
    _nombre = nombre;
    _numCel = cel;
}

string Persona::getNombre(){
    return _nombre;
}

string Persona::getNumCel(){
    return _numCel;
}

void Persona::setNombre(string nm){
    _nombre = nm;
}

void Persona::setNumCel(string nc){
    _numCel = nc;
}

//END OF CLASS PERSONA

//START OF CLASS TAXI

class Taxi{
    public:
    Taxi();
    Taxi(int, Persona);
    int getID();
    void setID(int);
    Persona getPersona();
    void setPersona(Persona);
    static int numOfTaxis;
    static int getNumOfTaxis();
    static void addToTaxis();
    private:
    Persona _responsable;
    int _ident;
};

int Taxi::numOfTaxis = 0;

int Taxi::getNumOfTaxis(){
    return numOfTaxis;
}

void Taxi::addToTaxis(){
    numOfTaxis++;
}

Taxi::Taxi(){
  _ident = 0; 
}

Taxi::Taxi(int id, Persona pers){
    _ident = id;
    _responsable = pers;
}

void Taxi::setID(int id1){
    _ident = id1;
}

void Taxi::setPersona(Persona pers){
    _responsable = pers;
}

int Taxi::getID(){
    return _ident;
}

Persona Taxi::getPersona(){
    return _responsable;
}

//END OF CLASS TAXI

//Ignore this part of the code
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49,
        BLINK = 5
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}


int main(){
    Color::Modifier red(Color::FG_RED);
    Color::Modifier redb(Color::BG_RED);
    Color::Modifier grn(Color::FG_GREEN);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier defb(Color::BG_DEFAULT);
    Color::Modifier blu(Color::FG_BLUE);

    Taxi arrTaxi[50];
    int numberOfTaxis;

    cout<<"Bienvenido al Sistema de Taxis"<<endl;
    cout<<redb<<"No hay Taxis registrados, por lo que tendras que registrarlos"<<defb<<endl;
    cout<<"¿Cuantos Taxis quieres? ";
    cout<<red<<"Recuerda que hay un maximo de 50 Taxis para ingresar"<<def<<endl;
    cin>>numberOfTaxis;

    string nombre, celular;

    for(int i = 0; i < numberOfTaxis; i++){
        cout<<grn<<"Taxi #"<<i+1<<def<<endl;
        cout<<"Dame el nombre del responsable del Taxi"<<endl;
        cin.ignore();
        getline(cin, nombre);
        cout<<"¿Cuál es el celular del Responsable del Taxi?"<<endl;
        cin>>celular;

        Persona tmp;
        tmp.setNombre(nombre);
        tmp.setNumCel(celular);
        arrTaxi[i].setPersona(tmp);
        arrTaxi[i].setID(arrTaxi[i].numOfTaxis+1);
        arrTaxi[i].numOfTaxis++;
    }

    char optn = 'Q';
    while(optn != 'Q' || optn != 'q'){
        cout<<grn<<"Para consultar los Taxis disponibles...presiona A"<<def<<endl;
        cout<<blu<<"Buscar Taxis por Nombre de Responsable...presiono B"<<def<<endl;
        cout<<red<<"Para Agregar un Nuevo Taxi a la lista...presiona C"<<def<<endl;
        cout<<"Terminar presiona...presiona D"<<endl;
        cin>>optn;

        switch(optn){
            case 'a':
            case 'A':{
                for(int i = 0; i < Taxi::getNumOfTaxis(); i++){
                    cout<<"---------------------------------------------------------------------"<<endl;
                    cout<<"ID Del Taxi: "<<arrTaxi[i].getID()<<endl;
                    cout<<"Nombre del Responsable: "<<arrTaxi[i].getPersona().getNombre()<<endl;
                    cout<<"Celular del Responsable: "<<arrTaxi[i].getPersona().getNumCel()<<endl;
                    cout<<"---------------------------------------------------------------------"<<endl;
                }
                cout<<endl;
            }
            break;
            case 'b':
            case 'B':{
                string rsp;
                int taxisCnResp = 0;
                cout<<"Que Responsable quieres buscar?"<<endl;
                cin.ignore();
                getline(cin, rsp);
                cout<<"ID de Taxis con el Responsable: ";
                for(int i = 0; i < numberOfTaxis; i++){
                   if(!arrTaxi[i].getPersona().getNombre().compare(rsp)){
                        taxisCnResp++;
                        cout<<" "<<arrTaxi[i].getID()<<" ";
                    } 
                }
                cout<<endl<<grn<<taxisCnResp<<def<<" taxi(s) tienen un responsable con nombre "<<blu<<rsp<<def<<endl;
            }
            break;
            case 'c':
            case 'C':{
                cout<<endl<<endl<<endl;
                if(arrTaxi[0].numOfTaxis <= 50){ 
                    cout<<"---------------------------------------------------------------------"<<endl;
                    cout<<red<<"Recuerda que hay un maximo de 50 Taxis y van: "<<Taxi::getNumOfTaxis()<<def<<endl;
                    cout<<"Agregar un nuevo Taxi con ID "<<Taxi::getNumOfTaxis()+1<<endl;
                    cout<<"Nombre del Responsable del Taxi: "<<endl;
                    cin.ignore();
                    getline(cin, nombre);
                    cout<<"Celular del Responsable: "<<endl;
                    cin.ignore();
                    getline(cin, celular);
                    Persona tmp(nombre, celular);
                    arrTaxi[arrTaxi[0].numOfTaxis] = Taxi(Taxi::getNumOfTaxis(), tmp);
                    Taxi::addToTaxis();
                    cout<<"---------------------------------------------------------------------"<<endl;
                }else{
                    cout<<red<<"Ya registraste 50 Taxis!"<<def<<endl;
                }
            }
            break;
            case'd':
            case'D': 
                exit(0);
            break;
        }
    }

    cout<<"Adios! Nos vemos pronto!"<<endl;

    return 0; 
}