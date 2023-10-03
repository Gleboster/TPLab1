#include "gtest/gtest.h"
#include "Serialization/Deserializator.h"

TEST(DeserializationTest, DeserializeStack) {
    Deserializator deserializator;
    std::string serializedString = "1 2 3";

    Stack *stack = deserializator.DeserializeAsStack(serializedString);

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
    std::string serializedString = "4 5 6";

    List *list = deserializator.DeserializeAsList(serializedString);

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
    std::string serializedString = "7 8 9";

    Deque* deque = deserializator.DeserializeAsDeque(serializedString);

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
