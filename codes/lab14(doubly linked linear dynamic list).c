#include <stdio.h>
#include <stdlib.h>

struct node
{
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

//удаление элемента из начала списка
void delete_from_head() {
    if (head == NULL) return;
    
    struct node* temp = head;
    head = head->next;
    
    if (head != NULL) head->prev = NULL;
    free(temp);
}

//удаление элемента из конца списка
void delete_from_tail() {
    if (tail == NULL) return;
    
    struct node* temp = tail;
    tail = tail->prev;
    
    if (tail != NULL) tail->next = NULL;
    free(temp);
}

//вывод всех элементов на экран в прямом порядке
void printer_forward()
{
    int sum = 0;
    struct node* current = head;
    while (current != NULL) {
        printf("%4d", current->data);
        sum++;
        current = current->next;
    }
    printf("\n");
}

//вывод всех элементов на экран в обратном порядке
void printer_backward() {
    struct node* current = tail;
    while (current != NULL) {
        printf("%4d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

//определение количества всех элементов
void count_of_el() {
    int sum = 0;
    struct node* curr_el = head;
    while (curr_el != NULL) {
        sum++;
        curr_el = curr_el->next;
    }
    printf("%d\n", sum);
}


int main()
{
    int el;
    while (scanf("%d", &el)==1) add_to_tail(el);

    delete_from_head();
    delete_from_head();
    
    printer_forward();
    count_of_el();
    return 0;
}
