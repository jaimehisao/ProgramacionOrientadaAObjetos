/*
Tarea 3.cpp -- Class Homework
This Program is a mock of a company's employee chekcing system. 
By: Jaime Hisao Yesaki Hinojosa -- A01720044 -- Use under your own risk and responsabilities
Work from: Object Oriented Programming Class at Tec de Monterrey at Campus Monterrey
*/

#include <iostream>
#include <fstream>

using namespace std;

class Employee{
public:
    Employee();

    int getID();
    double getFixedSalary();
    double getHourlySalary();
    int getWorkedHours();

    void setID(int);
    void setFixedSalary(double);
    void setHourlySalary(double);
    void setWorkedHours(int);

    void addWorkedHours(int);
    double calculateSalary();
    void seeEmployeeList(Employee);

private:

    int ID;
    double fixedSalary;
    double hourlySalary;
    int workedHours;
    
};

Employee::Employee(){
    int ID = 0;
    double fixedSalary = 0;
    double hourlySalary = 0;
    int workedHours = 0;
}

void Employee::addWorkedHours(int hours){
    workedHours += hours;
}

double Employee::calculateSalary(){
    return fixedSalary + (workedHours*hourlySalary);
}

int Employee::getID(){
return ID;
}

double Employee::getFixedSalary(){
return fixedSalary;
}

double Employee::getHourlySalary(){
return hourlySalary;
}

int Employee::getWorkedHours(){
return workedHours;
}

void Employee::setID(int id){
ID = id;
}

void Employee::setFixedSalary(double fs){
fixedSalary = fs;
}

void Employee::setHourlySalary(double hs){
hourlySalary = hs;
}

void Employee::setWorkedHours(int workedHours1){
workedHours = workedHours1;
}

bool checkID(int id, Employee arr[], int &iNum){
    bool status = false;
    for(int i = 0; i < 20; i++ ){
        if (arr[i].getID() == id){
            status = true;
            iNum = i;
        }
    }
    return status;
}



int main(){

    Employee arr[20];
    int employeeCounter = 0;

    ifstream archRead("/Users/hisao/ResilioSync/MacSync/Tec MTY/2ndo Semestre/POO:OOP/Empleados.txt");

    string frase;
    int id, hoursWorked;
    double fixedSalary, hourlySalary;

    if (archRead.is_open()){
     while (!archRead.eof()){
        archRead>>id>>fixedSalary>>hourlySalary>>hoursWorked;
        arr[employeeCounter].setID(id);
        arr[employeeCounter].setFixedSalary(fixedSalary);
        arr[employeeCounter].setHourlySalary(hourlySalary);
        arr[employeeCounter].setWorkedHours(hoursWorked);
        employeeCounter++;
    }
        
    archRead.close();

    char option = 'M';
    int idEmployeeTmp, iNumber = 0, tmp;

    while(option != 'F' && option != 'f'){
        cout<<"Bienvenido al sistema de Empleados"<<endl;
        cout<<"Presiona A para modificar un sueldo fijo"<<endl;
        cout<<"Presiona B para modificar el sueldo por hora"<<endl;
        cout<<"Presiona C para registrar horas trabajadas"<<endl;
        cout<<"Presiona D para calcular pago"<<endl;
        cout<<"Presiona E para ver lista de empleados"<<endl;
        cout<<"Presiona F para salir"<<endl;
        cin>>option;

        switch(option){
            case 'a':
            case 'A':
                do{
                cout<<"A que empleado le quieres cambiar el sueldo fijo?"<<endl;
                cin>>idEmployeeTmp;
                }while(!checkID(idEmployeeTmp, arr, iNumber));
                cout<<"El empleado con ID: "<<arr[iNumber].getID()<<" tiene el sueldo por hora de  "<<arr[iNumber].getFixedSalary()<<endl;
                cout<<"¿A que lo quieres cambiar?"<<endl;
                cin>>tmp;
                 if(!(tmp<= 1)){
                     arr[iNumber].setFixedSalary(tmp);
                }
            break;
            case 'b':
            case 'B':
                do{
                cout<<"A que empleado le quieres cambiar el sueldo fijo?"<<endl;
                cin>>idEmployeeTmp;
                }while(!checkID(idEmployeeTmp, arr, iNumber));
                cout<<"El empleado con ID: "<<arr[iNumber].getID()<<" tiene el sueldo por hora de  "<<arr[iNumber].getHourlySalary()<<endl;
                cout<<"¿A que lo quieres cambiar?"<<endl;
                cin>>tmp;
                if(!tmp<0){
                     arr[iNumber].setHourlySalary(tmp);
                }
            break;
            case 'C':
            case 'c':
                do{
                cout<<"A que empleado le quieres cambiar el sueldo fijo?"<<endl;
                cin>>idEmployeeTmp;
                }while(!checkID(idEmployeeTmp, arr, iNumber));
                cout<<"El empleado con ID: "<<arr[iNumber].getID()<<" trabaja "<<arr[iNumber].getWorkedHours()<<" horas."<<endl;
                cout<<"¿Cuantas horas de trabajo le quieres agregar?"<<endl;
                cin>>tmp;
                arr[iNumber].addWorkedHours(tmp);
            break;
            case 'D':
            case 'd':
                do{
                cout<<"A que empleado le quieres cambiar el sueldo fijo?"<<endl;
                cin>>idEmployeeTmp;
                }while(!checkID(idEmployeeTmp, arr, iNumber));
                cout<<"El sueldo actual del empleado con ID: "<<arr[iNumber].getID()<<" es de "<<arr[iNumber].calculateSalary();
            break;
            case 'e':
            case 'E':{
                cout<<"------------------------------------"<<endl;
                for(int i = 0; i < 20; i++){
                    cout<<"ID: "<<arr[i].getID()<<endl;
                     cout<<"Sueldo Fijo: "<<arr[i].getFixedSalary()<<endl;
                     cout<<"Sueldo por Horas: "<<arr[i].getHourlySalary()<<endl;
                     cout<<"Horas trabajadas: "<<arr[i].getWorkedHours()<<endl;
                     cout<<"Pago: "<<arr[i].calculateSalary()<<" MXN"<<endl;
                     cout<<"------------------------------------"<<endl;
                    } 
            }
            break;
        };
    }

    return 0;
}

}


