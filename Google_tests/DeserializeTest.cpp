#include "gtest/gtest.h"
#include "Serialization/Deserializator.h"

TEST(DeserializationTest, DeserializeStack) {
    Deserializator deserializator;
    std::string serializedString = "S 1 2 3";

    Stack *stack = new Stack();
    // Create a new stack
    deserializator.Deserialize(serializedString, reinterpret_cast<Collection *&>(stack));

// Check elements using iterators
    auto it = stack->begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
    ++it;

    delete stack;
}

TEST(DeserializationTest, DeserializeList) {
    Deserializator deserializator;
    std::string serializedString = "L 4 5 6";

    List *list = new List(); // Create a new list
    deserializator.Deserialize(serializedString, reinterpret_cast<Collection *&>(list));

// Check elements using iterators
    auto it = list->begin();
    EXPECT_EQ(*it, 4);
    ++it;
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(*it, 6);
    ++it;

    delete list;
}

TEST(DeserializationTest, DeserializeDeque) {
    Deserializator deserializator;
    std::string serializedString = "D 7 8 9";

    Deque *deque = new Deque(); // Create a new deque
    deserializator.Deserialize(serializedString, reinterpret_cast<Collection *&>(deque));

// Check elements using iterators
    auto it = deque->begin();
    EXPECT_EQ(*it, 7);
    ++it;
    EXPECT_EQ(*it, 8);
    ++it;
    EXPECT_EQ(*it, 9);
    ++it;

    delete deque;
}

TEST(DeserializationTest, DeserializeDequeAsList) {
    Deserializator deserializator;
    std::string serializedString = "L 7 8 9";

    Deque *deque = new Deque(); // Create a new deque
    deserializator.Deserialize(serializedString, reinterpret_cast<Collection *&>(deque));

// Check elements using iterators
    auto it = deque->begin();
    EXPECT_EQ(*it, 7);
    ++it;
    EXPECT_EQ(*it, 8);
    ++it;
    EXPECT_EQ(*it, 9);
    ++it;

    delete deque;
}