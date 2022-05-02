#include <iostream>
#include "list.h"
#define billion 1000000000
using namespace std;

void create(elem*& cur) {
    if (cur == nullptr)
    {
        cur = new elem;
        cur->a = 0;
    }
}

void adder(elem*& num1, elem* num2) {

    // This function will add the number "num2" (LIST) to the number "num1" and save result in "num1".
    // // If we save 0 in some part, it means write zero in nine times

    create(num1); // if in first moment num1 is nullptr (like not exist)

    elem* cur = num1; // copy num1
    elem* adder = num2; // copy num2
    elem* prev = nullptr; // prev part of number for num1

    int num_tmp = 0; // tmp var for saving draft calculations

    while (adder || num_tmp != 0) {

        create(cur);

        if (adder != nullptr) {
            num_tmp += adder->a;
            adder=adder->next;
        }

        int tmp = cur->a + num_tmp;
        cur->a = tmp % billion; // first part (<=9 digits)
        num_tmp = tmp / billion; // second part (>9 digits)

        prev = cur; // save first part
        cur = cur->next; // ->
        create(cur); // create new part of number
        cur->prev = prev; // insert previous part
        prev->next = cur; // insert new part
    }
}


void adder(elem*& num1, int num2) {

    // This function will add the number "num2" to the number "num1" and save result in "num1".
    // // If we save 0 in some part, it means write zero in nine times

    create(num1); // if in first moment num1 is nullptr (like not exist)

    elem* cur = num1; // copy num1
    elem* prev = nullptr; // prev part of number for num1


    while (num2 != 0) {

        create(cur);

        int tmp = cur->a + num2;
        cur->a = tmp % billion; // first part (<=9 digits)
        num2 = tmp / billion; // second part (>9 digits)

        prev = cur; // save first part
        cur = cur->next; // ->
        create(cur); // create new part of number
        cur->prev = prev; // insert previous part
        prev->next = cur; // insert new part
    }
}

int count(int x) {

    // Default function for finding count of digits in number.

    int count = 0;

    while (x > 0) {
        x /= 10;
        count++;
    }
    return count;
}

void show(elem* num) {
    create(num);
    elem* cur = num; // copy num

    while (cur != nullptr) // skipping first part
        if (!cur->next) {
            break;
        }
        else {
            cur = cur->next;
        }

    while (cur) {
        if (cur->a != 0) {
            // Work with a parts of number and zero.
            if (cur->next != nullptr)
                if (cur->next->a != 0)
                    for (int i = 0; i < 9 - count(cur->a); i++)
                        cout << 0;

            cout << cur->a;
        }
        cur = cur->prev;
    }
    cout << endl;
}
