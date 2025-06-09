#include "ListInt.hpp"
#include <stdexcept>
#include <algorithm>
#include <cstring>

ListInt::ListInt(long size)
    : capacity(size), count(0) {
    data = new int[capacity];
}

ListInt::ListInt(const ListInt& other)
    : capacity(other.capacity), count(other.count) {
    data = new int[capacity];
    std::copy(other.data, other.data + count, data);
}

ListInt::~ListInt() {
    delete[] data;
}

ListInt& ListInt::operator=(const ListInt& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        count = other.count;
        data = new int[capacity];
        std::copy(other.data, other.data + count, data);
    }
    return *this;
}

long ListInt::Count() const {
    return count;
}

int& ListInt::Get(long index) const {
    if (index < 0 || index >= count) throw std::out_of_range("Index out of bounds");
    return data[index];
}

int& ListInt::First() const {
    return Get(0);
}

int& ListInt::Last() const {
    return Get(count - 1);
}

bool ListInt::Includes(const int& item) const {
    for (long i = 0; i < count; ++i)
        if (data[i] == item) return true;
    return false;
}

void ListInt::Append(const int& item) {
    ensure_capacity(count + 1);
    data[count++] = item;
}

void ListInt::Prepend(const int& item) {
    ensure_capacity(count + 1);
    std::memmove(data + 1, data, sizeof(int) * count);
    data[0] = item;
    ++count;
}

void ListInt::Remove(const int& item) {
    for (long i = 0; i < count; ++i) {
        if (data[i] == item) {
            std::memmove(data + i, data + i + 1, sizeof(int) * (count - i - 1));
            --count;
            return;
        }
    }
}

void ListInt::RemoveLast() {
    if (count > 0) --count;
}

void ListInt::RemoveFirst() {
    if (count > 0) {
        std::memmove(data, data + 1, sizeof(int) * (count - 1));
        --count;
    }
}

void ListInt::RemoveAll() {
    count = 0;
}

int& ListInt::Top() const {
    return Last();
}

void ListInt::Push(const int& item) {
    Append(item);
}

int& ListInt::Pop() {
    if (count == 0) throw std::underflow_error("List is empty");
    --count;
    return data[count];
}

void ListInt::ensure_capacity(long min_capacity) {
    if (min_capacity > capacity) {
        long new_capacity = std::max(min_capacity, capacity * 2);
        int* new_data = new int[new_capacity];
        std::copy(data, data + count, new_data);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}
