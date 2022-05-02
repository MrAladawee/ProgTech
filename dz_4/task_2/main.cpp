#include <iostream>
#include "list.h"
using namespace std;

int main() {

    elem* num = nullptr; elem* num2 = nullptr;

    adder(num, 11111);
    adder(num, 999999999);
    adder(num, 999999999);
    adder(num, 999999999);
    adder(num, 999999999);
    show(num);
    cout << "First example is done." << endl << endl;

    adder(num2, 999999999);
    adder(num2, 999999999);
    adder(num2, 999999999);
    adder(num2, 999999999);
    show(num2);
    cout << "Second example is done." << endl << endl;

    adder(num, num2);
    adder(num, num2);
    show(num);
    cout << "Third example is done." << endl << endl;
}
