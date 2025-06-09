#include "LinkedList.h"
#include <stdlib.h>

void linkedlist_init(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

void linkedlist_free(LinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}

void linkedlist_push_front(LinkedList* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void linkedlist_push_back(LinkedList* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

int linkedlist_get(const LinkedList* list, size_t index) {
    if (index >= list->size) return 0;

    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void linkedlist_remove_at(LinkedList* list, size_t index) {
    if (index >= list->size) return;

    Node* current = list->head;
    if (index == 0) {
        list->head = current->next;
        free(current);
    } else {
        Node* prev = NULL;
        for (size_t i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
    }
    list->size--;
}

size_t linkedlist_size(const LinkedList* list) {
    return list->size;
}
