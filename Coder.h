//
// Created by cat on 10/16/16.
//

#pragma once
#ifndef GOLOMB_CODER_H
#define GOLOMB_CODER_H

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include "Utils.h"

class Coder {
public:
    static void Encode(int n, int m, std::list<int> &code_word);
    static void Decode();
};


#endif //GOLOMB_CODER_H
