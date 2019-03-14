/*

*/#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Start of Class Pelicula
class Pelicula{
    public:
    Pelicula();
    int getNumPeli();
    int getYear();
    int getDuracion();
    int getCantidadActores();
    int getFromListaActores(int);
    string getTitulo();
    string getGenero();

    void setNumPeli(int);
    void setYear(int);
    void setDuracion(int);
    void setTitulo(string);
    void setGenero(string);

    void muestra();

    bool agregarActor(int);


    private:
        int numPeli, year, duracion, cantidadActores;
        string titulo, genero;
        int listaActores[10];
};

Pelicula::Pelicula(){
        numPeli = 0; 
        year = 0;
        duracion = 0;
        cantidadActores = 0;
        titulo = "";
        genero = "";
}

int Pelicula::getNumPeli(){
    return numPeli;
}

int Pelicula::getYear(){
    return year;
}

int Pelicula::getDuracion(){
    return duracion;
}

int Pelicula::getCantidadActores(){
    return cantidadActores;
}

//int[] Peliculas::getListaActores();

string Pelicula::getTitulo(){
    return titulo;
}

string Pelicula::getGenero(){
    return genero;
}

void Pelicula::setNumPeli(int np){
    numPeli = np;
}

void Pelicula::setYear(int an){
    year = an;
}

void Pelicula::setDuracion(int dur){
    duracion = dur;
}

void Pelicula::setGenero(string gn){
    genero = gn;
}

void Pelicula::setTitulo(string titulo){
    this -> titulo = titulo;
}


void Pelicula::muestra(){
    cout<<"Numero de Pelicula: "<<numPeli<<endl;
    cout<<"Año: "<<year<<endl;
    cout<<"Duración: "<<duracion<<endl;
    cout<<"Cantidad de Actores: "<<cantidadActores<<endl;
}

int Pelicula::getFromListaActores(int i){
    return listaActores[i];
}

bool Pelicula::agregarActor(int id){
    bool boole = true;
    for(int i = 0; i < cantidadActores+1; i++){
        if(listaActores[i] == id || cantidadActores >= 10){
            boole = false;
        }
        }
        if(boole){
        listaActores[cantidadActores] = id;
        cantidadActores++;
        boole = true;
        }
    return boole;
}

//End of Class Peliculas


//Start of Class Actor
class Actor{  
    public:
        Actor();
        Actor(int, string);
        int getID();
        string getNombre();
        void setID(int);
        void setNombre(string);
        void muestra();
    private:
        int id;
        string nombre;
};

Actor::Actor(){
    id = 0;
    nombre = "";
}

Actor::Actor(int id, string nombre){
    this -> id = id;
    this -> nombre = nombre;
}

int Actor::getID(){
    return id;
}

string Actor::getNombre(){
    return nombre;
}

void Actor::setID(int id1){
    id = id1; 
}

void Actor::setNombre(string nm){
    nombre = nm;
}

void Actor::muestra(){
    cout<<"ID del Actor: "<<id<<endl;
    cout<<"Nombre del Actor: "<<nombre<<endl;
}
//End of Class Actor

//Start of Class Hora
class Hora{
    public:
        Hora();
        Hora(int, int);
        int getHour();
        int getMinute();
        void setHour(int);
        void setMinute(int);
        void muestra();
    private: 
        int hh, mm;
};

Hora::Hora(){
hh = 0;
mm = 0;
}

Hora::Hora(int hh, int mm){
this -> hh = hh;
this -> mm = mm;
}

int Hora::getHour(){
return hh;
}

int Hora::getMinute(){
return mm;
}

void Hora::setHour(int h){
hh = h;
}

void Hora::setMinute(int m){
mm = m;
}

void Hora::muestra(){
    cout<<hh<<":"<<mm<<endl;
}
//End of Class Hora

//Start of Class Funcion
class Funcion{
    public:
        Funcion();
        Funcion(string, int, Hora, int);
        string getClaveFuncion();
        int getNumPeli();
        Hora getHora();
        int getSala();

        void setClaveFuncion(string);
        void setNumPeli(int);
        void setHora(Hora);
        void setSala(int);

        void muestra();

    private:
        string cveFuncion;
        int numPeli;
        Hora hora;
        int sala;
};

Funcion::Funcion(){
    cveFuncion = "";
    numPeli = 0;
    sala = 0;
}

Funcion::Funcion(string cveFuncion, int numPeli, Hora hora, int sala){
    this -> cveFuncion = cveFuncion;
    this -> numPeli = numPeli;
    this -> sala = sala;
    this -> hora = hora;
}

string Funcion::getClaveFuncion(){
    return cveFuncion;
}

int Funcion::getNumPeli(){
    return numPeli;
}

Hora Funcion::getHora(){
    return hora;
}

int Funcion::getSala(){
    return sala;
}

void Funcion::setClaveFuncion(string cv){
    cveFuncion = cv;
}

void Funcion::setNumPeli(int np){
    numPeli = np;
}

void Funcion::setHora(Hora h1){
    hora = h1;
}

void Funcion::setSala(int s){
    sala = s;
}

