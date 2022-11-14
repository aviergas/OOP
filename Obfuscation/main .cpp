
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include <conio.h>
#include "Obfuscator.h"
#include "LineObfuscator.h"
#include "VarObfuscator.h"
#include "CommentObfuscator.h"
using namespace std;

int main() {
    srand (time(NULL));
    Obfuscator* obfs[3];
    obfs[0] = new VarObfuscator();
    obfs[1] = new LineObfuscator();
    obfs[2] = new CommentObfuscator();
    //obfuscate the code , starting with VarObfuscator ,*** Make sure the file "newCode.c" does not exist, otherwise the code will not run*** .
    obfs[0]->obfuscate("test.txt");
    for(int i = 1; i < 3; i++) 
	    obfs[i]->obfuscate(obfs[i-1]->OUT);
	
	for(int i = 0; i < 3; i++) 
        delete obfs[i];

}






