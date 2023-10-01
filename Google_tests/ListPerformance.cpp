#include <iomanip>
#include "gtest/gtest.h"
#include "Collections/List.h"

void TestPerformance(std::function<void(List &)> method, const std::string &method_name) {
    const int num_iterations = 1000; // Количество итераций для тестирования
    const int list_size = 1000;       // Размер списка
    List list;

    // Добавление элементов в список
    for (int i = 0; i < list_size; ++i) {
        list.Append(i);
    }

    double total_duration = 0;
    for (int i = 0; i < num_iterations; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        method(list);  // Вызываем переданную функцию
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        total_duration += duration.count();
    }
    double average_duration = total_duration / num_iterations;
    std::cout << method_name << " time: " << std::scientific << std::setprecision(5) << average_duration << " seconds" << std::endl;

}

TEST(ListPerformance, PerformanceTest) {
    // Вызов теста для метода Append
    TestPerformance([](List &list) {
        int itemToAppend = rand();
        list.Append(itemToAppend);
    }, "Append");

    // Вызов теста для метода GetElement
    TestPerformance([](List &list) {
        int index = rand() % list.Size();
        list.GetElement(index);
    }, "GetElement");

    // Вызов теста для метода SetElement
    TestPerformance([](List &list) {
        int index = rand() % list.Size();
        int value = rand();
        list.SetElement(index, value);
    }, "SetElement");

    // Вызов теста для метода IndexOf
    TestPerformance([](List &list) {
        int index = rand() % list.Size();
        list.IndexOf(list.GetElement(index));
    }, "IndexOf");


    // Вызов теста для метода Remove
    TestPerformance([](List &list) {
        int index = rand() % list.Size();
        list.Remove(list.GetElement(index));
    }, "Remove");

    TestPerformance([](List &list) {
        int indexToInsert = rand() % list.Size();
        int itemToInsert = rand();
        list.Insert(indexToInsert, itemToInsert);
    }, "Insert");


    // Вызов теста для метода Clear
    TestPerformance([](List &list) {
        list.Clear();
    }, "Clear");
}
