#include <stdexcept>  // for exception handling
#include <iostream>   // for debugging (if needed)

template <class Item>
Stack<Item>::Stack(long size) : capacity(size), count(0) {
    data = new Item[capacity];
}

template <class Item>
Stack<Item>::Stack(const Stack& other) : capacity(other.capacity), count(other.count) {
    data = new Item[capacity];
    for (long i = 0; i < count; ++i) {
        data[i] = other.data[i];  // Deep copy of the elements
    }
}

template <class Item>
Stack<Item>::~Stack() {
    delete[] data;
}

template <class Item>
Stack<Item>& Stack<Item>::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        count = other.count;
        data = new Item[capacity];
        for (long i = 0; i < count; ++i) {
            data[i] = other.data[i];  // Deep copy of the elements
        }
    }
    return *this;
}

// Accessing
template <class Item>
long Stack<Item>::Count() const {
    return count;
}

template <class Item>
Item& Stack<Item>::Top() const {
    if (count == 0) {
        throw std::underflow_error("Stack is empty");
    }
    return data[count - 1];
}

template <class Item>
bool Stack<Item>::IsEmpty() const {
    return count == 0;
}

// Modifying
template <class Item>
void Stack<Item>::Push(const Item& item) {
    ensure_capacity(count + 1);
    data[count++] = item;  // Add item to the top of the stack
}

template <class Item>
Item Stack<Item>::Pop() {
    if (count == 0) {
        throw std::underflow_error("Stack is empty");
    }
    return data[--count];  // Remove and return the top item
}

template <class Item>
void Stack<Item>::ensure_capacity(long min_capacity) {
    if (min_capacity > capacity) {
        long new_capacity = capacity * 2;
        if (new_capacity < min_capacity) {
            new_capacity = min_capacity;
        }
        Item* new_data = new Item[new_capacity];
        for (long i = 0; i < count; ++i) {
            new_data[i] = data[i];  // Copy data to new larger array
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}
