//
// Created by cat on 10/16/16.
//

#ifndef GOLOMB_SOURCE_H
#define GOLOMB_SOURCE_H
#include <cmath>
#include <iostream>
#include <map>
#include <random>
#include "../Utils.h"

class Geometric {
public:
    Geometric();
    ~Geometric();
    static unsigned int GetRandom(double p);
    static double Gistogram(unsigned int number_experiments, std::string out_txt);
    static void GetPlot(const std::string &plt_path, const std::string &png_path, const std::string &source_path);
};


#endif //GOLOMB_SOURCE_H
