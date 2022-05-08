#pragma once
#include <string>
using namespace std;

struct tree {
    string name;
    int count = 0; // count of repeats
    double av_score = 0;
    tree* left = nullptr;
    tree* right = nullptr;
    int lvl = 0;
};

void add(tree*& root, string new_word, double score, int level = 0);
void showTree(tree* root, int level);
