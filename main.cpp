#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Container_of_containers/Queue.h"
#include "Collections/Stack.h"
#include "Collections/List.h"
#include "Collections/Deque.h"
#include "Serialization/Deserializator.h"
#include "Serialization/Serializator.h"

const std::string filename = "C:\\Users\\glebl\\CLionProjects\\Lab1\\SerializedCollections";
Queue<Collection *> *MainQueue;
Stack *stack;
List *list;
Deque *deque;

void Pause() {
    system("pause");
}

void Clear() {
    system("cls");
    Sleep(100);
}

namespace ApplicationAction {
    int GetApplicationActionChoice() {
        int choice;
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        std::cout << "1. Изменить Стек" << std::endl;
        std::cout << "2. Изменить Лист" << std::endl;
        std::cout << "3. Изменить Дэк" << std::endl;
        std::cout << "4. Вывести очередь на экран" << std::endl;
        std::cout << "5. Сохранить очередь в файл" << std::endl;
        std::cin >> choice;
        return choice;
    }

    namespace StackAction {
        int GetStackActionChoice() {
            int choice;
            std::cout << "Выберите действие:" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "1. Засунуть в стек" << std::endl;
            std::cout << "2. Высунуть из стека" << std::endl;
            std::cout << "3. Посмотреть последний элемент" << std::endl;
            std::cin >> choice;
            return choice;
        }

        void PushToStack(Stack &stack) {
            int value;
            std::cout << "Введите значение для добавления в стек: ";
            std::cin >> value;
            stack.Push(value);
            std::cout << "Значение успешно добавлено в стек." << std::endl;
        }

