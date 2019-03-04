#include <iostream>
#include <string>

using namespace std;

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

class Computadora{
    public:
        Computadora();
        string getMarca();
        int getRam();
        string getSistemaOperativo();

        void setMarca(string);
        void setRam(int);
        void setSistemaOperativo(string);

    private:
        string _marca;
        int _ram;
        string _sistemaOperativo;

};

Computadora::Computadora(){
    _marca = "";
    _ram = 0;
    _sistemaOperativo = "";
}

string Computadora::getMarca(){
    return _marca;
    }

int Computadora::getRam(){
    return _ram;
    }

string Computadora::getSistemaOperativo(){
    return _sistemaOperativo;
    }

void Computadora::setMarca(string mc){
      _marca = mc;
    }

void Computadora::setRam(int rm){
    _ram = rm;
    }

void Computadora::setSistemaOperativo(string st){
    _sistemaOperativo = st;
    }

class Salon{
    public:
        Salon();
        int getNumeroDeSalon();
        Computadora getComputadora();
    
        void setNumeroDeSalon(int);
        void setComputadora(Computadora);
    private:
        int _numeroSalon;
        Computadora _comp;
};

Salon::Salon(){
    _numeroSalon = 0;
    Computadora comp();
}
int Salon::getNumeroDeSalon(){
    return _numeroSalon;
}

Computadora Salon::getComputadora(){
    return _comp;
}

void Salon::setNumeroDeSalon(int ns){
    _numeroSalon = ns;
}

void Salon::setComputadora(Computadora cp){
    _comp = cp;
}


int main(){
    Color::Modifier red(Color::FG_RED);
    Color::Modifier grn(Color::FG_GREEN);
    Color::Modifier def(Color::FG_DEFAULT);
    Color::Modifier blu(Color::FG_BLUE);

    Salon arr[10];
    int numeroDeSalones = 0;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Bienvenidos al Sistema de Salones!"<<endl;
    cout<<"No hay salones registrados, por lo que tendras que registrar uno"<<endl;
    cout<<"¿Cuantos salones quieres? ";
    cout<<red<<"Recuerda que hay un maximo de 10 salones"<<def<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cin>>numeroDeSalones;

    int ram, numeroDeSalon;
    string sysOp, marca;
    for(int i = 0; i < numeroDeSalones; i++){
        cout<<"Dame el numero del salón"<<endl;
        cin>>numeroDeSalon;
        cout<<"¿Qué marca es la computadora?"<<endl;
        cin>>marca;
        cout<<"¿Que sistema Operativo tiene la computadora?"<<endl;
        cin.ignore();
        getline(cin, sysOp);
        cout<<"¿Cuanto RAM tiene la computadora?"<<endl;
        cin>>ram;
        arr[i].getComputadora().setRam(ram);
        arr[i].getComputadora().setMarca(marca);
        arr[i].getComputadora().setSistemaOperativo(sysOp);
        arr[i].setNumeroDeSalon(numeroDeSalon);
    }

    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

    char optn = 'Q';
    while(optn != 'Q' || optn != 'q'){
        cout<<"Buscar por Marca...presiona A"<<endl;
        cout<<"Buscar por Sistema Operativo...presiono B"<<endl;
        cout<<"Listar Salones...presiona C"<<endl;
        cout<<"Terminar presiona...presiona D"<<endl;
        cin>>optn;

        switch(optn){
            case 'a':
            case 'A':{
                string mrc;
                int salonesConMrc = 0;
                cout<<"Que marca quieres buscar?"<<endl;
                cin>>mrc;
                cout<<"Salones: ";
                for(int i = 0; i < numeroDeSalones; i++){
                   if(arr[i].getComputadora().getMarca().compare(mrc)){
                        salonesConMrc++;
                        cout<<" "<<arr[i].getNumeroDeSalon()<<" ";
                    } 
                }
            }
            break;
            case 'b':
            case 'B':{
                cout<<"Que sistema operativo quieres buscar?"<<endl;
                string sysOp;
                cin>>sysOp;
                int salonesConSys = 0;
                cout<<"Salones: ";
                for(int i = 0; i < numeroDeSalones; i++){
                    if(arr[i].getComputadora().getSistemaOperativo().compare(sysOp)){
                        salonesConSys++;
                        cout<<arr[i].getNumeroDeSalon()<<" ";
                    }
                }
                cout<<endl<<grn<<salonesConSys<<def<<" salon(es) tienen computadoras con el sistema operativo "<<blu<<sysOp<<def<<endl;
            }
            break;
            case 'c':
            case 'C':{
                for(int i = 0; i < numeroDeSalones; i++){
                    cout<<"---------------------------------------------------------------------"<<endl;
                    cout<<"Numero de Salón: "<<arr[i].getNumeroDeSalon()<<endl;
                    cout<<"Marca Computadora de Salón: "<<arr[i].getComputadora().getMarca()<<endl;;
                    cout<<"Sistema Operativo de la Computadora: "<<arr[i].getComputadora().getSistemaOperativo()<<endl;;
                    cout<<"RAM de la Computadora: "<<arr[i].getComputadora().getRam()<<endl;;
                    cout<<"---------------------------------------------------------------------"<<endl;
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