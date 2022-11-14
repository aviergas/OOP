#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <time.h>
#include <conio.h>
#include "CommentObfuscator.h"
using namespace std;

void CommentObfuscator::obfuscate(string filename){
    string name = filename;
    char fileName[10];
    strcpy(fileName, name.c_str()); // convert c++ string to char*
    string*s3 = this->parseFile(fileName);
    int size = sumNumLine(s3);
    int i=0;
    string word = "//";
    int found;
    while(s3[i]!="lolololololo"){
        found = s3[i].find(word);
        if(found!=string::npos){
           s3[i]=randomString()+"\n";
        }
        i++;
    }
    writeToFile(s3);
}

    