        void PopFromStack(Stack &stack) {
            try {
                int value = stack.Pop();
                std::cout << "Извлечено значение из стека: " << value << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void PeekAtStack(const Stack &stack) {
            try {
                int value = stack.Peek();
                std::cout << "Последний элемент в стеке: " << value << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void PrintStack(const Stack &stack) {
            std::cout << "Содержимое стека:" << std::endl;
            if (stack.IsEmpty()) {
                std::cout << "Стек пуст." << std::endl;
            } else {
                Serializator serializator;
                std::cout << serializator.Serialize(stack) << std::endl;
            }
        }

        void RunStackAction(Stack &stack) {
            while (true) {
                Clear();
                PrintStack(stack);
                int choice = GetStackActionChoice();

                switch (choice) {
                    case 0:
                        std::cout << "Выход из работы со стеком." << std::endl;
                        return;
                    case 1:
                        PushToStack(stack);
                        break;
                    case 2:
                        PopFromStack(stack);
                        break;
                    case 3:
                        PeekAtStack(stack);
                        break;
                    default:
                        std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
                }
                Pause();
            }
        }
    }

    namespace ListAction {
        int GetListActionChoice() {
            int choice;
            std::cout << "Выберите действие для работы с листом:" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "1. Добавить элемент" << std::endl;
            std::cout << "2. Вставить элемент на определенное место" << std::endl;
            std::cout << "3. Установить значение по индексу" << std::endl;
            std::cout << "4. Получить значение по индексу" << std::endl;
            std::cout << "5. Удалить элемент по индексу" << std::endl;
            std::cout << "6. Удалить элемент" << std::endl;
            std::cout << "7. Найти элемент" << std::endl;
            std::cin >> choice;
            return choice;
        }

        void AddToList(List &list) {
            int value;
            std::cout << "Введите значение для добавления в лист: ";
            std::cin >> value;
            list.Append(value);
            std::cout << "Значение успешно добавлено в лист." << std::endl;
        }

        void InsertToList(List &list) {
            int value, index;
            std::cout << "Введите индекс для вставки: ";
            std::cin >> index;
            std::cout << "Введите значение для вставки в лист: ";
            std::cin >> value;
            try {
                list.Insert(index, value);
                std::cout << "Значение успешно вставлено в лист." << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void SetValueAtIndex(List &list) {
            int value, index;
            std::cout << "Введите индекс для установки значения: ";
            std::cin >> index;
            std::cout << "Введите значение для установки: ";
            std::cin >> value;
            try {
                list.SetElement(index, value);
                std::cout << "Значение успешно установлено." << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void GetValueAtIndex(const List &list) {
            int index;
            std::cout << "Введите индекс для получения значения: ";
            std::cin >> index;
            try {
                int value = list.GetElement(index);
                std::cout << "Значение по индексу " << index << ": " << value << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void RemoveFromListByIndex(List &list) {
            int index;
            std::cout << "Введите индекс для удаления элемента из списка: ";
            std::cin >> index;
            try {
                int removed = list.RemoveBy(index);
                std::cout << "Элемент по индексу " << index << ": " << removed <<"успешно удален." << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void RemoveFromList(List &list) {
            int element;
            std::cout << "Введите элемент для удаления из списка: ";
            std::cin >> element;
            try {
                list.Remove(element);
                std::cout << "Элемент успешно удален." << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void FindInList(const List &list) {
            int value;
            std::cout << "Введите значение для поиска: ";
            std::cin >> value;
            int index = list.IndexOf(value);
            if (index != -1) {
                std::cout << "Элемент найден по индексу: " << index << std::endl;
            } else {
                std::cout << "Элемент не найден." << std::endl;
            }
        }

        void PrintList(const List &list) {
            std::cout << "Содержимое листа:" << std::endl;
            if (list.IsEmpty()) {
                std::cout << "Лист пуст." << std::endl;
            } else {
                Serializator serializator;
                std::cout << serializator.Serialize(list) << std::endl;
            }
        }

        void RunListAction(List &list) {
            while (true) {
                Clear();
                PrintList(list);
                int choice = GetListActionChoice();

                switch (choice) {
                    case 0:
                        std::cout << "Выход из работы с листом." << std::endl;
                        return;
                    case 1:
                        AddToList(list);
                        break;
                    case 2:
                        InsertToList(list);
                        break;
                    case 3:
                        SetValueAtIndex(list);
                        break;
                    case 4:
                        GetValueAtIndex(list);
                        break;
                    case 5:

                        break;
                    case 6:
                        RemoveFromList(list);
                        break;
                    case 7:
                        FindInList(list);
                        break;
                    default:
                        std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
                        break;
                }
                Pause();
            }
        }
    }

    namespace DequeAction {

        int GetDequeActionChoice() {
            int choice;
            std::cout << "Выберите действие для работы с деком:" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "1. Добавить в начало" << std::endl;
            std::cout << "2. Добавить в конец" << std::endl;
            std::cout << "3. Удалить из начала" << std::endl;
            std::cout << "4. Удалить с конца" << std::endl;
            std::cout << "5. Посмотреть в начало" << std::endl;
            std::cout << "6. Посмотреть в конец" << std::endl;
            std::cin >> choice;
            return choice;
        }

        void AddToFront(Deque &deque) {
            int value;
            std::cout << "Введите значение для добавления в начало: ";
            std::cin >> value;
            deque.AddFront(value);
        }

        void AddToRear(Deque &deque) {
            int value;
            std::cout << "Введите значение для добавления в конец: ";
            std::cin >> value;
            deque.AddRear(value);
        }

        void RemoveFromFront(Deque &deque) {
            try {
                std::cout << "Из дэка достан элемент из начала: " << deque.RemoveFront() << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void RemoveFromRear(Deque &deque) {
            try {
                std::cout << "Из дэка достан элемент с конца: " << deque.RemoveRear() << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void PeekRear(const Deque &deque) {
            try {
                int value = deque.PeekRear();
                std::cout << "Элемент в конце дека: " << value << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void PeekFront(const Deque &deque) {
            try {
                int value = deque.PeekFront();
                std::cout << "Элемент в начале дека: " << value << std::endl;
            } catch (const std::out_of_range &ex) {
                std::cerr << ex.what() << std::endl;
            }
        }

        void PrintDeque(const Deque &deque) {
            std::cout << "Содержимое дека:" << std::endl;
            if (deque.IsEmpty()) {
                std::cout << "Дек пуст." << std::endl;
            } else {
                Serializator serializator;
                std::cout << serializator.Serialize(deque) << std::endl;
            }
        }

        void RunDequeAction(Deque &deque) {
            while (true) {
                Clear();
                PrintDeque(deque);
                int choice = GetDequeActionChoice();

                switch (choice) {
                    case 0:
                        std::cout << "Выход из работы с деком." << std::endl;
                        return;
                    case 1:
                        AddToFront(deque);
                        break;
                    case 2:
                        AddToRear(deque);
                        break;
                    case 3:
                        RemoveFromFront(deque);
                        break;
                    case 4:
                        RemoveFromRear(deque);
                        break;
                    case 5:
                        PeekRear(deque);
                        break;
                    case 6:
                        PeekFront(deque);
                        break;
                    default:
                        std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
                }
                Pause();
            }
        }
    }

    void PrintMainQueue() {
        std::cout << "Текущая очередь имеет вид: " << std::endl;

        Serializator serializator;
        std::cout << "Stack: " << serializator.Serialize(*stack) << std::endl;
        std::cout << "List: " << serializator.Serialize(*list) << std::endl;
        std::cout << "Deque: " << serializator.Serialize(*deque) << std::endl;
    }

    void SaveMainQueueToFile() {
        std::ofstream outputFile(filename);

        Serializator serializator;
        outputFile << serializator.Serialize(*stack) << std::endl;
        outputFile << serializator.Serialize(*list) << std::endl;
        outputFile << serializator.Serialize(*deque) << std::endl;
        std::cout << "Коллекции сохранены в файл" << std::endl;
    }

    void RunApplicationAction() {
        while (true) {
            Clear();
            int choice = GetApplicationActionChoice();

            switch (choice) {
                case 0:
                    std::cout << "Программа завершена." << std::endl;
                    return;
                case 1:
                    StackAction::RunStackAction(*stack);
                    break;
                case 2:
                    ListAction::RunListAction(*list);
                    break;
                case 3:
                    DequeAction::RunDequeAction(*deque);
                    break;
                case 4:
                    PrintMainQueue();
                    break;
                case 5:
                    SaveMainQueueToFile();
                    break;
                default:
                    std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
            }
            Pause();
        }
    }

    namespace QueueCreation {

        int GetQueueCreationChoice() {
            int choice;
            std::cout << "Выберите действие:" << std::endl;
            std::cout << "1. Создать новую очередь коллекций" << std::endl;
            std::cout << "2. Прочитать очередь из файла" << std::endl;
            std::cin >> choice;
            return choice;
        }

        Queue<Collection *> *GetMainQueueFromFile() {
            std::ifstream inputFile(filename);

            Queue<Collection *> *mainQueue = new Queue<Collection *>();

            Deserializator deserializator;
            std::string *lines = new std::string[3];
            std::cout << "Из файла считаны строки:" << std::endl;
            for (int i = 0; i < 3 && !inputFile.eof(); i++) {
                std::getline(inputFile, lines[i]);
                std::cout << lines[i] << std::endl;
            }

            stack = deserializator.DeserializeAsStack(lines[0]);
            list = deserializator.DeserializeAsList(lines[1]);
            deque = deserializator.DeserializeAsDeque(lines[2]);

            mainQueue->Enqueue(stack);
            mainQueue->Enqueue(list);
            mainQueue->Enqueue(deque);

            std::cout << "Очередь прочитана" << std::endl;
            return mainQueue;
        }

        Queue<Collection *> *CreateNewMainQueue() {
            Queue<Collection *> *mainQueue = new Queue<Collection *>();

            stack = new Stack();
            list = new List();
            deque = new Deque();

            mainQueue->Enqueue(stack);
            mainQueue->Enqueue(list);
            mainQueue->Enqueue(deque);

            std::cout << "Пустая очередь создана" << std::endl;
            return mainQueue;
        }

        void RunQueueCreation() {
            while (true) {
                Clear();
                int choice = GetQueueCreationChoice();

                switch (choice) {
                    case 1:
                        MainQueue = CreateNewMainQueue();
                        Pause();
                        return;
                    case 2:
                        MainQueue = GetMainQueueFromFile();
                        PrintMainQueue();
                        Pause();
                        return;
                    default:
                        std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
                        break;
                }
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ApplicationAction::QueueCreation::RunQueueCreation();

    ApplicationAction::RunApplicationAction();


    Pause();
}
