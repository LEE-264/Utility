#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

// 노드 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 연결 리스트 구조체
typedef struct {
    Node* head;
    size_t size;
} LinkedList;

// 함수 선언
void linkedlist_init(LinkedList* list);
void linkedlist_free(LinkedList* list);

void linkedlist_push_front(LinkedList* list, int value);
void linkedlist_push_back(LinkedList* list, int value);
int  linkedlist_get(const LinkedList* list, size_t index);
void linkedlist_remove_at(LinkedList* list, size_t index);
size_t linkedlist_size(const LinkedList* list);

#endif // LINKEDLIST_H
