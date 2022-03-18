#ifndef QUE_H
#define QUE_H

// An exception class for when a GetItem operation fails
class NotFoundException{};

template <class ItemType>
class Que {
    public:
        virtual void Enqueue(ItemType item)=0;
        virtual ItemType Dequeue()=0;
};

#endif