/*
Proyecto 3 - Programacion Orientada a Objetos
Por: Jaime Hisao Yesaki Hinojosa A01720044
En este archivo estan todas las clases requeriadas por el programa, debidamente separadas en diferentes archivos.
Versión 1.2
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/****************************
*       Clase Hora          * 
****************************/
class Hora{
	public:
		Hora();
		Hora(int hora);
		Hora(int hora, int min);

		void setHora(int hora);
		void setMin(int min);

		int getHora();
		int getMin();

		void muestra();

		Hora operator+(int min);
		bool operator>=(Hora r);
		bool operator<=(Hora r);
		bool operator==(Hora r);

  private:
		int hh;//hora
		int mm;//min
};
Hora::Hora(){
	hh = 0;
	mm = 0;
}
Hora::Hora(int hora){
	hh = hora;
	mm = 0;
}
Hora::Hora(int hora, int min){
	hh = hora;
	mm = min;
}
void Hora::setHora(int hora){
	hh = hora;
}
void Hora::setMin(int min){
	mm = min;
}
int Hora::getHora(){
	return hh;
}
int Hora::getMin(){
	return mm;
}
//Sobrecarga
//+
Hora Hora::operator+(int min){
  Hora res;
  res.mm =mm +min;
  res.hh =hh;
  if(res.mm >60){
    res.hh =hh+(res.mm/60);
    res.mm =(res.mm%60);
  }
  return res;
}
//>=
bool Hora::operator>=(Hora r){
  if(hh >=r.hh){
    if(mm >=r.mm){
      return true;
    }else{
      return false;
    }
  }else{
    return false;
  }
}
//<=
bool Hora::operator<=(Hora r){
  if(hh <=r.hh){
    if(mm <=r.mm){
      return true;
      }else{
        return false;
      }
  }else{
    return false;
  }
}
//==
bool Hora::operator==(Hora r){
  if(hh ==r.hh){
    if(mm ==r.mm){
      return true;
    }else{
      return false;
    }      
  }else{
    return false;
  }
}

/****************************
*       Clase Reserva       * 
****************************/
class Reserva{
  public:
    Reserva();
    Reserva(string,int,Hora,int);

    void setClaveServicio(string);
    void setIdCliente(int);
    void setHoraInicio(Hora);
    void setDuracion(int);

    string getClaveServicio();
    int getIdCliente();
    Hora getHoraInicio();
    int getDuracion();

    Hora calculaHoraFinReservacion(Hora h1);

  private:
    string claveServicio;
    int idCliente;
    Hora horaInicio;
    int duracion;
};

//Constructores de la Clase Reserva
Reserva::Reserva(){
  claveServicio="";
  idCliente=0;
  Hora h(0,0);
  horaInicio=h;
  duracion=0; 
}

Reserva::Reserva(string CS, int iDC, Hora hHInicio, int dura){
  claveServicio=CS;
  idCliente=iDC;
  horaInicio=hhInicio;
  duracion=dura;
}

//Setters
void Reserva::setClaveServicio(string CS){
  claveServicio=CS;
}
void Reserva::setIdCliente(int iDC){
  idCliente=iDC;
}
void Reserva::setHoraInicio(Hora hhInicio){
  horaInicio=hhInicio;
}
void Reserva::setDuracion(int dura){
  duracion=dura;
}

//Getters
string Reserva::getClaveServicio(){
  return claveServicio;
}
int Reserva::getIdCliente(){
  return idCliente;
}
Hora Reserva::getHoraInicio(){
  return horaInicio;
}
int Reserva::getDuracion(){
  return duracion;
}


/****************************
*       Clase Servicio      * 
****************************/
class Servicio{
  public:
    Servicio();
    Servicio(string,int,char);
    
    void setClave(string);
    void setTiempoMax(int);
    void setTipo(char);

    string getClave();
    int getTiempoMax();
    char getTipo();

    virtual void muestra()=0;
    virtual double calculaCosto(int tiempo)=0;

  protected:
    string clave;
    int tiempoMax;
    char tipo;
};

//Constructores de la Clase Servicio
Servicio::Servicio(){
  clave="";
  tiempoMax=0;
  tipo='?';
}

Servicio::Servicio(string cLv, int time, char type){
  clave=cLv;
  tiempoMax=time;
  tipo=type;
}

//Setters
void Servicio::setClave(string cLv){
  clave=cLv;
}

void Servicio::setTiempoMax(int time){
  tiempoMax=time;
}

void Servicio::setTipo(char type){
  tipo=type;
}

//Getters
string Servicio::getClave(){
  return clave;
}

int Servicio::getTiempoMax(){
  return tiempoMax;
}

char Servicio::getTipo(){
  return tipo;
}

/****************************
*       Clase Aparato       * 
****************************/
class Aparato:public Servicio{

  public:
    Aparato();
    Aparato(double,bool,string);

    double getCostoX15min();
    bool getConInstructor();
    string getDescripcion();

    void setCostoX15min(double);
    void setConInstructor(bool);
    void setDescripcion(string);
    
