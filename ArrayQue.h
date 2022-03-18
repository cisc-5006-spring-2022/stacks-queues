#ifndef LIST_ARRAY_QUE_H
#define LIST_ARRAY_QUE_H

#include <cstddef>  // Required for NULL
#include "Que.h"

#include <iostream>


using namespace std;

// An array-based implementation of a queue.
// It uses the loop-around logic described in the book.
// For a detailed description of what is going on, see Ch. 5.3, p. 309.
// In short: Index 0 in the array is the front of the queue.
// Elements closer to the end of the array are close to the end of the queue.
// As items are dequeued, the front moves through the array.
// For example:
//
//      ArrayQue(4)
//      Enqueue(10) Enqueue(20) Dequeue() Enqueue(30):
//
//        ___  20  30 ___
//         0   1   2   3
//
// To avoid wasting space, the queue loops around:
//
//      ArrayQue(4)
//      Enqueue(10) Enqueue(20) Dequeue() Dequeue() Enqueue(30)
//      Enqueue(5) Enqueue(2):
//
//          2 ___  30   5
//         0   1   2   3
template <class ItemType>
class ArrayQue: public Que<ItemType> {
    public:
        ArrayQue<ItemType>(int max) {
            maxQue = max + 1;
            front = maxQue - 1;
            rear = maxQue - 1;

            items = new ItemType[maxQue];
        }

        // Insert an item in the queue.
        virtual void Enqueue(ItemType item) {
            rear = (rear + 1) % maxQue;
            items[rear] = item;
        }

        // Remove an item from the queue.
        virtual ItemType Dequeue() {
            front = (front + 1) % maxQue;
            return items[front];

        }

        // Determine if the queue is empty
        virtual bool IsEmpty() {
            return (rear == front);
        }

        // Determine if the queue is full.
        virtual bool isFull() {
            return ((rear + 1) % maxQue == front);
        }

    private:
        int maxQue;
        int front;
        int rear;
        ItemType *items;
};

#endif