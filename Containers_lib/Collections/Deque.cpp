#include "Deque.h"

Deque::Deque() : data(new Queue<int>()) {
}

Deque::Deque(int *elements, int countElements) : Deque() {
    for (int i = 0; i < countElements; ++i) {
        AddRear(elements[i]);
    }
}

Deque::Deque(const Deque &other) : Deque() {
    data = new Queue(*other.data);
}

Deque::~Deque() {
    delete data;
}

void Deque::AddFront(int value) {
    Queue<int> newData;

    newData.Enqueue(value);

    while (!data->IsEmpty()) {
        newData.Enqueue(data->Dequeue());
    }
    delete data;

    data = new Queue(newData);
}

void Deque::AddRear(int value) {
    data->Enqueue(value);
}

int Deque::RemoveFront() {
    CheckSize();
    return data->Dequeue();
}

int Deque::RemoveRear() {
    CheckSize();
    if(Size() == 1)
        return data->Dequeue();

    Queue<int> newData;

    int startSize = data->Size();
    for(int i = 0; i < startSize - 1; i++)
        newData.Enqueue(data->Dequeue());

    int lastElement = data->Dequeue();

    delete data;

    data = new Queue(newData);

    return lastElement;
}

int Deque::PeekFront() const {
    CheckSize();
    return data->Head();
}

int Deque::PeekRear() const {
    CheckSize();
    return data->Trail();
}

bool Deque::IsEmpty() const {
    return data->IsEmpty();
}

int Deque::Size() const {
    return data->Size();
}

Queue<int>::Iterator Deque::begin() const {
    return data->begin();
}

Queue<int>::Iterator Deque::end() const {
    return data->end();
}

void Deque::CheckSize() const {
    if(Size() == 0)
        throw std::out_of_range("Deque is empty");
}
