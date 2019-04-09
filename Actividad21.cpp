/*
Actividad21.cpp  -- Actividad en Clase
Por: Jaime Hisao Yesaki Hinojosa A01720044
Fecha: 9/4/19
Version: v1.0
Esta actividad usa el polimorfismo para tener dos subclases de la superclase MaterialDeLectura,
y en el main simulamos la funcionalidad de un administrador de bilbiografia, que guarda todo en un Arreglo
que tiene el tipo de la superclase pero guarda sus derivadas (hijos).
*/

#include <iostream>
#include <string>

using namespace std;

class MaterialDeLectura{
    public: 
    void virtual muestra();
    void setAutor(string);
    void setTitulo(string);
    string getTitulo();
    string getAutor();
    protected:
        string titulo, autor;

};

string MaterialDeLectura::getTitulo(){
    return titulo;
}

void MaterialDeLectura::setTitulo(string titulo){
    this -> titulo = titulo;
}

string MaterialDeLectura::getAutor(){
    return autor;
}

void MaterialDeLectura::setAutor(string autor){
    this -> autor = autor;
}

void MaterialDeLectura::muestra(){
    cout<<"El titulo es: "<<titulo<<" y el autor es: "<<autor;
}

class Libro : public MaterialDeLectura{
    protected:
        string editorial;
        int numeroDePags;
    public:
        void muestra();
        void setEditorial(string);
        string getEditorial();
        void setNumPags(int);
        int getNumPags();
};

void Libro::muestra(){
     cout<<"El titulo es: "<<titulo<<" y el autor es: "<<autor;
     cout<<"Tiene: "<<numeroDePags<<" paginas y la editorial es: "<<editorial;
}

void Libro::setEditorial(string editorial){
    this -> editorial = editorial;
}

string Libro::getEditorial(){
    return editorial;
}

void Libro::setNumPags(int numeroDePags){
    this-> numeroDePags = numeroDePags;
}

int Libro::getNumPags(){
    return numeroDePags;
}

class TutorialElectronico : public MaterialDeLectura{
    protected:
        string fechaDeActualizacion, url;
    public:
        void muestra();
        void setFechaActualizacion(string);
        string getFechaActualizacion();
        void setURL(string);
        string getURL();

};

void TutorialElectronico::muestra(){
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Autor: "<<autor<<endl;
    cout<<"Fecha de Actualización: "<<fechaDeActualizacion<<endl;
    cout<<"URL: "<<url;
}

void TutorialElectronico::setFechaActualizacion(string fecha){
    fechaDeActualizacion = fecha;
}

string TutorialElectronico::getFechaActualizacion(){
    return fechaDeActualizacion;
}

void TutorialElectronico::setURL(string url){
    this-> url = url;
}

string TutorialElectronico::getURL(){
    return url;
}


int main(){

    int numOf, optn;
    
    cout<<"Bienvenido al programa de Bibliografia..."<<endl;
    cout<<"Cuantas bilbiografias quieren hacer?"<<endl;
    
    cin>>numOf;

    MaterialDeLectura arr[numOf];
    MaterialDeLectura tmp;

    for(int i = 0; i < numOf; i++){
        TutorialElectronico tmp1;
        Libro tmp2;
        string temp;

        cout<<"El libro es un Tutorial (1) o Libro (2)"<<endl;
        cin>>optn;

        if(optn == 1){
            tmp1 = TutorialElectronico();
            cout<<"Cual es el titulo?"<<endl;
            cin.ignore();
            getline(cin,temp);
            tmp1.setTitulo(temp);
            cout<<"Cual es el Autor"<<endl;
            getline(cin,temp);
            tmp1.setAutor(temp);
            cout<<"Cual es el URL?"<<endl;
            cin>>temp;
            tmp1.setURL(temp);
            cout<<"Cual es la Fecha de Actualizcion?"<<endl;
            cin>>temp;
            tmp1.setFechaActualizacion(temp);
        }else{
            tmp2 = Libro();
        }

        arr[i] = tmp;
    }

    for(int i = 0; i < numOf; i++){
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"La bibliografía utilizada para realizar la investigación es:"<<endl;
        arr[i].muestra();
        cout<<"---------------------------------------------------------"<<endl;
    }
    
    return 0;
}