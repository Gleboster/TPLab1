#include <gtest/gtest.h>
#include <iostream>
#include <vector>

// Include your collection and serializator classes
#include "Collections/Collection.h" // Replace with appropriate header file names
#include "Serialization/Serializator.h" // Replace with appropriate header file names


TEST(SerializationTest, StackSerialization) {
    int arr[] = {1, 2, 3, 4, 5};
    int count = sizeof(arr) / sizeof(arr[0]);
    Stack stack(arr, count);

    Serializator serializator;
    std::string serializedString = serializator.Serialize(stack);

    EXPECT_EQ(serializedString, "S 1 2 3 4 5");
}

TEST(SerializationTest, ListSerialization) {
    int arr[] = {6, 7, 8, 9};
    int count = sizeof(arr) / sizeof(arr[0]);
    List list(arr, count);

    Serializator serializator;
    std::string serializedString = serializator.Serialize(list);

    EXPECT_EQ(serializedString, "L 6 7 8 9");
}

TEST(SerializationTest, DequeSerialization) {
    int arr[] = {10, 11, 12};
    int count = sizeof(arr) / sizeof(arr[0]);
    Deque deque(arr, count);

    Serializator serializator;
    std::string serializedString = serializator.Serialize(deque);

    EXPECT_EQ(serializedString, "D 10 11 12");
}


