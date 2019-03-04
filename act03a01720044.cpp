#include<iostream>
#include<string>
#include <locale>

using namespace std;

int main(){

   // ******EJERCICIO #1***********

    // string theWord;
    // getline(cin,theWord);
    // string fraseOriginal = theWord;

    // bool isPalindrome = true;

    // for(int i = 0; i < theWord.length()-1; i++){
    //     if(theWord[i+1] == ' '){
    //         theWord.erase(i+1,1);
    //     }
    // }

    // int j = theWord.length()-1;
    // for(int i = 0; i < theWord.length(); i++){
    //     if(tolower(theWord[i]) != tolower(theWord[j])){
    //         isPalindrome = false;
    //         j--;
    //     }else{
    //         isPalindrome = true;
    //         j--;
    //     }
    // }


    // if(isPalindrome){
    //     cout<<"La frase "<<fraseOriginal<<" SI es palindrome"<<endl;
    // }else{
    //     cout<<"La frase "<<fraseOriginal<<" NO es palindrome"<<endl;
    // }



     // ******EJERCICIO #2***********

    // string frase, fraseFinal;
    // cout<<"Favor de Teclear una Frase..."<<endl;
    // getline(cin, frase);

    // if(frase[0] != ' '){
    //     fraseFinal = frase[0];
    // }

    // for(int i = 0; i < frase.length(); i++){
    //     if((frase[i] == ' ' && frase[i+1] != ' ') ){
    //         fraseFinal += frase[i+1];
    //     }
    // }

    // cout<<"La frase resultante es... "<<fraseFinal<<endl;

    // ******EJERCICIO #3***********

    // string frase, frase2;
    // getline(cin, frase);

    // for(int i = frase.length(); i > 0; i--){
    //     if(frase[i] == ' '){
    //         frase2 = frase.substr(i+1);
    //         cout<<frase2<<" ";
    //         frase.erase(i);
    //     }else if(i == 0){
    //         frase2 = frase.substr(i);
    //         cout<<frase2<<" ";
    //     }
    // }


    // ******EJERCICIO #4***********

//     string frase4, palabra4;
//     int longF4, position;

//     cout<<"Inserte una palabra..."<<endl;
//     getline(cin,frase4);

//      cout<<"Inserte una palabra..."<<endl;
//     getline(cin,palabra4);


//    do{
//        position = frase4.find(palabra4);
//        if(position != -1){
//            frase4.erase(position, palabra4.length());
//            frase4.insert(position,"*");
//        }

//    }while(position != -1);
    

// ******EJERCICIO #4***********

    // string frase5;
    // string fraseABuscar;
    // string toReplace = "*";

    // getline(cin, frase5);
    // cin>>fraseABuscar;

	// int pos = frase5.find(fraseABuscar);
    // while( pos != string::npos){
	// 	frase5.replace(pos, fraseABuscar.size(), toReplace);
	// 	pos = frase5.find(fraseABuscar, pos + toReplace.size());
	// }
    
    // cout<<frase5;


// ******EJERCICIO #5***********

    string theStringRec;
    bool isFloat = true;

    cin>>theStringRec;

    for(int i = 0; i<theStringRec.size(); i++){
    if (!isdigit(theStringRec[i])) {
        if(theStringRec[i] == '.'){
            isFloat = true;
        }else{
         isFloat = false;   
        }
            }
    }

    if(isFloat){
        cout<<"Si Es Float";
    }else{
        cout<<"No Es Float";
    }

// ******EJERCICIO #6***********

    // string  wordWithSpaces;
    // getline(cin, wordWithSpaces);

    // while(wordWithSpaces[0] == ' '){
    //     wordWithSpaces.erase(0,1);
    // }

    // int sizeWord = wordWithSpaces.size();

    // for(int i = 0; i < sizeWord+1; i++){
    //     if(wordWithSpaces[i] == ' ' && wordWithSpaces[i+1] == ' ' ){
    //         wordWithSpaces.erase(i,1);
    //         i--;
    //     }
    // }

    // cout<<wordWithSpaces;


    return 0;
}
