#include "Container_of_containers/Queue.h"

#ifndef LAB1_COLLECTION_H
#define LAB1_COLLECTION_H


class Collection {
public:
    virtual int Size() const = 0;
    virtual bool IsEmpty() const;

    virtual Queue<int>::Iterator begin() const = 0;
    virtual Queue<int>::Iterator end() const = 0;

};


#endif //LAB1_COLLECTION_H
