//
// Created by cat on 10/16/16.
//

#include "Coder.h"
using namespace std;

void Coder::Encode(int n, int m, list<int> &code_word)
{
    int remainder = (unsigned int) (n % m);
    int quotient = (unsigned int) (n / m);

    list<int> q_vec;
    list<int> r_vec;

    int r_size = 0;
    if (m % 2 == 0)
    {
        r_size = (int)log2(m);
        Utils::Decimal2Binary(remainder, r_size, r_vec);
    }
    else
    {
        int b = (int)log2(m) + 1;
        if (remainder < pow(2, b) - m)
        {
            r_size = b - 1;
        }
        else
        {
            r_size = b;
        }
        Utils::Decimal2Binary(remainder, r_size, r_vec);
    }
    Utils::UnaryCode(quotient, q_vec);

    code_word.insert(code_word.begin(), q_vec.begin(), q_vec.end());
    code_word.insert(code_word.end(), r_vec.begin(), r_vec.end());
}

void Coder::Decode()
{

}