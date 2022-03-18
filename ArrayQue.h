#ifndef LIST_ARRAY_QUE_H
#define LIST_ARRAY_QUE_H

#include <cstddef>  // Required for NULL
#include "Que.h"

#include <iostream>


using namespace std;

template <class ItemType>
class ArrayQue: public Que<ItemType> {
    public:
        ArrayQue<ItemType>(int max) {
            maxQue = max + 1;
            front = maxQue - 1;
            rear = maxQue - 1;

            items = new ItemType[maxQue];
        }

        virtual void Enqueue(ItemType item) {
            rear = (rear + 1) % maxQue;
            items[rear] = item;
        }

        virtual ItemType Dequeue() {
            front = (front + 1) % maxQue;
            return items[front];

        }
    private:
        int maxQue;
        int front;
        int rear;
        ItemType *items;
};

#endif