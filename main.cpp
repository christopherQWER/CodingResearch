#include <iostream>
#include <vector>
#include "Utils.h"
#include "Generator.h"
#include "Coder.h"
using namespace std;

int main()
{
    int M = 10;
    list<int> code_word;


    for (int i = 10; i < 25; i++)
    {
        Coder::Encode(i, M, code_word);
        printf("%d / %d = %d with remainder: %d. %d --> %s\n",
               i, M, i / M, i % M, i, Utils::Vector2String(code_word).c_str());
        code_word.clear();
    }
    return 0;
}