#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#ifndef OBFUSCATOR_H
#define OBFUSCATOR_H
using namespace std;

class Obfuscator {
    public:
    const int MAX = 26;
    const string OUT = "newCode.c";
    virtual void obfuscate(string fileName) = 0;
    
    string generateRandomVar();//return random string . 
    string* parseFile(string);// return array of string according to the input text . 
    void writeToFile(string*);// open new file according to string array .  
    int sumNumLine(string*);// return how much line in the array .
    int sumNumLineBeforeMain(string*);//return sum line before Main line .
    int findLineWithInt(string*);//after the Main line the function will search the word int 4 lines after Main line.
    string randomString(); // the function have string array and returns string .
    int findLenWord(int ,string);// return length of word without the word int. 
    
    void findForAndInt(string*);// ***search for loops and terms and will insert Parenthesis if not ***. (המתרגלת אמרה לי לכתוב לבודק בהערה לגבי הפונקציה הזאת שלא יראה שהכנסתי הודפסות לא קשורות ) 
};
#endif 
 