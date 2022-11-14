#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Obfuscator.h"
#ifndef VAR_OBFUSCATOR_H
#define VAR_OBFUSCATOR_H
using namespace std;
class VarObfuscator : public Obfuscator {
public:
    void obfuscate(string);
};
#endif 