/*

Una empresa de construcción requiere un programa para administrar las horas que trabajan sus empleados y poder calcular sus pagos. Los empleados tienen un sueldo fijo semanal por hacer actividades en la oficina. Pero además los empleados deben registrar las horas que trabajan en la construcción, las cuales se pagan de acuerdo con el sueldoPorHora que se define para cada empleado.
1. Escribe una clase Empleado que tenga:

• Como atributos:


• Los métodos necesarios para:

◦ registrar las horas trabajadas por el empleado; este método debe sumar las horas que esté registrando el empleado a las que se encuentren en el objeto (o sea las que ya había registrado antes).

◦ calcular el pago para el empleado que se calcula como: sueldo fijo + (horas trabajadas * sueldo por hora).






 

2. Crea ahora una aplicación que cree un arreglo de objetos de tipo Empleado. Supón que la cantidad máxima de empleados que habrá es 20. Luego que cargue los datos iniciales de un archivo. No es necesario validar los datos que se cargan del archivo, puedes suponer que son correctos y que siempre serán una cantidad menor o igual a 20.

En el archivo vendría en cada renglón los datos de un empleado de esta forma:

idEmpleado sueldoFijo sueldoPorHoras horasTrabajadas

Después el programa debe tener un menú con las siguientes opciones; el usuario debe poder ejecutar las opciones del menú todas las veces que quiera, el programa termina cuando el usuario de la opción terminar.

A. Modificar sueldo fijo: En esta opción se debe preguntar el id del empleado y cuál es el valor del nuevo sueldo fijo. Se debe validar que el id del empleado exista y que el sueldo fijo nuevo sea positivo.  

B. Modificar sueldo por horas : En esta opción se debe preguntar el id del empleado y cual es el valor del nuevo sueldo por horas. Se debe validar que el id del empleado exista y que el sueldo por horas nuevo sea positivo.

C. Registrar horas trabajadas:   En esta opción se debe preguntar el id del empleado y cuantas horas va a registrar. Se debe validar que el id del empleado exista y que la cantidad de horas sea positiva. Esta opción debe agregar la cantidad de horas trabajadas a la cantidad de horas que ya tenía el objeto, de manera que si el empleado originalmente había trabajado 10 hrs y registra que trabajó 16 ahora tendrá 26. 

D. Calcular pago del empleado : En esta opción el programa debe preguntar el id del empleado y debe mostrar en la pantalla el pago que le corresponde de acuerdo con las horas que ha trabajado. Se debe validar que el id del empleado exista.

E. Ver lista empleados : En esta opción el programa debe mostrar al usuario la lista de todos los empleados que hay en el arreglo de objetos con su sueldo fijo, su sueldo por horas, sus horas trabajadas y el pago que le corresponde.

F. Terminar

NOTA: En todos los casos en que se pida un id de empleado, se debe validar que exista y si no existe el programa debe indicarlo y volver a pedirlo tantas veces como el usuario se equivoque.

*/