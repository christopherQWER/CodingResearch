//
// Created by cat on 1/11/17.
//

#ifndef CODINGRESEARCH_HUFFMAN_H
#define CODINGRESEARCH_HUFFMAN_H

#include <iostream>
#include <vector>
#include <map>
#include <list>

class Node
{
public:
    int a;
    char c;
    Node *left, *right;

    Node() { left = right = nullptr; }

    Node(Node *L, Node *R)
    {
        left = L;
        right = R;
        a = L->a + R->a;
    }
};


struct MyCompare
{
    bool operator()(const Node* l, const Node* r) const { return l->a < r->a; }
};

class Huffman
{
public:
    std::vector<bool> code;
    std::map<char, std::vector<bool> > table;
    void Compress(std::vector<char> to_compress);

private:
    void BuildTable(Node *root);
    void GetSymFrequency(std::vector<char> symbols, std::map<char,int> &freq_map);
};


#endif //CODINGRESEARCH_HUFFMAN_H
