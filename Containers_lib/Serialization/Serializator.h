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

    std::string SerializeCollection(const Collection &collection, bool reverse = false) const;

    std::string Serialize(const Stack &stack) const;
    std::string Serialize(const List &list) const;
    std::string Serialize(const Deque &deque) const;

private:
    int* GetArray(const Collection &collection) const;

    int* Reverse(int* source, int count) const;

    std::string Serialize(int* array, int count) const;

    std::string SerializeType(Collection &collection) const;
};


#endif //LAB1_SERIALIZATOR_H
