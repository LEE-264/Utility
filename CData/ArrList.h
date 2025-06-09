#ifndef ARRLIST_H
#define ARRLIST_H

#include <stddef.h>

typedef struct {
    int* data;          // 실제 데이터를 담는 배열
    size_t size;        // 현재 저장된 원소 개수
    size_t capacity;    // 총 할당된 배열 크기
} ArrList;

void arrlist_init(ArrList* list);
void arrlist_free(ArrList* list);
void arrlist_push_back(ArrList* list, int value);
int  arrlist_get(const ArrList* list, size_t index);
size_t arrlist_size(const ArrList* list);

#endif // ARRLIST_H
