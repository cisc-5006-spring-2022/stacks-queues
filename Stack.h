#ifndef STACK_H
#define STACK_H

template <class ItemType>
class Stack {
    public:
        virtual void Push(ItemType item)=0;
        virtual void Pop()=0;
        virtual ItemType Top()=0;

        virtual bool IsEmpty()=0;
        virtual bool IsFull()=0;
};

#endif