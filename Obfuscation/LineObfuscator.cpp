#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <time.h>
#include <conio.h>
#include "LineObfuscator.h"
using namespace std;

void LineObfuscator::obfuscate(string filename){
     string name = filename;
     char fileName[10];
     strcpy(fileName, name.c_str()); // convert c++ string to char*
     string*s = this->parseFile(fileName);
        this->findForAndInt(s);
        int k = 0;
        while(s[k]!="lolololololo"){
            //cout<<s[k];
            k++;
        }
        
        string op = this->generateRandomVar();

        int size = this->sumNumLine(s);
        int sizeBefMain = this->sumNumLineBeforeMain(s);
        
        int i;
        int newInt=sizeBefMain+1;
        string*s1 = new string[size+3];
        int numR=rand()%(size-newInt-1)+newInt;
        
        int randNum1=rand()%1000;
        int randNum2=rand()%1000;
        
        for(i=0 ; i<=sizeBefMain ; i++){
            s1[i]=s[i];
        }
        sizeBefMain+=1;
        s1[sizeBefMain]="int " + op + ";" + "\n";
        
        for(newInt=sizeBefMain+1 ; i<=numR ; newInt++ , i++){
            s1[newInt]=s[i];
        }
        s1[newInt]=op+ " = " + to_string(randNum1) + " + " + to_string(randNum2) + ";" + "\n" ;
        
        for(newInt+=1 ; i<=size; newInt++ , i++){
            s1[newInt]=s[i];
            }
            
        writeToFile(s1);
         
}
