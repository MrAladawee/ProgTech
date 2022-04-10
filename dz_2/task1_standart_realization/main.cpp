#include <iostream>
#include <string>
#include <string.h>
#include "stack.h"

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

int check_math_expression(const char* exp) {

    //  Initialization
    elem* stack = nullptr;
    int index_open_bracket = -1;

    // Main part
    for (int index = 0; index < strlen(exp); index++) {

        // [, {, <, ( - adding this elements to stack
        if (__is_open_bracket(exp[index])) {
            push(stack, exp[index]);
            index_open_bracket = index;
            continue;
        }

        // ], }, >, ) - checking this elements with elements from stack
        if (__is_close_bracket(exp[index])) {
            //print(stack);
            // Extra ()}
            if (stack == nullptr) {
                return index+1;
            }

                // (], {>, ...
            else {
                if (!__brackets(stack,exp[index])) {
                    return index+1;
                }
            }
        }
    }

    if (stack != nullptr) {
        return index_open_bracket+1;
    }

    return 0;
}

int main() {
    char* exp = new char;
    cin >> exp;
    //cout << exp << endl << endl;

    if (check_math_expression(exp) != 0) {
        cout << "This math expression is bad. Bad index: " << check_math_expression(exp);
    }
    else {
        cout << "Math expression is good.";
    }
}
