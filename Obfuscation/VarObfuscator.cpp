#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <time.h>
#include <conio.h>
#include "VarObfuscator.h"
using namespace std;

void VarObfuscator::obfuscate(string filename){
    string name = filename;
    char fileName[10];
    strcpy(fileName, name.c_str()); // convert c++ string to char*
    string*s2 = this->parseFile(fileName);
    int size = sumNumLine(s2);  
    int countInt = this->findLineWithInt(s2);
    int randInt = rand()%countInt+(this->sumNumLineBeforeMain(s2)+1);
    
    
    string op1 = this->generateRandomVar();
    
    int i; 
    string word = "int";
    int foundInt;
    int foundNek;
    foundInt=s2[randInt].find(word);
    foundNek=s2[randInt].find(";");
    
    
    
    string wordReplace = s2[randInt].substr(foundInt+4,(this->findLenWord(foundInt+4,s2[randInt]))-1);

    s2[randInt].replace(foundInt+4,wordReplace.length(),op1);  
    
    if(wordReplace.find("=")){
        string wordReplaceNew = wordReplace.substr(0,wordReplace.find("="));
        wordReplace = wordReplaceNew;
        }
        
    int foundWordReplace;
    int count=0;
    string testSentence;
    for(i=randInt+1 ; i<size ;i++){
          foundWordReplace = s2[i].find(wordReplace);
         if(foundWordReplace!=string::npos){
            s2[i].replace(foundWordReplace,wordReplace.length(),op1);
            while(foundWordReplace!=string::npos){
                foundWordReplace = s2[i].find(wordReplace,foundWordReplace+1);
                if(foundWordReplace!=string::npos)
                    s2[i].replace(foundWordReplace,wordReplace.length(),op1);
            }
                
         }
            
    }
    writeToFile(s2);
}
