#pragma once

#ifndef LAB1_SERIALIZATOR_H
#define LAB1_SERIALIZATOR_H

#include "string"
#include "Collections/Stack.h"
#include "Collections/List.h"
#include "Collections/Deque.h"

class Serializator {
public:
    Serializator();

    std::string Serialize(Stack &stack) const;
    std::string Serialize(List &list) const;
    std::string Serialize(Deque &deque) const;

private:
    int* GetArray(Collection &collection) const;

    int* Reverse(int* source, int count) const;

    std::string Serialize(int* array, int count) const;

    std::string SerializeType(Collection &collection) const;
};


#endif //LAB1_SERIALIZATOR_H
