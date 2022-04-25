#include <iostream>
#include <cstring>
#include <fstream>
#include "queue.h"

using namespace std;

inline man create_elem(char* information) {
    man m;
    char* context;

    char* pch = strtok_s(information,"|", &context);
    m.name = pch;
    information = nullptr;

    pch = strtok_s(information, "|", &context);
    m.sex = pch;
    information = nullptr;


    pch = strtok_s(information, "|", &context);
    m.age = stoi(pch);
    information = nullptr;

    pch = strtok_s(information, "|", &context);
    m.work_place = pch;
    information = nullptr;

    pch = strtok_s(information, "|", &context);

    if (pch[1] >= '0' && pch[1] <= '9') {
        m.salary = stoi(pch);
        information = nullptr;
        pch = strtok_s(information, "|", &context);
        m.purpose = pch;
    }
    else {
        m.salary = -1;
        m.purpose = pch;
    }

    return m;
}

bool data_fill(const char* filename, queue*& deposits, queue*& credits) {

    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "File reading error" << endl;
        return false;
    }

    while (!file.eof())
    {
        // Initialization string
        int buf_size = 256;
        char* line = new char[buf_size];
        file.getline(line, buf_size - 1);

        // Create structure information
        man m = create_elem(line);

        if (string(m.purpose) == " кредит") {
            enqueue(credits,m);
        }
        else if (string(m.purpose) == " вклад") {
            enqueue(deposits,m);
        }

    }

    return true;
}

int main() {
    // System instruction initialization
    system("chcp 65001");

    // Create database
    queue* deposits = new queue;
    queue* credits = new queue;

    // Main part
    data_fill("data.txt", deposits, credits);
    cout << endl;

    // Show databaase
    cout << "Deposits: " << endl;
    showQueue(deposits);

    cout << endl << endl;

    cout << "Credits: " << endl;
    showQueue(credits);

}
