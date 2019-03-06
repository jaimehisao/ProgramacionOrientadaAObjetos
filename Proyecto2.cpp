#include <iostream>
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
    //int[] getListaActores();
    string getTitulo();
    string getGenero();

    void setNumPeli(int);
    void setYear(int);
    void setDuracion(int);
    void setCantidadActores(int);
    void setTitulo(string);
    void setGenero(string);

    void muestra();

    private:
        int numPeli, year, duracion, cantidadActores, listaActores[10];
        string titulo, genero;
};

Pelicula::Pelicula(){

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

void Pelicula::setCantidadActores(int cnt){
    cantidadActores = cnt;
}

void Pelicula::muestra(){
    cout<<"Numero de Pelicula: "<<numPeli<<endl;
    cout<<"Año: "<<year<<endl;
    cout<<"Duración: "<<duracion<<endl;
    cout<<"Cantidad de Actores: "<<cantidadActores<<endl;
}
//End of Class Peliculas


//Start of Class Actor
class Actor{  
    public:
        int getID();
        string getNombre();
        void setID(int);
        void setNombre(string);
        void muestra();
    private:
        int id;
        string nombre;
};

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

Hora::Hora(int h, int m){
hh = h;
mm = m;
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

Funcion::Funcion(string cve, int np, Hora hora1, int s){
    cveFuncion = cve;
    numPeli = np;
    sala = s;
    hora = hora1;
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

int main(){

    Actor actArr[20];
    Funcion funcionArr[20];
    Pelicula peliculaArr[20];

    int contadorActor = 0, contadorPeliculas = 0;

    ifstream actorIn("Proyecto 2/actores.txt");
    ifstream peliculasIn("Proyecto 2/peliculas.txt");

     int tempActId;
     string tempActNm;
     if (actorIn.is_open()){
     while (!actorIn.eof()){
       actorIn>>tempActId;
       getline(cin, tempActNm);
       actArr[contadorActor].setID(tempActId);
       actArr[contadorActor].setNombre(tempActNm);
       contadorActor++;
    }
    }  
    actorIn.close();

    int tmpNumPeli, tmpYear, tmpDuration, tmpNumberOfActors;
    string tempGenere, tempPeliName;
    if (peliculasIn.is_open()){
     while (!peliculasIn.eof()){
       peliculasIn>>tmpNumPeli>>tmpYear>>tmpDuration>>tempGenere>>tmpNumberOfActors;

       for(int i = 0; i < tmpNumberOfActors; i++){

       }
       getline(cin, tempPeliName);
       

    


       contadorPeliculas++;
    }
    }  
    peliculasIn.close();

    cout<<"Bienvenido al la copia de IMBD!"<<endl;
    cout<<"";


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