#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Obfuscator.h"
#ifndef COMMENT_OBFUSCATOR_H
#define COMMENT_OBFUSCATOR_H
using namespace std;
class CommentObfuscator : public Obfuscator {
public:
    void obfuscate(string);
};
#endif 