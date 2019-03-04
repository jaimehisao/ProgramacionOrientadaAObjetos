#include <iostream>
#include <string>

using namespace std;

class Reloj{
    private:
        int hour;
        int minute;

    public:
        Reloj();
        Reloj(int h, int m);
        void setHour(int);
        void setMinute(int);
        int getHour();
        int getMinute();
        void show();
};

Reloj::Reloj(int h, int m){
    hour = h;
    minute = m;
}

Reloj::Reloj(){
    hour = 0;
    minute = 0;
}

void Reloj::setHour(int hourP){
     hour = hourP;
}

void Reloj::setMinute(int minuteP){
    minute = minuteP;
}

int Reloj::getHour(){
    return hour;
}

int Reloj::getMinute(){
    return minute;
}

void Reloj::show(){
    if(hour<9){
        std::cout<<"0"<<hour<<":";
    }else{
        std::cout<<hour<<":";
    }

    if(minute<9){
        std::cout<<"0"<<minute<<std::endl;
    }else{
        std::cout<<minute<<std::endl;
    }
}

class Evento{

    public:
    string getAsunto();
    Evento(Reloj, int, string);
    Evento();
    Reloj getHoraInicial();
    int getDuracion();

    void setHoraInicial(Reloj);
    void setDuracion(int);
    void setAsunto(string);

    private:
    int inicio, duracion;
    string asunto;
    Reloj horaInicial;
    
    


};

Evento::Evento(){
    Reloj hi(0,0);
    horaInicial = hi;
    inicio = 0;
    duracion = 0;
    asunto = "";
}

Evento::Evento(Reloj r, int d, string a){

}

Reloj Evento::getHoraInicial(){
    return horaInicial;
}

int Evento::getDuracion(){
    return duracion;
}

string Evento::getAsunto(){
    return asunto;
}

void Evento::setHoraInicial(Reloj re){
    horaInicial = re;
}

void Evento::setDuracion(int we){
    duracion = we;
}

void Evento::setAsunto(string ne){
    asunto = ne;
}


int main(){
    int numeroDeEventos;
    cout<<"Cuantos Eventos quieres crear?"<<endl;
    cin>>numeroDeEventos;
    Evento arrEventos[numeroDeEventos];
    char optn = 'F'; 
    cout<<"Bienvenido al Sistema de Eventos!"<<endl;
    int contEventos = 0;

    while(optn != 'C' && optn != 'c'){
        cout<<"Selecciona una opcion..."<<endl;
        cout<<"A.- Agregar un evento"<<endl;
        cout<<"B.- Ver Eventos"<<endl;
        cout<<"C.- Salir"<<endl;

        cin>>optn;

        string asunto;
        int hor, minu, duracion;

        switch(optn){
            case 'a':
            case 'A':{
                    cout<<"Cual es el Asunto? "<<endl;
                    cin.ignore();
                    getline(cin, asunto);
                    cout<<"Cual es la hora inicial...dame la hora primero?"<<endl;
                    cin>>hor;
                    cout<<"Dame los minutos"<<endl;
                    cin>>minu;
                    cout<<"Cual es la duracion del evento: ";
                    cin>>duracion;
                    arrEventos[contEventos].setAsunto(asunto);
                    arrEventos[contEventos].setDuracion(duracion);
                    arrEventos[contEventos].setHoraInicial(Reloj(hor, minu));
                    contEventos++;
                    break;
            }
            case 'b':
            case 'B':{
                for(int i = 0; i < numeroDeEventos; i++){
                    cout<<"----------------------------------------------------------------------"<<endl;
                    cout<<"El Asunto es: "<<arrEventos[i].getAsunto()<<endl;
                    cout<<"La hora inicial es: "<<arrEventos[i].getHoraInicial().getHour()<<":"<<arrEventos[i].getHoraInicial().getMinute()<<endl;
                    cout<<"La duracion es: "<<arrEventos[i].getDuracion()<<endl;
                     cout<<"----------------------------------------------------------------------"<<endl;
                }
                break;
            }
        };
    }
    cout<<"Adios!"<<endl;
    return 0;
}