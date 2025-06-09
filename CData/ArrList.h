#ifndef ARRLIST_H
#define ARRLIST_H

#include <stddef.h>

typedef struct {
    int* data;          // 실제 데이터를 담는 배열
    size_t size;        // 현재 저장된 원소 개수
    size_t capacity;    // 총 할당된 배열 크기
} List;

void list_init(List* list);
void list_free(List* list);
void list_push_back(List* list, int value);
int  list_get(const List* list, size_t index);
size_t list_size(const List* list);

#endif // LIST_H
