#include <gtest/gtest.h>
#include "Collections/Deque.h"

TEST(DequeSuiteSuite, AddFrontAndRemoveFront) {
    Deque deque;

    deque.AddFront(10);
    deque.AddFront(20);
    deque.AddFront(30);

    EXPECT_EQ(deque.Size(), 3);

    EXPECT_EQ(deque.RemoveFront(), 30);
    EXPECT_EQ(deque.RemoveFront(), 20);
    EXPECT_EQ(deque.RemoveFront(), 10);
    EXPECT_EQ(deque.Size(), 0);
    EXPECT_TRUE(deque.IsEmpty());
}

TEST(DequeSuite, AddRearAndRemoveRear) {
    Deque deque;

    deque.AddRear(10);
    deque.AddRear(20);
    deque.AddRear(30);

    EXPECT_EQ(deque.Size(), 3);

    EXPECT_EQ(deque.RemoveRear(), 30);
    EXPECT_EQ(deque.RemoveRear(), 20);
    EXPECT_EQ(deque.RemoveRear(), 10);
    EXPECT_EQ(deque.Size(), 0);
    EXPECT_TRUE(deque.IsEmpty());
}

TEST(DequeSuite, PeekFrontAndPeekRear) {
    Deque deque;

    deque.AddFront(10);
    deque.AddFront(20);
    deque.AddFront(30);

    EXPECT_EQ(deque.PeekFront(), 30);
    EXPECT_EQ(deque.PeekRear(), 10);

    deque.RemoveFront();
    deque.RemoveRear();

    EXPECT_EQ(deque.PeekFront(), 20);
    EXPECT_EQ(deque.PeekRear(), 20);
}

TEST(DequeSuite, CopyConstructor) {
    Deque originalDeque;
    originalDeque.AddFront(10);
    originalDeque.AddFront(20);

    Deque copiedDeque(originalDeque);

    EXPECT_EQ(copiedDeque.Size(), originalDeque.Size());

    EXPECT_EQ(copiedDeque.RemoveFront(), 20);
    EXPECT_EQ(copiedDeque.RemoveFront(), 10);
    EXPECT_TRUE(copiedDeque.IsEmpty());
}
void TestEmptyDequeFunction(std::function<void(Deque&)> func) {
    Deque deque;

    EXPECT_THROW({
                     func(deque);  // Trying to call the function on an empty deque
                 }, std::out_of_range);
}

TEST(DequeSuite, RemoveFrontOnEmptyDeque) {
    TestEmptyDequeFunction([](Deque& deque) {
        deque.RemoveFront();
    });
}

TEST(DequeSuite, RemoveRearOnEmptyDeque) {
    TestEmptyDequeFunction([](Deque& deque) {
        deque.RemoveRear();
    });
}

TEST(DequeSuite, PeekFrontOnEmptyDeque) {
    TestEmptyDequeFunction([](Deque& deque) {
        deque.PeekFront();
    });
}

TEST(DequeSuite, PeekRearOnEmptyDeque) {
    TestEmptyDequeFunction([](Deque& deque) {
        deque.PeekRear();
    });
}

TEST(DequeSuite, IteratorTest) {
    Deque dequeI;

    dequeI.AddRear(10);
    dequeI.AddRear(20);
    dequeI.AddRear(30);

    Deque dequeR(dequeI);

    for (const auto &item : dequeI) {
        EXPECT_EQ(item, dequeR.RemoveFront());
    }

    EXPECT_FALSE(dequeI.IsEmpty());
    EXPECT_TRUE(dequeR.IsEmpty());
}

TEST(DequeSuite, CreateDequeFromArray) {
    int arr[] = {10, 20, 30, 40, 50};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    Deque deque(arr, arrSize);

    EXPECT_EQ(deque.Size(), arrSize);

    // Check the elements in the deque
    auto it = deque.begin();
    for (int i = 0; i < arrSize; ++i) {
        EXPECT_EQ(*it, arr[i]);
        ++it;
    }
}




