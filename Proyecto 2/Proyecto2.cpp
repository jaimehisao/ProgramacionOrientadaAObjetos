#include <iostream>
#include <string>

using namespace std;

class Peliculas{
    public:
    Peliculas();
    int getNumPeli();
    int getAño();
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

    private:
        int numPeli, year, duracion, cantidadActores, listaActores[10];
        string titulo, genero;
};

Peliculas::Peliculas(){

}

int Peliculas::getNumPeli(){
    return numPeli;
}

int Peliculas::getAño(){
    return año;
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


class Actor{  
    private:

    public:
        int id;
        string nombre;

};

class Hora{
    public:

    private: 
        int hh, mm;



};

class Funcion{
    public:

    private:
        string cveFuncion;
        int numPeli;
        Hora hora;
        int sala;
};



int main(){



    return 0;
}