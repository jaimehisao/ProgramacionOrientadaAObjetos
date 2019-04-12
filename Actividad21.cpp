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
    MaterialDeLectura();
    virtual void muestra() = 0;
    void setAutor(string);
    void setTitulo(string);
    string getTitulo();
    string getAutor();
    protected:
        string titulo, autor;

};

MaterialDeLectura::MaterialDeLectura(){
    titulo = "";
    autor= "";
}

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
    cout<<"El titulo es: "<<titulo<<" y el autor es: "<<autor<<endl;
}

class Libro : public MaterialDeLectura{
    protected:
        string editorial;
        int numeroDePags;
    public:
        Libro();
        void muestra();
        void setEditorial(string);
        string getEditorial();
        void setNumPags(int);
        int getNumPags();
};

Libro::Libro(){
    titulo = "";
    autor= "";
    editorial = "";
    numeroDePags = 0;
}

void Libro::muestra(){
     MaterialDeLectura::muestra();
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
        TutorialElectronico();
        TutorialElectronico(string , string, string, string);
        void setFechaActualizacion(string);
        string getFechaActualizacion();
        void setURL(string);
        string getURL();
};

TutorialElectronico::TutorialElectronico(){
    titulo = "";
    autor= "";
    fechaDeActualizacion= ""; 
    url= "";
}

TutorialElectronico::TutorialElectronico(string titulo, string autor, string url, string fechaDeActualizacion){
    this -> titulo = titulo;
    this -> autor = autor;
    this -> fechaDeActualizacion= fechaDeActualizacion; 
    this -> url = url;
}

void TutorialElectronico::muestra(){
    MaterialDeLectura::muestra();
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

void agregaTutorial(MaterialDeLectura *arr[], int &iCont){
  string sTitle, sAuthor, sURL, sUpdate;
  cout << "Titulo: ";
  cin.ignore();
  getline(cin, sTitle);
  cout << "Autor: ";
  cin.ignore();
  getline(cin, sAuthor);
  cout << "URL: ";
  cin.ignore();
  getline(cin, sURL);
  cout << "Actualizacion: ";
  cin.ignore();
  getline(cin, sUpdate);
  TutorialElectronico e(sTitle, sAuthor, sURL, sUpdate);
  arr[iCont] = &e;
  iCont++;
}

int main(){

    int numOf, optn, iCont = 0;
    
    cout<<"Bienvenido al programa de Bibliografia..."<<endl;
    cout<<"Cuantas bilbiografias quieren hacer?"<<endl;
    
    cin>>numOf;

    MaterialDeLectura* arr[100];

    for(int i = 0; i < numOf; i++){
        string temp;
        int tmpint;

        cout<<"El libro es un Tutorial (1) o Libro (2)"<<endl;
        cin>>optn;

        if(optn == 1){
            agregaTutorial(arr, iCont);
            /* string tTitulo, tAutor, tURL, tFecha;
            cout<<"Cual es el titulo?"<<endl;
            cin.ignore();
            getline(cin,tTitulo);
            cout<<"Cual es el Autor"<<endl;
            getline(cin,tAutor);
            cout<<"Cual es el URL?"<<endl;
            cin.ignore();
            getline(cin,tURL);
            cout<<"Cual es la Fecha de Actualizcion?"<<endl;
            //cin.ignore();
            cin>>tFecha;
            TutorialElectronico tmp1(tTitulo, tAutor, tURL, tFecha);
            arr[i] = &tmp1; */
        }else{
            Libro tmp2;
            tmp2 = Libro();
            arr[i] = &tmp2;
            cout<<"Cual es el titulo?"<<endl;
            cin.ignore();
            getline(cin,temp);
            tmp2.setTitulo(temp);
            cout<<"Cual es el Autor"<<endl;
            getline(cin,temp);
            tmp2.setAutor(temp);
            cout<<"Cual es la editorial del libro?"<<endl;
            getline(cin,temp);
            tmp2.setEditorial(temp);
            cout<<"Cuantas paginas tiene el libro?"<<endl;
            cin>>tmpint;
            tmp2.setNumPags(tmpint);
        }
    }


    for(int i = 0; i < iCont; i++){
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"La bibliografía utilizada para realizar la investigación es:"<<endl;
        //arr[i] -> getTitulo();
        arr[i] -> muestra();
        //cout<<arr[i];
        cout<<"-----------------------------------------------------------------------"<<endl;
    }
    
    return 0;
}