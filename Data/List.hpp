#ifndef LIST_HPP
#define LIST_HPP

#define DEFAULT_LIST_CAPACITY 10

template <class Item>
class List {
public:
    List(long size = DEFAULT_LIST_CAPACITY);
    List(List& other);
    ~List();
    List& operator=(const List& other);

    long Count() const;
    Item& Get(long index) const;
    Item& First() const;
    Item& Last() const;
    bool Includes(const Item&) const;

    void Append(const Item&);
    void Prepend(const Item&);

    void Remove(const Item&);
    void RemoveLast();
    void RemoveFirst();
    void RemoveAll();

    Item& Top() const;
    void Push(const Item&);
    Item& Pop();

private:
    Item* data;
    long capacity;
    long count;

    void ensure_capacity(long min_capacity);
};

#include "List.tpp"

#endif
