//
// Created by cat on 10/16/16.
//
#ifndef GOLOMB_UTILS_H
#define GOLOMB_UTILS_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
#include <bitset>
#include <vector>
#include <climits>
#include <list>

int Binary2Decimal(std::string binary_string);
void Decimal2Binary(unsigned int decimal, int bits_num, std::string& binary);
void UnaryCode(unsigned int decimal, std::string &unary_repr);
std::string List2String(std::list<unsigned int> &vector);
void AppendToFile(const std::string &output_path, double i_var, double d_var);
void AppendToFile(const std::string &output_path, const std::string &text);

#endif //GOLOMB_UTILS_H
