#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct List {
    struct ListNode* head;
};

struct List* create_list() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

//добавление элемента в начало списка
void add_to_head(struct List* list, int newData) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = newData;
    newNode->next = list->head;

    list->head = newNode;
}

//добавление элемента в конец списка
void add_to_tail(struct List* list, int newData) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = newData;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct ListNode* current = list->head;
    while (current->next != NULL) current = current->next;

    current->next = newNode;
}

//удаление элемента из начала списка
void delete_head(struct List* list) {
    struct ListNode* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

//удаление элемента с конца списка
void delete_tail(struct List* list) {
    struct ListNode* current = list->head;
    struct ListNode* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) list->head = NULL;
    else previous->next = NULL;
    free(current);
}

//вывод всех элементов списка
void print_list(struct List* list) {
    struct ListNode* current = list->head;

    while (current != NULL) {
        printf("%4d", current->data);
        current = current->next;
    }
    printf("\n");
}

//поиск элемента с заданным значением в списке
struct ListNode* search_element(struct List* list, int target) {
    struct ListNode* current = list->head;

    while (current != NULL) {
        if (current->data == target) return current;
        current = current->next;
    }

    return NULL;
}

//добавление элемента после данного
void insert(struct ListNode* prevNode, int newData) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int main() {
    struct List* list = create_list();
    int el, value, to_insert;
    while (scanf("%d", &el) == 1) add_to_head(list, el);
    scanf("%*[^\n]");
    scanf("%d", &value);
    scanf("%d", &to_insert);

    struct ListNode* found = search_element(list, value);
	if (found != NULL) insert(found, to_insert);

	print_list(list);

    return 0;
}

