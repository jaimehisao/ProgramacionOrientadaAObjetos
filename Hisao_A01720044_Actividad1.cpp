#include<iostream>

int main(){

    //Actividad 1

   std::cout<<"Dame 5 datos para llenar el arreglo..."<<std::endl;

   double arr[5];

   for(int i = 0; i < 5; i++){
       std::cin>>arr[i];
   }

    //Actividad 2

    std::cout<<"Cuantos elementos quieres agregar al arreglo?"<<std::endl;

    int n;
    std::cin>>n;
    double arr2[n];

   for(int i = 0; i < n; i++){
       std::cin>>arr2[i];
   }

   //Actividad 3

     std::cout<<"Cuantos elementos quieres agregar al arreglo?"<<std::endl;

    int n2;
    std::cin>>n2;
    double arr3[n2];
    double avg = 0;
    int temp;

   for(int i = 0; i < n2; i++){
       std::cin>>temp;
       arr3[i] = temp;
       avg += temp;
   }
    avg = avg/n2;

    std::cout<<"El promedio es..."<<avg<<std::endl;


    return 0;
}

