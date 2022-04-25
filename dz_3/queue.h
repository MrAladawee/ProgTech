//
// Created by andre on 18.04.2022.
//

#pragma once

struct man {
    /// Имя человека
    char *name;
    /// Пол человека
    char *sex;
    /// Возраст человека
    int age;
    /// Место работы человека
    char *work_place;
    /// Доход человека
    int salary;
    /// Тип обращения
    char *purpose;
};

struct elem {
    /// Информационное поле
    man m;
    /// Адресное поле
    elem* next = nullptr;
};

/// Структура для работы с очередью, хранящая указатели на ее начало и конец
struct queue {
    /// Первый элемент очереди (голова)
    elem* head = nullptr;
    /// Последний элемент очереди (хвост)
    elem* tail = nullptr;
    /// Количество элементов в очереди
    int size = 0;
};

void enqueue(queue*& queue, man& newm);
bool dequeue(queue& queue, man& m);
void clear(queue& queue);
void showQueue(queue*& queue);