void Funcion::muestra(){
    cout<<"Sala: "<<sala<<endl;
    cout<<"Clave de la Funcion: "<<cveFuncion<<endl;
    cout<<"Numero de Pelicula: "<<cveFuncion<<endl;
    cout<<"Hora: ";
    hora.muestra();
    cout<<endl;
}
//End of Class Funcion

//Ignore this part of the Code!
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FB_PURPLE  = 82,
        FG_YELLOW  = 51,
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
    Color::Modifier pur(Color::FB_PURPLE);
    Color::Modifier ylw(Color::FG_YELLOW);

    Actor actArr[20];
    Funcion funcionArr[20];
    Pelicula peliculaArr[20];

    int contadorActor = 0, contadorPeliculas = 0, contadorFunciones = 0;

    ifstream actorIn("/Users/hisao/Documents/GitHub/ProgramacionOrientadaAObjetosITESM/Proyecto 2/actores.txt");
    ifstream peliculasIn("/Users/hisao/Documents/GitHub/ProgramacionOrientadaAObjetosITESM/Proyecto 2/peliculas.txt");

    cout<<redb<<"Leyendo Archivos"<<defb<<endl;

     int tempActId;
     string tempActNm;
     if (actorIn.is_open()){
     while (!actorIn.eof()){
       actorIn>>tempActId;
       getline(actorIn, tempActNm);
       actArr[contadorActor].setID(tempActId);
       actArr[contadorActor].setNombre(tempActNm);
       contadorActor++;
    }
    }  
    actorIn.close();

    cout<<"Actores Leidos!!"<<endl;

    int tmpNumPeli, tmpYear, tmpDuration, tmpNumberOfActors;
    string tempGenere, tempPeliName;
    Pelicula tmp;
    if (peliculasIn.is_open()){
     while (!peliculasIn.eof()){
       peliculasIn>>tmpNumPeli>>tmpYear>>tmpDuration>>tempGenere>>tmpNumberOfActors;
        //tmp.setCantidadActores(tmpNumberOfActors);
        tmp.setNumPeli(tmpNumPeli);
        tmp.setYear(tmpYear);
        tmp.setDuracion(tmpDuration);
        tmp.setGenero(tempGenere);
       for(int i = 0; i < tmpNumberOfActors; i++){
           int tmpInt;
           peliculasIn>>tmpInt;
           tmp.agregarActor(tmpInt);
       }
       getline(peliculasIn, tempPeliName);
       tmp.setTitulo(tempPeliName);
       peliculaArr[contadorPeliculas] = tmp;
       contadorPeliculas++;
        }
    }  
    peliculasIn.close();

    cout<<"Peliculas Leidas!"<<endl<<endl<<endl;

    cout<<"Cuantas funciones quieres agregar?"<<endl;
    cin>>contadorFunciones;

    int tmpH, tmpM, tmpSala;
    string tmpCvef;
    Funcion tmpFunc;
    Hora tmpHora;
    for(int i = 0; i < contadorFunciones; i++){
        cout<<"Que clave de funcion tiene?"<<endl;
        cin>>tmpCvef;
        cout<<"Que numero de pelicula es?"<<endl;
        cin>>tmpNumPeli;
        cout<<"En que sala se va a presentar?"<<endl;
        cin>>tmpSala;
        cout<<"A que hora es? Ponlo en el formato HH espacio MM"<<endl;
        cin>>tmpH>>tmpM;
        Hora tmpHora(tmpH, tmpM);
        Funcion tmpFunc(tmpCvef, tmpNumPeli, tmpHora, tmpSala);
        funcionArr[i] = tmpFunc;
    }

    char optn = 'Q';

    while(optn != 'G' && optn != 'g'){
        cout<<"Bienvenido al la copia de IMBD!"<<endl;
        cout<<red<<"A.- Consulta de todos los Actores"<<def<<endl;
        cout<<blu<<"B.- Consulta de todas las Peliculas"<<def<<endl;
        cout<<grn<<"C.- Consulta de todas las funciones disponibles"<<def<<endl;
        cout<<red<<"D.- Consulta de peliculas por actor"<<def<<endl;
        cout<<blu<<"E.- Consulta de funciones por hora"<<def<<endl;
        cout<<grn<<"F.- Consulta por clave de funcion"<<def<<endl;
        cout<<red<<"G.- Terminar"<<def<<endl;

        cin>>optn;

        switch(optn){
            case 'a':
            case 'A':{
                for(int i = 0; i < contadorActor; i++){
                    cout<<"-------------------------------------------------------"<<endl;
                    cout<<"El ID del Actor es: "<<actArr[i].getID()<<endl;
                    cout<<"El Nombre del Actor es: "<<actArr[i].getNombre()<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
            }
            break;
            case 'b':
            case 'B':{
                for(int i = 0; i < contadorPeliculas; i++){
                    cout<<"-------------------------------------------------------"<<endl;
                    cout<<"El Titulo de la Pelicula es: "<<peliculaArr[i].getTitulo()<<endl;
                    cout<<"El Numero de Pelicula es: "<<peliculaArr[i].getNumPeli()<<endl;
                    cout<<"El Año de la Pelicula es: "<<peliculaArr[i].getYear()<<endl;
                    cout<<"El Genero de la Pelicula es: "<<peliculaArr[i].getGenero()<<endl;
                    cout<<"La duracion de la Pelicula es: "<<peliculaArr[i].getDuracion()<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
            }
            break;
            case 'c':
            case 'C':{
                for(int i = 0; i < contadorFunciones; i++){
                    cout<<"-------------------------------------------------------"<<endl;
                    cout<<"La Clave de la funcion es: "<<funcionArr[i].getClaveFuncion()<<endl;
                    cout<<"La hora de la funcion es: ";
                    funcionArr[i].getHora().muestra();
                    cout<<endl;
                    cout<<"El numero de pelicula es: "<<funcionArr[i].getNumPeli()<<endl;
                    cout<<"La sala de la pelicula es: "<<funcionArr[i].getSala()<<endl;
                    cout<<"-------------------------------------------------------"<<endl;
                }
            }
            break;
            case 'd':
            case 'D':{
                int actorCurr, cantPelis = 0;
                cout<<"Dame el ID del actor que quieres buscar..."<<endl;
                cin>>actorCurr;

                cout<<"Los resultados para el actor con el ID "<<actorCurr<<" son: "<<endl;

                for(int i = 0; i < contadorPeliculas; i++){
                    for(int j = 0; j < peliculaArr[i].getCantidadActores(); j++){
                        if(peliculaArr[i].getFromListaActores(j) == actorCurr){
                            cout<<"-------------------------------------------------------"<<endl;
                            cout<<"Pelicula: "<<peliculaArr[i].getTitulo()<<endl;
                            cout<<"-------------------------------------------------------"<<endl;
                            cantPelis++;
                        }
                    }
                }
                cout<<endl;
                cout<<"El actor con el ID: "<<actorCurr<<" sale en: "<<cantPelis<<" peluculas."<<endl;
                cout<<endl;
            }
            break;
            case 'e':
            case 'E':{
                int tmp1, tmp2;
                cout<<"Que hora de funciones quieres buscar? Pon la hora y luego el minuto eg. 10 11"<<endl;
                cin>>tmp1>>tmp2;
                Hora tmpHr(tmp1, tmp2);
                for(int i = 0; i < contadorFunciones; i++){
                    if(funcionArr[i].getHora().getHour() == tmpHr.getHour() && funcionArr[i].getHora().getMinute() == tmpHr.getMinute()){
                        cout<<"-------------------------------------------------------"<<endl;
                        for(int j = 0; j < contadorPeliculas; j++){
                            if(funcionArr[i].getNumPeli() == peliculaArr[j].getNumPeli()){
                                cout<<"Titulo de Pelicula: "<<funcionArr[i].getNumPeli()<<endl;
                                cout<<"Sala: "<<funcionArr[i].getSala()<<endl;
                            }
                        }
                        cout<<"-------------------------------------------------------"<<endl;
                            
                    }
                }
            }
            break;
            case 'f':
            case 'F':{

            }
        }
    }

    return 0;
}


/*
$$$$$$$\                         $$$$$\  $$$$$$\  $$$$$$\ $$\      $$\ $$$$$$$$\       $$\   $$\ $$$$$$\  $$$$$$\   $$$$$$\   $$$$$$\  
$$  __$$\                        \__$$ |$$  __$$\ \_$$  _|$$$\    $$$ |$$  _____|      $$ |  $$ |\_$$  _|$$  __$$\ $$  __$$\ $$  __$$\ 
$$ |  $$ |$$\   $$\ $$\             $$ |$$ /  $$ |  $$ |  $$$$\  $$$$ |$$ |            $$ |  $$ |  $$ |  $$ /  \__|$$ /  $$ |$$ /  $$ |
$$$$$$$\ |$$ |  $$ |\__|            $$ |$$$$$$$$ |  $$ |  $$\$$\$$ $$ |$$$$$\          $$$$$$$$ |  $$ |  \$$$$$$\  $$$$$$$$ |$$ |  $$ |
$$  __$$\ $$ |  $$ |          $$\   $$ |$$  __$$ |  $$ |  $$ \$$$  $$ |$$  __|         $$  __$$ |  $$ |   \____$$\ $$  __$$ |$$ |  $$ |
$$ |  $$ |$$ |  $$ |$$\       $$ |  $$ |$$ |  $$ |  $$ |  $$ |\$  /$$ |$$ |            $$ |  $$ |  $$ |  $$\   $$ |$$ |  $$ |$$ |  $$ |
$$$$$$$  |\$$$$$$$ |\__|      \$$$$$$  |$$ |  $$ |$$$$$$\ $$ | \_/ $$ |$$$$$$$$\       $$ |  $$ |$$$$$$\ \$$$$$$  |$$ |  $$ | $$$$$$  |
\_______/  \____$$ |           \______/ \__|  \__|\______|\__|     \__|\________|      \__|  \__|\______| \______/ \__|  \__| \______/ 
          $$\   $$ |                                                                                                                   
          \$$$$$$  |                                                                                                                   
           \______/                                                                                                                    
                                                                         
*/

