#ifndef QUE_H
#define QUE_H

// An exception class for when a GetItem operation fails
class NotFoundException{};

template <class ItemType>
class Que {
    public:
        // Add an item to the queue
        virtual void Enqueue(ItemType item)=0;

        // Remove an item from the queue
        virtual ItemType Dequeue()=0;

        // Determine whether the queue is empty
        virtual bool IsEmpty()=0;
};

#endif