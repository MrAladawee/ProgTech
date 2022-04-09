#pragma once
struct elem;

void push(elem*& stack, char val);
bool pop(elem*& stack, char& val);
bool peek(elem* stack, char& val);
void print(elem*& stack);