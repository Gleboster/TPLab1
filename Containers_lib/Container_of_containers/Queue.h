#pragma once

#include <stdexcept>

template<typename T>
class Queue {
public:
    Queue() : count(0), trail(nullptr), head(nullptr) {};

    Queue(T *elements, int countElements) : Queue() {
        for (int i = 0; i < countElements; i++)
            Enqueue(elements[i]);
    }

    Queue(const Queue &other) : Queue() {
        for (const auto &element: other) {
            Enqueue(element);
        }
    }

    ~Queue() {
        while (!IsEmpty())
            Dequeue();
    };

    void Enqueue(T value) {
        Element *node = new Element(value);
        if (count == 0) {
            head = node;
            trail = node;
        } else {
            trail->prev = node;
            trail = node;
        }
        count++;
    }

    T Dequeue() {
        if (count == 0) {
            throw std::out_of_range("Queue is empty");
        }
        T value = head->value;
        Element *next = head->prev;
        delete head;
        head = next;
        count--;
        if(count == 0)
            trail = nullptr;
        return value;
    }

    T Head() const {
        return trail == nullptr ? T() : head->value;
    }

    T Trail() const {
        return trail == nullptr ? T() : trail->value;
    }

    int Size() const {
        return count;
    }

    bool IsEmpty() const {
        return count == 0;
    }

    bool operator!() {
        return IsEmpty();
    }

private:
    class Element {
    public:
        Element(T value) {
            this->value = value;
            prev = nullptr;
        }

        T value;
        Element *prev;
    };

public:
    class Iterator{
    public:
        Iterator(Element *current) {
            this->current = current;
        }

        T &operator*() {
            return current->value;
        }

        Iterator &operator++() {
            current = current->prev;
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            return current != other.current;
        }

    private:
        Element *current;
    };

    int count;
    Element *head;
    Element *trail;

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};
