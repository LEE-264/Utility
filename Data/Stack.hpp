#ifndef STACK_HPP
#define STACK_HPP

#define DEFAULT_STACK_CAPACITY 10

template <class Item>
class Stack {
public:
    // Construction, Destruction, Initialization, and Assignment
    Stack(long size = DEFAULT_STACK_CAPACITY);
    Stack(const Stack& other);
    ~Stack();
    Stack& operator=(const Stack& other);

    // Accessing
    long Count() const;
    Item& Top() const;
    bool IsEmpty() const;

    // Modifying
    void Push(const Item& item);
    Item Pop();

private:
    Item* data;
    long capacity;
    long count;

    void ensure_capacity(long min_capacity);
};

#include "Stack.tpp"

#endif
