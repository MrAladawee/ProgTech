//
// Created by andre on 18.04.2022.
//

#include "queue.h"
#include <iostream>

using namespace std;

void enqueue(queue*& queue, man& newm) {
    elem* newel = new elem;
    newel->m = newm;
    if (!queue->tail)
    {
        queue->head = queue->tail = newel;
    } else
    {
        queue->tail->next = newel;
        queue->tail = newel;
    }
    queue->size++;
}

bool dequeue(queue*& queue, man& man)
{
    if (queue->size <= 0)
        return false;

    man = queue->head->m;
    elem* rem = queue->head;
    queue->head = queue->head->next;
    delete rem;
    queue->size--;

    return true;
}

void clear(queue& queue) {

    while (queue.head)
    {
        elem* rem = queue.head;
        queue.head = queue.head->next;
        delete rem;
    }
    queue.size = 0;
    queue.tail = nullptr;
}

void showQueue(queue*& queue)
{
    man m;
    while (queue->size > 0)
    {
        dequeue(queue, m);
        cout << m.name << "(" << m.age << " лет): пол:" << m.sex
             << ", место работы:" << m.work_place;
        if (m.salary == -1) {
            cout << ", доход: отсутствуют данные ,"
                    " цель:" << m.purpose << endl;
        }
        else {
            cout << ", доход: " << m.salary
                 << " , цель:" << m.purpose << endl;
        }
    }
}
