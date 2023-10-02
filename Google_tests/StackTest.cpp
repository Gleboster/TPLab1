#include "gtest/gtest.h"
#include "Collections/Stack.h"

TEST(StackSuite, PushPickPop){
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Stack stack;
    for (int i = 0; i < countElements; ++i) {
        stack.Push(elements[i]);
        EXPECT_EQ(stack.Peek(), elements[i]);
    }

    EXPECT_EQ(stack.Size(), countElements);

    for (int i = countElements - 1; i >= 0; --i) {
        int popped = stack.Pop();
        EXPECT_EQ(popped, elements[i]);
    }
}

TEST(StackSuite, Iterator){
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Stack stackI;
    Stack stackP;

    for (int i = 0; i < countElements; ++i) {
        stackI.Push(elements[i]);
        stackP.Push(elements[i]);
    }

    for (const auto &item: stackI) {
        int popped = stackP.Pop();
        std::cout << popped << " ";
        EXPECT_EQ(popped, item);
    }

    EXPECT_FALSE(stackI.IsEmpty());
    EXPECT_TRUE(stackP.IsEmpty());
}

TEST(StackSuite, StackFromArray){
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Stack stack1;
    for (int i = 0; i < countElements; ++i) {
        stack1.Push(elements[i]);
    }

    Stack stack2(elements, countElements);

    auto it1 = stack1.begin();
    auto it2 = stack2.begin();
    for (; it1 != stack1.end() && it2 != stack2.end(); ++it1, ++it2) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(StackSuite, StackFromStack){
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Stack stack1;
    for (int i = 0; i < countElements; ++i) {
        stack1.Push(elements[i]);
    }

    Stack stack2(stack1);

    auto it1 = stack1.begin();
    auto it2 = stack2.begin();
    for (; it1 != stack1.end() && it2 != stack2.end(); ++it1, ++it2) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(StackException, PopOnEmptyStack) {
    Stack stack;
    try {
        stack.Pop();
        FAIL() << "Expected std::out_of_range exception, but no exception was thrown.";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ("Stack is empty", e.what());
    } catch (...) {
        FAIL() << "Expected std::out_of_range exception, but a different exception was thrown.";
    }
}

TEST(StackException, PickOnEmptyStack) {
    Stack stack;
    try {
        stack.Peek();
        FAIL() << "Expected std::out_of_range exception, but no exception was thrown.";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ("Stack is empty", e.what());
    } catch (...) {
        FAIL() << "Expected std::out_of_range exception, but a different exception was thrown.";
    }
}