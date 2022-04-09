#include <iostream>
#include <string>
#include <string.h>
#include "stack.h"

int choose;
const char* open_brackets = "[{<(";
const char* close_brackets = "]}>)";

using namespace std;

bool __is_open_bracket(char element) {
    for (int index = 0; index < strlen(open_brackets); index++) {
        if (element == open_brackets[index]) return true;
    }
    return false;
}

bool __is_close_bracket(char element) {
    for (int index = 0; index < strlen(close_brackets); index++) {
        if (element == close_brackets[index]) return true;
    }
    return false;
}

bool __brackets(elem*& stack, char bracket_2) {
    char bracket_1;
    pop(stack, bracket_1);
    int val = bracket_2 - bracket_1;
    if (val == 1 || val == 2) {
        return true;
    }
    return false;
}

void check_math_expression(const char* exp) {

    //  Initialization
    int amount_of_brackets = 0;
    elem* stack = nullptr;

    // Main part
    for (int index = 0; index < strlen(exp); index++) {

        // [, {, <, ( - adding this elements to stack
        if (__is_open_bracket(exp[index])) {
            push(stack, exp[index]);
            amount_of_brackets++;
            continue;
        }

        // ], }, >, ) - checking this elements with elements from stack
        if (__is_close_bracket(exp[index])) {
            //print(stack);
            // Extra ()}
            if (stack == nullptr) {
                if (choose == 1) {cout << index+1; return;}
                cout << "Index of extra bracket: " << index+1 << endl;
            }

                // (], {>, ...
            else {
                if (!__brackets(stack,exp[index])) {
                    if (choose == 1) {cout << index+1; return;}
                    cout << "Index of different bracket: " << index+1 << endl;
                }
            }
        }
    }
}

int main() {
    char* exp = new char;
    cin >> exp;
    //cout << exp << endl << endl;

    cout << "Write 1 if you want to see the first discrepancy between the brackets,\n"
            "And write 2 if you want to see almost all possible inconsistencies in parentheses:\n";
    cin >> choose;

    check_math_expression(exp);
}