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
		int hh; //Variable Hora
		int mm;//Variable Minuto
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

//Sobrecarga de Operadores de la Clase Hora
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
    Reserva(string, int, Hora, int);

    void setClaveServicio(string);
    void setIdCliente(int);
    void setHoraInicio(Hora);
    void setDuracion(int);

    string getClaveServicio();
    int getIdCliente();
    Hora getHoraInicio();
    int getDuracion();

    Hora calculaHoraFinReservacion(Hora);

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

Reserva::Reserva(string claveServicio, int idCliente, Hora horaInicio, int duracion){
  this -> claveServicio = claveServicio;
  this -> idCliente = idCliente;
  this -> horaInicio = horaInicio;
  this -> duracion = duracion;
}

//Setters
void Reserva::setClaveServicio(string claveServicio){
  this -> claveServicio = claveServicio;
}

void Reserva::setIdCliente(int idCliente){
  this -> idCliente = idCliente;
}

void Reserva::setHoraInicio(Hora horaInicio){
  this -> horaInicio = horaInicio;
}

void Reserva::setDuracion(int duracion){
  this -> duracion = duracion;
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

Servicio::Servicio(string clave, int tiempoMax, char tipo){
  this -> clave = clave;
  this -> tiempoMax = tiempoMax;
  this -> tipo = tipo;
}

//Setters
void Servicio::setClave(string clave){
  this -> clave = clave;
}

void Servicio::setTiempoMax(int tiempoMax){
  this -> tiempoMax = tiempoMax;
}

void Servicio::setTipo(char tipo){
  this -> tipo = tipo;
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
void Aparato::setCostoX15min(double costo15m){
  this -> costo15m = costo15m;
}

void Aparato::setConInstructor(bool conInstructor){
  this -> conInstructor = conInstructor;
}

void Aparato::setDescripcion(string descripcion){
  this -> descripcion = descripcion;
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
  int x = tiempo/15;
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

Cancha::Cancha(double costoPorHora,int cantMaxPers, string deporte){
  this -> costoPorHora = costoPorHora;
  this -> cantMaxPers = cantMaxPers;
  this -> deporte = deporte;
}

//Setters
void Cancha::setCostoPorHora(double cantMaxPers){
  this -> cantMaxPers = cantMaxPers;
}

void Cancha::setCantMaxPersonas(int costoPorHora){
  this -> costoPorHora = costoPorHora;
}

void Cancha::setDeporte(string deporte){
  this -> deporte = deporte;
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

  cout<<"Costo por Hora: "<<costoPorHora<<endl;
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
 return x * costoPorHora;
}


//!Methods for Main

void endProgram(){
    //Guardar Archivo, Cerrar Archivo y Terminar la Ejecución del Programa
}


//Main del Programa
int main(){

    //Class Variable Declarations
    int opcionMenu = 99;
    Servicio *arrServicios[20];
    Reserva *arrReserva[20];

    int serviciosCont = 0;
    int reservaCont = 0;

    //Start the program by reading the files, if the files doen't exist, notify the user and create them accordingly.
    ifstream reservaRead("/Users/hisao/Documents/GitHub/ProgramacionOrientadaAObjetosITESM/Proyecto 3/Reserva.txt"); //Directory Relative to Project Path
    ifstream servicioRead("/Users/hisao/Documents/GitHub/ProgramacionOrientadaAObjetosITESM/Proyecto 3/Servicios.txt"); //Directory Relative to Project Path

    //Variable Declarations for the Reservations File
    string claveServicio;
    Hora horaObj;
    int minutos, hora, tiempoEnMinutos, idCliente;

    //Loop to Read the File 
    while(!reservaRead.eof()){
        reservaRead>>claveServicio;
        reservaRead>>hora;
        reservaRead>>minutos;
        reservaRead>>tiempoEnMinutos;
        reservaRead>>idCliente;

        Hora tmpHora(hora, minutos);
        Reserva* tmpReserva = new Reserva(claveServicio, idCliente, tmpHora, tiempoEnMinutos);
        arrReserva[reservaCont] = tmpReserva;
        reservaCont++;
        cout<<"Reserva #"<<reservaCont<<" Agregada!"<<endl;

    }

    reservaRead.close();

    //Variable Declarations for the Servicio File, which can be of type cancha or aparato, depending on the first char
    string typeChooser;
    //Type Aparato
    string clave;     
    int tiempoMax;
    char tipo;
    double costoX15min;
    bool conInstructor;
    string descripcion;
  
    //Type Cancha
    string clave2;     
    int tiempoMax2;
    char tipo2;
    double costoXHr;
    int cantMaxPers;
    string deporte;

    //Loop to Read the Service File
    while(!servicioRead.eof()){
        servicioRead>>typeChooser;
        if(typeChooser[0] == 'C' || typeChooser[0] =='E' || typeChooser[0] =='B'){   
            servicioRead>>tiempoMax;
            servicioRead>>tipo;
            servicioRead>>costoX15min;
            servicioRead>>conInstructor;
            servicioRead.clear();
            getline(servicioRead, descripcion);
            Aparato* tmpAparato = new Aparato(costoX15min, conInstructor, descripcion);
            arrServicios[serviciosCont] = tmpAparato;
            cout<<"Servicio Tipo 1 #"<<serviciosCont<<" Agregado!"<<endl;
            serviciosCont++;
        }else if(typeChooser[0] == 'T' || typeChooser[0] =='F' || typeChooser[0] =='V'){    
            servicioRead>>tiempoMax2;
            servicioRead>>tipo2;
            servicioRead>>costoXHr;
            servicioRead>>cantMaxPers;
            servicioRead.clear();
            getline(servicioRead, deporte);
            Cancha* tmpCancha = new Cancha(costoXHr, cantMaxPers, deporte);
            arrServicios[serviciosCont] = tmpCancha;
            cout<<"Servicio Tipo 2 #"<<serviciosCont<<" Agregado!"<<endl;
            serviciosCont++;
        }
    }

    reservaRead.close();


    

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
        case 1:{ //Mostrar todos los servicios
        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        for(int i = 0; i < serviciosCont; i++){
          arrServicios[i] -> muestra();
          cout<<"-------------------------------------------------------------------------------------------"<<endl;
        }
        break;
        }
        case 2:{ //Consulta de la Lista de Reservaciones (Mostrar Clave, ID, Hora de inicio y fin, y el costo)
        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        for(int i = 0; i < reservaCont; i++){
          arrReserva[i] -> getClaveServicio();
          arrReserva[i] -> getIdCliente();
          arrReserva[i] -> getHoraInicio();
          arrReserva[i] -> calculaHoraFinReservacion();
          arrReserva[i] -> calculaCosto();
          cout<<"-------------------------------------------------------------------------------------------"<<endl;
        }
          break;
        }
        case 3:{ 
          //Consulta las Reservaciones de un servicio dado (Pide ID del servicio y muestra datos, y muestra la hora
          //inicial y final basado en las reservaciones existentes

          break;
        }
        case 4:{
          //Consulta de Reservaciones dada una Hora (h y m), muestra los servicios reservados usando el mtd muestra

          break;
        }
        case 6:
        endProgram();
        break;




    }

    }
    return 0;
}