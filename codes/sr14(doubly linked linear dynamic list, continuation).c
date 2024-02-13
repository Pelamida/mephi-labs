#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

//добавление элемента в начало списка
void add_to_head(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (tail == NULL) tail = new_node;
    
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    
    if (head != NULL) head->prev = new_node;
    head = new_node;
}

//добавление элемента в конец списка
void add_to_tail(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) head = new_node;
    
    new_node->data = data;
    new_node->prev = tail;
    new_node->next = NULL;
    
    if (tail != NULL) tail->next = new_node;
    tail = new_node;
}

//вывод всех элементов на экран в прямом порядке
void printer() {
    struct node* current = head;
    while (current != NULL) {
        printf("%4d", current->data);
        current = current->next;
    }
    printf("\n");
}

//поиск элемента с заданным значением
struct node* search(int value) {
    struct node* curr_el = head;
    while (curr_el != NULL) {
        if (curr_el->data == value) return curr_el;
        curr_el = curr_el->next;
    }
    return NULL;
}

//добавление элемента в список после заданного
void insert(struct node* node, int data) {
    if (node == NULL) {
        printf("error\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = node;
    new_node->next = node->next;

    if (node->next != NULL) node->next->prev = new_node;

    node->next = new_node;
}

//удаление заданного элемента из списка
void delete(struct node* node) {
    if (node == NULL) {
        printf("error\n");
        return;
    }

    if (node->prev != NULL) node->prev->next = node->next;
    else head = node->next;

    if (node->next != NULL) node->next->prev = node->prev;
    else tail = node->prev;

    free(node);
}


int main()
{
    int el, value, to_add;
    while (scanf("%d", &el)==1) add_to_tail(el);
    scanf("%*[^\n]");
    scanf("%d", &value);
    scanf("%d", &to_add);
	
	struct node* found = search(value);
	if (found == NULL) printer();
	else {
		insert(found, to_add);
		printer();
		delete(found);
		printer();
	}
	
    return 0;
}
