
#ifndef LAB1_DESERIALIZATOR_H
#define LAB1_DESERIALIZATOR_H

#include <iostream>
#include <sstream>
#include "Collections/Stack.h"
#include "Collections/List.h"
#include "Collections/Deque.h"

class Deserializator {
public:
    void Deserialize(const std::string &serializedString, Collection *&sourceCollection) const;

private:

    Stack *DeserializeStack(std::istringstream &ss) const;

    List *DeserializeList(std::istringstream &ss) const;

    Deque *DeserializeDeque(std::istringstream &ss) const;

    struct DynamicIntArray {
    public:
        DynamicIntArray(int *data, int size);

        int* getData();
        int getSize();

    private:
        int* data;
        int size;
    };

    DynamicIntArray DeserializeArray(std::istringstream &ss) const;
};


#endif //LAB1_DESERIALIZATOR_H
