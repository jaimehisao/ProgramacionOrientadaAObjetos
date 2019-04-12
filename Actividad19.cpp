#include<iostream>

using namespace std;

class Triangulo {
  protected:
    int iSide;
    int iOffsite;
    char cChar;
  public:
    Triangulo();
    Triangulo(int, char);
    void setSide(int);
    void setChar(char);
    int getSide();
    char getChar();
    void show();
};

Triangulo::Triangulo(){
  iSide = 0;
  iOffsite = 0;
  cChar = '*';
}

Triangulo::Triangulo(int iSide, char cChar){
  this->iSide = iSide;
  this->cChar = cChar;
}

void Triangulo::setSide(int iSide){
  this->iSide = iSide;
}

void Triangulo::setChar(char cChar){
  this->cChar = cChar;
}

int Triangulo::getSide(){
  return iSide;
}

char Triangulo::getChar(){
  return cChar;
}

void Triangulo::show(){
   for (int iK=1, iA=1; iK<=iSide; iK++, iA=iA+2){
    for (int iE=iSide-iK; iE>=0; iE--){
      cout << " ";
    }
    for (int iD=1; iD<=iA; iD++){
      if (iD%2==0){
        cout << " ";
      } else {
        cout << cChar;
      }
    }
    cout << endl;
  }
}

class TrianguloNombre : public Triangulo {
  protected:
    string sName;
  public:
    TrianguloNombre();
    TrianguloNombre(int, char, string);
    string getName();
    void setName(string);
    void show();
};

TrianguloNombre::TrianguloNombre() : Triangulo(){
  sName = " ";
}

TrianguloNombre::TrianguloNombre(int iS, char cChar, string sN):Triangulo(iS, cChar){
  sName = sN;
}

string TrianguloNombre::getName(){
  return sName;
}

void TrianguloNombre::setName(string sName){
  this->sName = sName;
}


void TrianguloNombre::show(){

  if (sName.length() < iSide*2-1){
    for (int iK=1, iA=1; iK<=iSide; iK++, iA=iA+2){
    for (int iE=iSide-iK; iE>0; iE--){
      cout << " ";
    }
    for (int iD=1; iD<=iA; iD++){
      if (iD%2==0){
        cout << " ";
      } else {
        cout << cChar;
      }
    }
    cout << endl;
  }
    for (int i = 0; i < ((iSide*2-1) - sName.length())/2; i++){
      cout << " ";
    }
    cout  << sName;
 } 
 
 else {
    for (int iK=1, iA=1; iK<=iSide; iK++, iA=iA+2){
    for (int iE=iSide-iK+((sName.length() - (iSide*2-1))/2); iE>0; iE--){
      cout << " ";
    }
    for (int iD=1; iD<=iA; iD++){
      if (iD%2==0){
        cout << " ";
      } else {
        cout << cChar;
      }
    }
    cout << endl;
  }
    cout  << sName;
 }


}

class TrianguloBaseNombre : public TrianguloNombre {
  protected:
  char cBase;
  public:
  TrianguloBaseNombre();
  TrianguloBaseNombre(int, char, string, char);
  char getBase();
  void setBase(char);
  void show();
};

TrianguloBaseNombre::TrianguloBaseNombre():TrianguloNombre(){
  cBase = '*';
}


int main() {
  
  TrianguloNombre t(6, '/', "Boeing");
  t.show();
  cout<<endl;

  return 0;
}

