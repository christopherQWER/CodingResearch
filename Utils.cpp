//
// Created by cat on 10/16/16.
//

#include "Utils.h"
using namespace std;

void Utils::Decimal2Binary(int &decimal, int bits_num, std::string &binary)
{
    //binary = bitset<bits_num>(decimal).to_string(); // string conversion
}

void Utils::Decimal2Binary(int decimal, int bits_num, list<int> &binary)
{
    int total =- 1;
    for(int q = 0; decimal > 0; q++)
    {
        if( (decimal % 2) == 0)
            binary.push_front(0);
        else
            binary.push_front(1);
        total++;
        decimal /= 2;
    }
    while (bits_num > binary.size())
        binary.push_front(0);
}

void Utils::UnaryCode(int decimal, std::list<int> &unary_repr)
{
    // set zeroes (number of zeroes is decimal value)
    for (int i = 0; i < decimal; i++)
    {
        unary_repr.push_back(1);
    }
    unary_repr.push_back(0);
}

std::string Utils::Vector2String(std::list<int> &l)
{
    std::stringstream ss;
    for(list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        ss << *it;
    }
    string s = ss.str();
    return s;
}
