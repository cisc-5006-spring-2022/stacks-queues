#ifndef LIST_UNSORTED_LIST_H
#define LIST_UNSORTED_LIST_H

#include <cstddef>  // Required for NULL
#include "Stack.h"

#include <iostream>

class EmptyStack{};


using namespace std;

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType<ItemType> *next;
};

template <class ItemType>
class LinkedStack: public Stack<ItemType> {
    public:
        LinkedStack() {
            top = NULL;
        }

        virtual void Push(ItemType item) {
            // Create a new linked list node
            NodeType<ItemType> *newItem = new NodeType<ItemType>;

            // The new node will become the first node in the list.
            // Set its value, then make the current first node
            // come after this one
            newItem->info = item;
            newItem->next = this->top;
            this->top = newItem;
        };


        virtual void Pop() {
            if (top == NULL) {
                throw EmptyStack();
            }

            NodeType<ItemType> *tmp = top;
            top = top->next;
            delete tmp;
        };

        virtual ItemType Top() {
            if (top == NULL) {
                throw EmptyStack();
            }
            return top->info;
        }

        virtual bool IsEmpty() {
            return top == NULL;
        }

        virtual bool IsFull() {
            return false;
        };

    private:
        NodeType<ItemType> *top;
};

#endif