//
// Created by cat on 10/16/16.
//

#pragma once
#ifndef GOLOMB_SOURCE_H
#define GOLOMB_SOURCE_H
#include <cmath>
#include <iostream>
#include <random>

class Generator {
public:
    Generator();
    ~Generator();
    static int GetRandom();
};


#endif //GOLOMB_SOURCE_H
