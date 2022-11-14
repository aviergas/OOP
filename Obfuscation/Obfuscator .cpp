#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include "Obfuscator.h"
using namespace std;


 string Obfuscator::generateRandomVar(){
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
 
        string res = "";
        int num = rand()%5+4;
        for (int i = 0; i <num ; i++)
            res = res + alphabet[rand() % MAX];
        return res;
}

    string* Obfuscator::parseFile(string filename){
        string name = filename;
        char fileName[15];
        strcpy(fileName, name.c_str()); // convert c++ string to char*
        FILE* f = fopen(fileName, "r");
        if(f==NULL)
        {
            cout<<"cannot open first"<<endl;
        }
        char s[100];
        int count = 0;
        while(fgets(s, 100, f)) {
            count++;
        }
        fclose(f);
        FILE* f2=fopen(fileName , "r");
        if(f2==NULL)
        {
            cout<<"cannot open second"<<endl;
        }
        string* str=new string[count+1];
        int i = 0;
        while(fgets(s, 100, f2)) {   // read the file line by line
            str[i]=s;
            //cout<<str[i];
            i++;
        }
    str[count]="lolololololo";//stop line 
            fclose(f2);

    return str;
    }
    
    void Obfuscator::writeToFile(string* codeArray){
        ofstream outfile;
        outfile.open(OUT);
        int i=0;
        while(codeArray[i]!="lolololololo"){ // stop line
            outfile<<codeArray[i];
            i++;
        }  
        outfile.close();
    }
    
    int Obfuscator::sumNumLine(string* codeArray){
        int count = 0;
        int i = 0;
        while(codeArray[i]!="lolololololo"){ // stop line
            i++;  
            count++;    
        }
        return count;  
    }
    
    int Obfuscator::sumNumLineBeforeMain(string* codeArray){
        int count = 0;
        string main ="main()";
        int i;
        int found;
        for(i=0;codeArray[i]!="lolololololo";i++){
            found = codeArray[i].find(main);
                if(found!=string::npos)
                    break;
                    count++;
            //cout<<codeArray[i];
          }
        return count;
        }
        
    int Obfuscator::findLineWithInt(string*codeArray){
        int count = 0;
        string int1 = "int";
        int j = sumNumLineBeforeMain(codeArray);
        int i; 
        int found;
            for(i=j;i<j+3;i++){
            found = codeArray[i].find(int1);
                if(found!=string::npos)
                    count++;
            //cout<<codeArray[i];
          }
        return count;
    }    
    
    string Obfuscator::randomString(){
        string* s = new string [3];
        s[0]="//change the words right now!@#$@#$";
        s[1]="//stop doing that!@#^$$#";
        s[2]="//this work is soo harddd !!!!@##$!@@##!@#";
         
        int num = rand()%2;
        return s[num];
    }
    
    int Obfuscator::findLenWord(int foundInt , string sentence){
        int i = 0 ;
        int count = 0;
    int foundNek=sentence.find(";");
    string sentenceWithOutInt = sentence.substr(foundInt,foundNek);
    foundNek=sentenceWithOutInt.find(";");
    int f=sentenceWithOutInt.find(" ");
    int f1=sentenceWithOutInt.find("=");

    if(f>f1)
        return f;
    else if(f1>f)
        return f1;
    else if(f1==-1&&f==-1)
        return foundNek;
    else
        return -1;
        
    }
    void Obfuscator::findForAndInt(string*codeArray){
            int i;
            string if1 = "if(" ;
            string for2 = "for(" ;
            string while3 = "while(";
            string else4 = "else(";
            string else5 = "else";
            int found1;
            int found2;
            int found3;
            int found4;
            int found5;
            int foundOpen;
            for(i=0;codeArray[i]!="lolololololo";i++){
                found1 = codeArray[i].find(if1);
                found2 = codeArray[i].find(for2);
                found3 = codeArray[i].find(while3);
                found4 = codeArray[i].find(else4);
                found5 = codeArray[i].find(else5);
                if(found1!=string::npos){
                    foundOpen = codeArray[i].find("{");
                    if(foundOpen!=string::npos);
                    else{
                        codeArray[i]=codeArray[i]+"{"+"\n" ;
                        codeArray[i+1]=codeArray[i+1]+"}"+"\n" ;
                    }
                }
                else if(found2!=string::npos){
                    foundOpen = codeArray[i].find("{");
                    if(foundOpen!=string::npos);
                    else{
                        codeArray[i]=codeArray[i]+"{"+"\n";
                        codeArray[i+1]=codeArray[i+1]+"}"+"\n";
                    }
                }
                else if(found3!=string::npos){
                    foundOpen = codeArray[i].find("{");
                    if(foundOpen!=string::npos);
                    else{
                        codeArray[i]=codeArray[i]+"{"+"\n" ;
                        codeArray[i+1]=codeArray[i+1]+"}"+"\n" ;
                    }
                }
                else if(found4!=string::npos){
                    foundOpen = codeArray[i].find("{");
                    if(foundOpen!=string::npos);
                    else{
                        codeArray[i]=codeArray[i]+"{"+"\n" ;
                        codeArray[i+1]=codeArray[i+1]+"}"+"\n" ;
                    }
                }
                else if(found5!=string::npos){
                    foundOpen = codeArray[i].find("{");
                    if(foundOpen!=string::npos);
                    else{
                        codeArray[i]=codeArray[i]+"{"+"\n" ;
                        codeArray[i+1]=codeArray[i+1]+"}"+"\n" ;
                    }
                }
                else{}
        }
    }
    
    