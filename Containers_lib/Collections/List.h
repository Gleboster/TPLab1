#include <functional>
#include "Collection.h"
#include "Container_of_containers/Queue.h"

#ifndef LAB1_LIST_H
#define LAB1_LIST_H


class List : public Collection {
    Queue<int> *data;
public:

    List();

    List(int *elements, int countElements);

    List(const List &other);

    void SetElement(int index, int value);

    int GetElement(int index) const;

    void Append(int item);

    void Insert(int index, int item);

    int RemoveBy(int index);

    void Remove(int item);

    int IndexOf(int item) const;

    void Clear();

    bool IsEmpty() const;

    int Size() const;

    Queue<int>::Iterator begin() const;

    Queue<int>::Iterator end() const;

private:
    void CheckIndex(int index) const;

    int Search(std::function<bool(int, int)> predicateIndexItem, std::function<int(int, int)> returnedValue) const;
    Queue<int> *CopyDataUnder(int indexChanging, std::function<void(Queue<int> *)> actionCopyed) const;
};


#endif //LAB1_LIST_H
