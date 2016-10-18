//
// Created by cat on 10/16/16.
//
#pragma once
#ifndef GOLOMB_UTILS_H
#define GOLOMB_UTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <climits>
#include <list>

class Utils {
public:
    static void Decimal2Binary(int &decimal, int bits_num, std::string& binary);
    static void Decimal2Binary(int decimal, int bits_num, std::list<int> &binary);
    static void UnaryCode(int decimal, std::list<int> &unary_repr);
    static std::string Vector2String(std::list<int> &vector);
};


#endif //GOLOMB_UTILS_H
