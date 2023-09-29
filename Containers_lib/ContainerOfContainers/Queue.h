#pragma once

#include <stdexcept>

template<typename T>
class Queue {
public:
    Queue(T *elements, int countElements) {
        for (int i = 0; i < countElements; i++)
            Enqueue(elements[i]);
    };

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
        return value;
    }

    bool IsEmpty() {
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

    class Iterator {
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

public:
    Iterator begin() {
        return Iterator(trail);
    }

    Iterator end() {
        return Iterator(head);
    }
};
