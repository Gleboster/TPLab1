#include "Container_of_containers/Queue.h"
#include "Collection.h"

#ifndef LAB1_STACK_H
#define LAB1_STACK_H


class Stack : public Collection {
    Queue<int> data;

public:
    Stack();

    Stack(int *elements, int countElements);

    Stack(const Stack &other);

    void Push(int value);

    void Pop();

    int Pick() const;

    bool IsEmpty() const;

    int Size() const;

};


#endif //LAB1_STACK_H
