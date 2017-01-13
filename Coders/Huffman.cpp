//
// Created by cat on 1/11/17.
//

#include "Huffman.h"
using namespace std;

void Huffman::BuildTable(Node *root)
{
    if (root->left != nullptr)
    {
        code.push_back(0);
        BuildTable(root->left);
    }

    if (root->right != nullptr)
    {
        code.push_back(1);
        BuildTable(root->right);
    }

    if (root->left == nullptr && root->right == nullptr) table[root->c] = code;

    code.pop_back();
}

void Huffman::GetSymFrequency(vector<char> symbols, map<char,int> &freq_map)
{
    for(int i = 0; i < symbols.size(); i++)
    {
        char c = symbols[i];
        freq_map[c]++;
    }
}

void Huffman::Compress(vector<char> to_compress)
{
    // Get symbols frequencies
    map<char, int> freq_map;
    GetSymFrequency(to_compress, freq_map);

    // Write starting nodes to the list
    list<Node*> t;
    for( map<char, int>::iterator itr = freq_map.begin(); itr != freq_map.end(); ++itr)
    {
        Node *p = new Node;
        p->c = itr->first;
        p->a = itr->second;
        t.push_back(p);
    }

    // Generate tree
    while (t.size() != 1)
    {
        t.sort(MyCompare());

        Node *descendant_l = t.front();
        t.pop_front();
        Node *descendant_r = t.front();
        t.pop_front();

        Node *parent = new Node(descendant_l, descendant_r);
        t.push_back(parent);
    }

    // Pointer to the top of the tree
    Node *root = t.front();
    // Generating pairs "symbol - code"
    BuildTable(root);

    int count = 0; char buf = 0;
    for (int i = 0; i < to_compress.size(); i++)
    {
        vector<bool> x = table[to_compress[i]];
        for(int n = 0; n < x.size(); n++)
        {
            buf = buf | x[n] << (7 - count);
            count++;
            if (count == 8)
            {
                count = 0;
                buf = 0;
            }
        }
    }
}