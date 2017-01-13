#include <iostream>
#include <vector>
#include "Utils.h"
#include "Generators/Geometric.h"
#include "Coders/Golomb.h"
#include "Tests/Test.h"
using namespace std;
default_random_engine gen;
uniform_real_distribution<double> distrib(0.0, 1.0);
#define _GISTS_DIR_ "//home//cat//Documents//CodingResearch//Tests//Gists"

int main()
{
    unsigned int N = 13;
    unsigned int double_N = 0;
    unsigned int M = 5;
    string code_word;
    Golomb coder = Golomb(M);
    double entropy = Geometric::Gistogram(10000, string(_GISTS_DIR_) + "//out.txt");
    cout << "Entropy for geometric source: " << entropy << endl;
    Geometric::GetPlot(string(_GISTS_DIR_) + "//conf.plt",
                       string(_GISTS_DIR_) + "//Geometric.png",
                       string(_GISTS_DIR_) + "//out.txt");

    for (int i = 0; i < 20; i++)
    {
        N = (unsigned int) Geometric::GetRandom(0.3);
        cout << "Input number: " << N << " --> encode --> ";
        coder.Encode(N, code_word);
        cout << code_word << " --> decode --> ";
        double_N = coder.Decode(code_word);
        cout << double_N << " ";
        code_word.clear();
        cout << endl;
    }
    return 0;
}