    void muestra();
    double calculaCosto(int tiempo);

  private:
    double costo15m;
    bool conInstructor;
    string descripcion;
};

//Constructores de la Clase Aparato
Aparato::Aparato(){
  costo15m = 0;
  conInstructor = false;
  string descripcion = "";
}

Aparato::Aparato(double costMin,bool inst,string desc){
  costo15m = costMin;
  conInstructor = inst;
  descripcion = desc;
}

//Setters
void Aparato::setCostoX15min(double costMin){
  costo15m = costMin;
}

void Aparato::setConInstructor(bool inst){
  conInstructor = inst;
}

void Aparato::setDescripcion(string desc){
  descripcion = desc;
}

//Getters
double Aparato::getCostoX15min(){
  return costo15m;
}

bool Aparato::getConInstructor(){
  return conInstructor;
}

string Aparato::getDescripcion(){
  return descripcion;
}

//Metodo Muestra con Atributos Heredados
void Aparato::muestra(){
  cout<<"Clave: "<<clave<<endl;
  cout<<"Tiempo maximo: "<<tiempoMax<<endl;

  cout<<"Tipo de servicio: Aparato - ";
  if(tipo=='C'||tipo=='c'){
    cout<<"Caminadora"<<endl;
  }
  else if(tipo=='E'||tipo=='e'){
    cout<<"Escaladora"<<endl;
  }
  else if(tipo=='B'||tipo=='b'){
    cout<<"Bicicleta"<<endl;
  }

  cout<<"Costo: "<<costo15m<<endl;
  cout<<"Instructor: "<<conInstructor<<endl;
  cout<<"Descripcion: "<<descripcion<<endl;
}
double Aparato::calculaCosto(int tiempo){
  int x=tiempo/15;
  return x * costo15m;
}


/****************************
*       Clase Cancha        * 
****************************/
class Cancha : public Servicio{
  public:
    Cancha();
    Cancha(double,int,string);

    void setCostoPorHora(double);
    void setCantMaxPersonas(int);
    void setDeporte(string);

    double getCostoPorHora();
    int getCantMaxPersonas();
    string getDeporte();

    void muestra();
    double calculaCosto(int tiempo);

  private:
    double costoPorHora;
    int cantMaxPers;
    string deporte;
};

//Constructores de la Clase Cancha
Cancha::Cancha(){
  costoPorHora=0;
  cantMaxPers=0;
  deporte="";
}

Cancha::Cancha(double cost,int cant,string sport){
  costoPorHora=cost;
  cantMaxPers=cant;
  deporte=sport;
}

//Setters
void Cancha::setCostoPorHora(double cant){
  cantMaxPers = cant;
}

void Cancha::setCantMaxPersonas(int cost){
  costoPorHora = cost;
}

void Cancha::setDeporte(string sport){
  deporte = sport;
}

//Getters 
double Cancha::getCostoPorHora(){
  return costoPorHora;
}

int Cancha::getCantMaxPersonas(){
  return cantMaxPers;
}

string Cancha::getDeporte(){
  return deporte;
}

//Metodo Muestra con Atributos Heredados
void Cancha::muestra(){
  cout<<"Clave: "<<clave<<endl;
  cout<<"Tiempo maximo: "<<tiempoMax<<endl;

  cout<<"Tipo de servicio: Cancha - ";
  if(tipo == 'T'||tipo == 't'){
    cout<<"Tenis"<<endl;
  }
  else if(tipo == 'F'||tipo == 'f'){
    cout<<"Fronton"<<endl;
  }
  else if(tipo == 'V'||tipo == 'v'){
    cout<<"Volley Ball"<<endl;
  }

  cout<<"Costo por Hora: "<<costoXHr<<endl;
  cout<<"Cantidad de personas: "<<cantMaxPers<<endl;
  cout<<"Deporte: "<<deporte<<endl;
}

//Metodo Calcula
double Cancha::calculaCosto(int tiempo){
 int x = 0;
  x = tiempo/60;
  if(x == 0){
    x = 1;
  }
 return x * costoXHr;
}


void endProgram(){
    //Guardar Archivo, Cerrar Archivo y Terminar la Ejecución del Programa
}


//Main del Programa
int main(){

    int opcionMenu = 99;

    cout<<"Bienvenido al Sistema de Reservaciones!"<<endl;

    while(opcionMenu != 6){

    cout<<"Seleccione la Opcion deseada poniendo el numero en la consola"<<endl;
    cout<<"1.- Consultar la lista de servicios"<<endl;
    cout<<"2.- Consultar la lista de reservaciones"<<endl;
    cout<<"3.- Consultar las reservaciones de un servicio en particular"<<endl;
    cout<<"4.- Consultar las reservaciones de una hora especifica"<<endl;
    cout<<"5.- Hacer una reservación"<<endl;
    cout<<"6.- Terminar"<<endl;

    cin>>opcionMenu;

    switch(opcionMenu){
        case 1:
        break;
        case 6:
        endProgram();
        break;




    }

    }
    return 0;
}