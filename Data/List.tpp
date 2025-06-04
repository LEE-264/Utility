#include <stdexcept>
#include <iostream>

template <class Item>
List<Item>::List(long size) : capacity(size), count(0) {
    data = new Item[capacity];
}

template <class Item>
List<Item>::List(List& other) : capacity(other.capacity), count(other.count) {
    data = new Item[capacity];
    for (long i = 0; i < count; ++i)
        data[i] = other.data[i];
}

template <class Item>
List<Item>::~List() {
    delete[] data;
}

template <class Item>
List<Item>& List<Item>::operator=(const List& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        count = other.count;
        data = new Item[capacity];
        for (long i = 0; i < count; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

template <class Item>
long List<Item>::Count() const {
    return count;
}

template <class Item>
Item& List<Item>::Get(long index) const {
    if (index < 0 || index >= count)
        throw std::out_of_range("Invalid index");
    return data[index];
}

template <class Item>
Item& List<Item>::First() const {
    return Get(0);
}

template <class Item>
Item& List<Item>::Last() const {
    return Get(count - 1);
}

template <class Item>
bool List<Item>::Includes(const Item& item) const {
    for (long i = 0; i < count; ++i)
        if (data[i] == item) return true;
    return false;
}

template <class Item>
void List<Item>::Append(const Item& item) {
    ensure_capacity(count + 1);
    data[count++] = item;
}

template <class Item>
void List<Item>::Prepend(const Item& item) {
    ensure_capacity(count + 1);
    for (long i = count; i > 0; --i)
        data[i] = data[i - 1];
    data[0] = item;
    ++count;
}

template <class Item>
void List<Item>::Remove(const Item& item) {
    for (long i = 0; i < count; ++i) {
        if (data[i] == item) {
            for (long j = i; j < count - 1; ++j)
                data[j] = data[j + 1];
            --count;
            return;
        }
    }
}

template <class Item>
void List<Item>::RemoveLast() {
    if (count > 0) --count;
}

template <class Item>
void List<Item>::RemoveFirst() {
    if (count > 0) {
        for (long i = 0; i < count - 1; ++i)
            data[i] = data[i + 1];
        --count;
    }
}

template <class Item>
void List<Item>::RemoveAll() {
    count = 0;
}

template <class Item>
Item& List<Item>::Top() const {
    return Last();
}

template <class Item>
void List<Item>::Push(const Item& item) {
    Append(item);
}

template <class Item>
Item& List<Item>::Pop() {
    if (count == 0)
        throw std::underflow_error("Pop from empty list");
    --count;
    return data[count];
}

template <class Item>
void List<Item>::ensure_capacity(long min_capacity) {
    if (min_capacity > capacity) {
        long new_capacity = capacity * 2;
        if (new_capacity < min_capacity)
            new_capacity = min_capacity;
        Item* new_data = new Item[new_capacity];
        for (long i = 0; i < count; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}
