#include "Collection.h"
#include "Container_of_containers/Queue.h"

#ifndef LAB1_DEQUE_H
#define LAB1_DEQUE_H

class Deque : public Collection {
    Queue<int>* data;

public:
    Deque();

    Deque(int *elements, int countElements);

    Deque(const Deque &other);

    ~Deque();

    void AddFront(int value);

    void AddRear(int value);

    int RemoveFront();

    int RemoveRear();

    int PeekFront() const;

    int PeekRear() const;

    bool IsEmpty() const;

    int Size() const;

    Queue<int>::Iterator begin() const;

    Queue<int>::Iterator end() const;
private:
    void CheckSize() const;
};

#endif //LAB1_DEQUE_H
