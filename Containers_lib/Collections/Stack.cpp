#include "Stack.h"

Stack::Stack() : data(new Queue<int>()) {}

Stack::Stack(int *elements, int countElements) : Stack() {
    for (int i = 0; i < countElements; ++i) {
        Push(elements[i]);
    }
}

Stack::Stack(const Stack &other) : Stack() {
    this->data = new Queue(*other.data);
}

Stack::~Stack() {
    delete data;
}

void Stack::Push(int value) {
    Queue<int> newData;

    newData.Enqueue(value);

    for (const auto &oldvalues: *data) {
        newData.Enqueue(oldvalues);
    }
    delete data;

    data = new Queue(newData);
}

int Stack::Pop() {
    if (Size() == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return data->Dequeue();
}

int Stack::Pick() const {
    if (Size() == 0) {
        throw std::out_of_range("Stack is empty");
    }
    return data->Head();
}

bool Stack::IsEmpty() const {
    return data->IsEmpty();
}

int Stack::Size() const {
    return data->Size();
}

Queue<int>::Iterator Stack::begin() const {
    return data->begin();
}

Queue<int>::Iterator Stack::end() const {
    return data->end();
}


