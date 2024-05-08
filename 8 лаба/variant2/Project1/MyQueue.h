#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <string>
struct Queue {
    int info;
    Queue* next;
};

void create(Queue** begin, Queue** end, const std::string& valuesstr);
void view(const Queue* begin);
void clear(Queue** begin);
void removeElement(Queue** begin, int value);
int findMinMaxDiff(const Queue* begin);
int countElementsBetweenMinMax(const Queue* begin);

#endif // MYQUEUE_H
