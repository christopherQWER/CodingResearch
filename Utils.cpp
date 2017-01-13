//
// Created by cat on 10/16/16.
//

#include "Utils.h"
using namespace std;

/*void Utils::Decimal2Binary(unsigned int &decimal, int bits_num, string &binary)
{
    //binary = bitset<bits_num>(decimal).to_string(); // string conversion
}*/

void Decimal2Binary(unsigned int decimal, int bits_num, string &bin_string)
{
    int total =- 1;
    for(int q = 0; decimal > 0; q++)
    {
        if( (decimal % 2) == 0)
            bin_string.insert(0, "0");
        else
            bin_string.insert(0, "1");
        total++;
        decimal /= 2;
    }
    while (bits_num > bin_string.size())
        bin_string.insert(0, "0");
}

void UnaryCode(unsigned int decimal, string &unary_repr)
{
    // set zeroes (number of zeroes is decimal value)
    for (int i = 0; i < decimal; i++)
    {
        unary_repr += "1";
    }
    unary_repr += "0";
}

std::string List2String(std::list<unsigned int> &l)
{
    std::stringstream ss;
    for(list<unsigned int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        ss << *it;
    }
    string s = ss.str();
    return s;
}

int Binary2Decimal(std::string binary_string)
{
    int result = 0, pow = 1;
    for ( int i = binary_string.length() - 1; i >= 0; --i, pow <<= 1 )
        result += (binary_string[i] - '0') * pow;

    return result;
}

void AppendToFile(const std::string &output_path, double i_var, double d_var)
{
    ofstream density_file;
    density_file.open(output_path.c_str(), fstream::out | fstream::app);

    density_file << i_var;
    density_file << "\t";
    density_file << d_var;
    density_file << "\n";

    density_file.close();
}

void AppendToFile(const std::string &output_path, const std::string &text)
{
    ofstream density_file;
    density_file.open(output_path.c_str(), fstream::out | fstream::app);
    density_file << text;
    density_file << "\n";
    density_file.close();
}