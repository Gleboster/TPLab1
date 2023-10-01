#include "List.h"


List::List() : data(new Queue<int>()) {}

List::List(int *elements, int countElements) : List() {
    for (int i = 0; i < countElements; ++i) {
        Append(elements[i]);
    }
}

List::List(const List &other) : List() {
    for (const auto &item: other) {
        Append(item);
    }
}

void List::SetElement(int index, int value) {
    CheckIndex(index);

    Remove(index);
    Insert(index, value);
}

int List::GetElement(int index) const {
    CheckIndex(index);

    int element = Search(
            [&](int c_index, int c_item) { return c_index == index; },
            [](int c_index, int c_item) { return c_item; });

    return element;
}

void List::Append(int item) {
    data->Enqueue(item);
}

void List::Insert(int index, int item) {
    if (index == Size()){
        Append(item);
        return;
    }

    CheckIndex(index);

    auto newData = CopyDataUnder(index,
                                 [&](Queue<int> *copeOfData) { copeOfData->Enqueue(item); });

    delete data;
    data = newData;
}

void List::Remove(int item) {
    int index = IndexOf(item);
    if (index == -1)
        return;

    auto newData = CopyDataUnder(index, nullptr);

    delete data;
    data = newData;
}

int List::IndexOf(int item) const {
    int index = Search(
            [&](int c_index, int c_item) { return c_item == item; },
            [](int c_index, int c_item) { return c_index; });

    return index;
}

void List::Clear() {
    delete data;
    data = new Queue<int>();
}

bool List::IsEmpty() const {
    return data->IsEmpty();
}

int List::Size() const {
    return data->Size();
}

Queue<int>::Iterator List::begin() const {
    return data->begin();
}

Queue<int>::Iterator List::end() const {
    return data->end();
}

void List::CheckIndex(int index) const {
    if (index < 0 || index >= Size()) {
        throw std::out_of_range("Index out of range");
    }
}

int List::Search(std::function<bool(int, int)> predicateIndexItem, std::function<int(int, int)> returnedValue) const {
    int i = 0;
    for (const auto &element: *this) {
        if (predicateIndexItem(i, element))
            return returnedValue(i, element);
        i++;
    }
    return -1;
}

Queue<int> *
List::CopyDataUnder(int indexChanging, std::function<void(Queue<int> *)> actionCopyed) const {
    auto *copyOfData = new Queue<int>();

    auto it = begin();
    int i = 0;
    for (; it != end(); ++it, i++) {
        if (i == indexChanging) {
            if (actionCopyed != nullptr)
                actionCopyed(copyOfData);
            else
                continue;
        }
        copyOfData->Enqueue(*it);
    }

    return copyOfData;


/*    Queue<int> newData;

    auto it = begin();
    int i = 0;
    for (; it != end(); ++it, i++) {
        if (i == index)
            continue;
        newData.Enqueue(*it);
    }*/
}




