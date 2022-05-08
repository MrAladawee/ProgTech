#include "tree.h"
#include <iostream>
#include <string>

using namespace std;

void add(tree*& root, string new_word, double score, int level) {
    if (!root) { // root == nullptr
        tree* newelem = new tree;
        newelem->name = new_word;
        newelem->lvl = level;
        newelem->av_score = score;
        root = newelem;
        return;
    }

    if (root->name > new_word) {
        add(root->left, new_word, score, level+1);
        return;
    }

    if (root->name < new_word) {
        add(root->right, new_word, score, level + 1);
        return;
    }
    if (root->name == new_word) {
        root->count++;
        return;
    }
}

void showTree(tree* root, int level) {

    if (!root) {
        return;
    }

    if (root->left != nullptr) { showTree(root->left, level); }
    for (int i = 0; i < root->lvl; i++) {
        cout << ".";
    }
    cout << root->name << " (" << root->av_score << ") " << endl;
    if (root->right != nullptr) { showTree(root->right, level--); }

}
