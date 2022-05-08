#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#include "tree.h"

using namespace std;

bool find_in_tree_thLetter(tree* root, char cmpObj) {

    if (!root) { return false; }

    if (root->name[0] == cmpObj) { // if root is our right word

        cout << root->name << " (" << root->av_score << ")" << endl;

        if (root->left != nullptr && root->left->name[0] == cmpObj) {
            find_in_tree_thLetter(root->left, cmpObj);
        }

        if (root->right != nullptr && root->right->name[0] == cmpObj) {
            find_in_tree_thLetter(root->right, cmpObj);
        }

        return true; // exiting recursion
                     //
                     // The following iterations will not pass,
                     // because they are checked earlier
    }

    if (root->name[0] > cmpObj) { // if our right word > root word, then we go left
        if (root->left == nullptr) {
            cout << "not_found"<<endl;
            return false;

        }
        else { return find_in_tree_thLetter(root->left, cmpObj); } // entering recursion
    }

    if (root->name[0] < cmpObj) { // if our right word > root word, then we go right
        if (root->right == nullptr) {
            cout << "not_found" << endl;
            return false;
        }
        else { return find_in_tree_thLetter(root->right, cmpObj); } // entering recursion
    }
}


void find_in_tree_thScore(tree* root, double cmpObject, int level, int& flag) {

    if (!root) {
        return;
    }

    if (root->left != nullptr) { find_in_tree_thScore(root->left, cmpObject, level, flag); }
    if (root->av_score == cmpObject) { flag = 1; cout << root->name << " (" << root->av_score << ") " << endl; }
    if (root->right != nullptr) { find_in_tree_thScore(root->right, cmpObject, level--, flag); }

}

bool data_fill(tree*& root, string fileName) {

    ifstream file(fileName);

    if (!file.is_open())
    {
        cout << "File reading error." << endl;
        return false;
    }

    while (!file.eof())
    {
        string name_tmp;
        double score_tmp;
        // Initialization string
        int buf_size = 256;
        char* line = new char[buf_size];
        file.getline(line, buf_size - 1);

        char* context;
        char* pch = strtok_s(line,",", &context);
        name_tmp = pch;
        score_tmp = atof(context);

        cout << name_tmp << " " << score_tmp << endl;

        add(root,name_tmp,score_tmp);
    }

    return true;
}

int main() {

    tree* root = nullptr;

    // Add part

    /*
    add(root, "Vismutov", 4.0);
    add(root, "Abdurahmanov", 4.2);
    add(root, "Bebekurov", 4.2);
    add(root, "Barashkin", 4.3);
    add(root, "Borozdov", 4);
    add(root, "Borpidzov", 3.5);
    add(root, "Bopominud", 4);
    add(root, "Malkin", 5);
    add(root, "Septunov", 4.9);
    add(root, "Bopoaidov", 4.2);
    */

    data_fill(root,"data.txt");
    cout << endl;

    // Check tree
    showTree(root, 0);
    cout << endl;

    // Find obj in tree

    // // Setup compare mode
    int cmpMode;
    cout << "How we will did search element in tree? Through average score or with a first letter of last name?" << endl
    << "1 - average score, 0 - first letter" << endl; cin >> cmpMode;
    if (cmpMode != 1 && cmpMode != 0)  { cout << "Oops! You've written bad compare mode! Reread and do again!"; return -1; }

    if (cmpMode == 1) {
        cout << "Write average score: ";
        float cmpObj;
        cin >> cmpObj;

        int flag = 0;
        find_in_tree_thScore(root,cmpObj,0, flag);
        if (flag == 0) cout << "not_found.";
    }

    else {
        cout << "Write a first letter (with a capital letter!): ";
        char cmpObj;
        cin >> cmpObj;
        find_in_tree_thLetter(root,cmpObj);
    }

}
