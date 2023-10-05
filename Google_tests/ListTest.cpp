#include "gtest/gtest.h"
#include "Collections/List.h"

List getList(int n) {
    List *list = new List();

    for (int i = 0; i < n; ++i) {
        list->Append(i + 1);
    }

    return *list;
}

TEST(ListSuite, SetElement) {
    int countList = 10;
    List list = getList(countList);

    for (int i = 0; i < countList; ++i) {
        int indexToSet = i % list.Size();
        int itemToSet = 10;

        list.SetElement(indexToSet, itemToSet);
        EXPECT_EQ(list.Size(), countList);

        EXPECT_EQ(list.GetElement(indexToSet), itemToSet);
        EXPECT_EQ(list.Size(), countList);
    }
}

TEST(ListSuite, GetElement) {
    int count = 100;
    int *elements = new int[count];
    for (int i = 0; i < count; i++){
        elements[i] = i + 1;
    }
    List list(elements, count);

    for (int i = 0; i < count; ++i) {
        EXPECT_EQ(list.GetElement(i), elements[i]);
    }
}

TEST(ListSuite, GetElementOutOfRange) {
    List list;
    EXPECT_THROW(list.GetElement(0), std::out_of_range);

    // Добавление нескольких элементов
    list.Append(10);
    list.Append(20);
    list.Append(30);

    // Попытка доступа к элементу с неверным индексом
    EXPECT_THROW(list.GetElement(5), std::out_of_range);
    EXPECT_THROW(list.GetElement(-1), std::out_of_range);
}

TEST(ListSuite, ListFromArray) {
    int arr[] = {10, 20, 30, 40, 50};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    List list(arr, arr_size);

    EXPECT_EQ(list.Size(), arr_size);

    for (int i = 0; i < arr_size; ++i) {
        EXPECT_EQ(list.GetElement(i), arr[i]);
    }
}

TEST(ListSuite, Insert) {
    List list;

    list.Append(10);
    list.Append(20);
    list.Append(30);

    int initialSize = list.Size();

    int indexToInsert = 1;
    int itemToInsert = 15;
    list.Insert(indexToInsert, itemToInsert);

    EXPECT_EQ(list.GetElement(indexToInsert), itemToInsert);
    EXPECT_EQ(list.Size(), initialSize + 1);
}

TEST(ListSuite, InsertToEnd) {
    List list;

    int initialSize = list.Size();

    int iterations = 10;

    for (int i = 0; i < iterations; ++i) {
        int indexToInsert = initialSize + i;
        int itemToInsert = 15;
        list.Insert(indexToInsert, itemToInsert);

        EXPECT_EQ(list.GetElement(indexToInsert), itemToInsert);
    }

    EXPECT_EQ(list.Size(), initialSize + iterations);
}

TEST(ListSuite, IndexOf) {
    List list;

    for (int i = 0; i < 1000; ++i) {
        list.Append(i);
    }

    for (int i = 0; i < 1000; ++i) {
        int index = list.IndexOf(i);

        EXPECT_EQ(index, i);
    }

    EXPECT_EQ(list.IndexOf(-3), -1);
}

TEST(ListSuite, Remove) {
    int elements[] = {1, 2, 3, 4, 5};
    int countElements = sizeof(elements) / sizeof(elements[0]);

    List d(elements, countElements);

    d.Remove(3);

    for (const auto &item: d) {
        printf("%d ", item);
    }

    EXPECT_EQ(d.Size(), countElements - 1);
    EXPECT_EQ(d.IndexOf(3), -1);
}

TEST(ListSuite, Clear) {
    const int initial_size = 1000;
    List list = getList(initial_size);

    EXPECT_EQ(list.Size(), initial_size);
    list.Clear();
    EXPECT_EQ(list.Size(), 0);
}

