#pragma once

struct elem
{
    int a;
    elem* next = nullptr;
    elem* prev = nullptr;
};

void create(elem*& cur);
void adder(elem*& num1, elem* num2);
void adder(elem*& num1, int num2);
int count(int x);
void show(elem* num);
