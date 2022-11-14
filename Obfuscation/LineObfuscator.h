#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Obfuscator.h"
#ifndef LINE_OBFUSCATOR_H
#define LINE_OBFUSCATOR_H
using namespace std;
class LineObfuscator : public Obfuscator {
public:
    void obfuscate(string);
};
#endif 