#include <cstring>
#include "Deserializator.h"

Stack *Deserializator::DeserializeAsStack(const std::string &serializedString) const {
    std::istringstream ss(serializedString);
    return DeserializeStack(ss);
}

List *Deserializator::DeserializeAsList(const std::string &serializedString) const {
    std::istringstream ss(serializedString);
    return DeserializeList(ss);
}

Deque *Deserializator::DeserializeAsDeque(const std::string &serializedString) const {
    std::istringstream ss(serializedString);
    return DeserializeDeque(ss);
}

Stack *Deserializator::DeserializeStack(std::istringstream &ss) const {
    auto array = DeserializeArray(ss);
    return new Stack(array.getData(), array.getSize());
}

List *Deserializator::DeserializeList(std::istringstream &ss) const {
    auto array = DeserializeArray(ss);
    return new List(array.getData(), array.getSize());
}

Deque *Deserializator::DeserializeDeque(std::istringstream &ss) const {
    auto array = DeserializeArray(ss);
    return new Deque(array.getData(), array.getSize());
}

Deserializator::DynamicIntArray Deserializator::DeserializeArray(std::istringstream &ss) const {
    int val;
    int capacity = 10;  // Initial capacity for the dynamic array
    int *elements = new int[capacity];
    int count = 0;

    while (ss >> val) {
        if (count == capacity) {
            // Increase capacity when needed
            capacity *= 2;
            int *newElements = new int[capacity];
            std::memcpy(newElements, elements, count * sizeof(int));
            delete[] elements;
            elements = newElements;
        }

        elements[count++] = val;
    }

    // Resize the array to the actual number of elements
    int *resizedElements = new int[count];
    std::memcpy(resizedElements, elements, count * sizeof(int));
    delete[] elements;

    DynamicIntArray result(resizedElements, count);
    return result;
}




Deserializator::DynamicIntArray::DynamicIntArray(int *data, int size) : data(data), size(size) {}

int *Deserializator::DynamicIntArray::getData() {
    return data;
}

int Deserializator::DynamicIntArray::getSize() {
    return size;
}
