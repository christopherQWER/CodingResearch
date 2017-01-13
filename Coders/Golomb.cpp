//
// Created by cat on 10/16/16.
//

#include "Golomb.h"
using namespace std;

Golomb::Golomb(unsigned int m)
{
    M = m;
    _code_length = (unsigned int)log2(m) + 1;
}

Golomb::~Golomb()
{
}

void Golomb::Encode(unsigned int to_encode, string &code_word)
{
    unsigned int remainder = to_encode % M;
    unsigned int quotient = to_encode / M;

    string q_vec = "";
    string r_vec = "";

    int r_size = 0;
    if (M % 2 == 0)
    {
        r_size = _code_length - 1;
        Decimal2Binary(remainder, r_size, r_vec);
    }
    else
    {
        if (remainder < pow(2.0, _code_length) - M)
        {
            r_size = _code_length - 1;
        }
        else
        {
            r_size = _code_length;
        }
        Decimal2Binary(remainder, r_size, r_vec);
    }
    // Get first part of code word which is
    // unary code with length = quotient
    UnaryCode(quotient, q_vec);

    // Unary part
    code_word.insert(code_word.begin(), q_vec.begin(), q_vec.end());
    // Binary remainder representation part
    code_word.insert(code_word.end(), r_vec.begin(), r_vec.end());
}

unsigned int Golomb::Decode(const string &code_word)
{
    string str_r = "";
    int a = 0;
    int result = 0;
    int i = 0;
    int coded_r = 0;
    vector<char> char_code_word(code_word.c_str(), code_word.c_str() + code_word.size() + 1);
    while(char_code_word[i] != '0')
    {
        i++;
    }
    a = i;
    i++;
    for (; i < code_word.size(); i++)
    {
        str_r += char_code_word[i];
    }
    coded_r = Binary2Decimal(str_r);
    if (coded_r <= M)
    {
        result = M * a + coded_r;
    }
    else
    {
        result = M * a + coded_r - (pow(2.0, _code_length) - M);
    }
    return result;
}