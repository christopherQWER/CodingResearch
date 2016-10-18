//
// Created by cat on 10/16/16.
//

#include "Generator.h"
using namespace std;

default_random_engine generator;
uniform_real_distribution<double> distribution(0.0, 1.0);

Generator::Generator()
{}

Generator::~Generator()
{}

int Generator::GetRandom()
{
    double uniform_num = distribution(generator);
    int rand_num = (int)(- log2((1 - uniform_num) / 2)) ;
    return rand_num;
}