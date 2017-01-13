//
// Created by cat on 10/16/16.
//

#ifndef GOLOMB_CODER_H
#define GOLOMB_CODER_H

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include "../Utils.h"

class Golomb
{
public:
    Golomb(unsigned int m);
    ~Golomb();
    void Encode(unsigned int to_encode, std::string &code_word);
    unsigned int Decode(const std::string &code_word);

private:
    /**
     * [Code parameter, that sets code word length]
     */
    unsigned int M;
    unsigned int _code_length;
};


#endif //GOLOMB_CODER_H
