#include <iostream>
#include "stack.h"

struct elem
{
    char val;
    elem* next;
};

void push(elem*& stack, char val)
{
    elem* newel = new elem;
    newel->val = val;
    newel->next = stack;
    stack = newel;
}

bool pop(elem*& stack, char& val)
{
    if (stack == nullptr)
        return false;

    val = stack->val;
    stack = stack->next;
}

bool peek(elem* stack, char& val)
{
    if (stack == nullptr)
        return false;

    val = stack->val;
}

void print(elem*& stack)
{
    char val;
    while (pop(stack, val))
        std::cout << val << std::endl;
}