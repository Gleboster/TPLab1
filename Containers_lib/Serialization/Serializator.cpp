#include <sstream>
#include "Serializator.h"

Serializator::Serializator() {}


std::string Serializator::SerializeCollection(const Collection &collection, bool reverse) const {
    int* array = GetArray(collection);

    if(reverse)
        array = Reverse(array, collection.Size());

    std::stringstream ss;
    ss << Serialize(array, collection.Size());
    return ss.str();
}

std::string Serializator::Serialize(const Stack &stack) const {
    return SerializeCollection(stack, true);
}

std::string Serializator::Serialize(const List &list) const {
    return SerializeCollection(list);
}

std::string Serializator::Serialize(const Deque &deque) const {
    return SerializeCollection(deque);
}

int *Serializator::GetArray(const Collection &collection) const {
    int *result = new int[collection.Size()];
    int i = 0;
    for (const auto &item: collection) {
        result[i] = item;
        i++;
    }
    return result;
}


int *Serializator::Reverse(int *source, int count) const {
    int *result = new int[count];
    for (int i = count - 1, j = 0; i >= 0, j < count; --i, j++) {
        result[j] = source[i];
    }
    delete[] source;

    return result;
}

std::string Serializator::Serialize(int *array, int count) const {
    if (count <= 0 || array == nullptr) {
        return std::string(); // Return an empty string for invalid input
    }

    std::stringstream ss;
    for (int i = 0; i < count; ++i) {
        ss << array[i]; // Serialize the integer
        if (i < count - 1) {
            ss << ' '; // Add a space between elements (except the last one)
        }
    }

    return ss.str(); // Return the serialized string
}

std::string Serializator::SerializeType(Collection &collection) const {
    std::string result;

    if (typeid(collection) == typeid(Stack)) {
        result = "S";
    } else if (typeid(collection) == typeid(Deque)) {
        result = "D";
    } else if (typeid(collection) == typeid(List)) {
        result = "L";
    } else {
        result = "Unknown";  // Or handle other types as needed
    }

    return result;
}


