#include "gtest/gtest.h"
#include "Container_of_containers/Queue.h"

TEST(QueueSuite, EnqueueAndDequeue) {
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Queue<int> queue;
    for (const auto &item: elements) {
        queue.Enqueue(item);
    }

    // Check elements after enqueue
    for (int i = 0; i < countElements; ++i) {
        EXPECT_EQ(queue.Dequeue(), elements[i]);
    }

    EXPECT_TRUE(queue.IsEmpty());
}

TEST(QueueSuite, QueueFromArray) {
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Queue<int> queue1; // Создаем пустую очередь
    Queue<int> queue2(elements, countElements); // Создаем очередь из массива

    // Заполняем queue1 элементами из массива elements
    for (int i = 0; i < countElements; ++i) {
        queue1.Enqueue(elements[i]);
    }

    // Сравниваем элементы из обеих очередей
    auto it1 = queue1.begin();
    auto it2 = queue2.begin();
    for (; it1 != queue1.end() && it2 != queue2.end(); ++it1, ++it2) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(QueueSuite, IteratorCount) {
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Queue<int> queue(elements, countElements);

    int count = 0;
    for (auto it = queue.begin(); it != queue.end(); ++it) {
        ++count;
    }

    EXPECT_EQ(count, countElements);
}

TEST(QueueSuite, DequeueIterator){
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    Queue<int> queueI (elements, countElements);
    Queue<int> queueD (elements, countElements);

    for (const auto &item: queueI) {
        EXPECT_EQ(queueD.Dequeue(), item);
    }

    // Убеждаемся, что итеируемая очередь непуста а декюшная пустая
    EXPECT_FALSE(queueI.IsEmpty());
    EXPECT_TRUE(queueD.IsEmpty());
}

TEST(QueueSuite, IsEmpty) {
    Queue<int> queue;

    EXPECT_TRUE(queue.IsEmpty());

    queue.Enqueue(10);
    EXPECT_FALSE(queue.IsEmpty());

    queue.Dequeue();
    EXPECT_TRUE(queue.IsEmpty());
}

TEST(QueueSuite, DequeueEmptyQueue) {
    Queue<int> queue;

    try {
        queue.Dequeue();
        FAIL() << "Expected std::out_of_range exception";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ("Queue is empty", e.what());
    } catch (...) {
        FAIL() << "Expected std::out_of_range exception";
    }
}
