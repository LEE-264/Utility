#include "ArrList.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 4

void arrlist_init(ArrList* list) {
    list->data = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

void arrlist_free(ArrList* list) {
    if (list->data) {
        free(list->data);
        list->data = NULL;
    }
    list->size = 0;
    list->capacity = 0;
}

void arrlist_push_back(ArrList* list, int value) {
    if (list->size >= list->capacity) {
        size_t new_capacity = list->capacity * 2;
        int* new_data = (int*)realloc(list->data, sizeof(int) * new_capacity);
        if (!new_data) return; // 메모리 부족 시 안전하게 리턴
        list->data = new_data;
        list->capacity = new_capacity;
    }
    list->data[list->size++] = value;
}

int arrlist_get(const ArrList* list, size_t index) {
    if (index >= list->size) {
        return 0; // 범위 초과 시 0 반환 (상황에 따라 assert 또는 에러 코드 권장)
    }
    return list->data[index];
}

size_t arrlist_size(const ArrList* list) {
    return list->size;
}
