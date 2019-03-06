#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Start of Class Peliculas
class Peliculas{
    public:
    Peliculas();
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

Peliculas::Peliculas(){

}

int Peliculas::getNumPeli(){
    return numPeli;
}

int Peliculas::getYear(){
    return year;
}

int Peliculas::getDuracion(){
    return duracion;
}

int Peliculas::getCantidadActores(){
    return cantidadActores;
}

//int[] Peliculas::getListaActores();

string Peliculas::getTitulo(){
    return titulo;
}

string Peliculas::getGenero(){
    return genero;
}

void Peliculas::setNumPeli(int np){
    numPeli = np;
}

void Peliculas::setYear(int an){
    year = an;
}

void Peliculas::setDuracion(int dur){
    duracion = dur;
}

void Peliculas::setCantidadActores(int cnt){
    cantidadActores = cnt;
}

void Peliculas::muestra(){
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

    cout<<"Bienvenido al la copia de IMBD!"<<endl;
    cout<<"";


    return 0;
}