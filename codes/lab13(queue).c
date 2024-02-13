#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* head;
    struct QueueNode* tail;
};

//создание пустой очереди
struct Queue* create_queue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

//добавление элемента в очередь
void add_el(struct Queue* queue, int newData) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = newData;
    newNode->next = NULL;

    if (queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
        return;
    }

    queue->tail->next = newNode;
    queue->tail = newNode;
}

//удаление элемента из очереди
void delete_el(struct Queue* queue) {
    struct QueueNode* temp = queue->head;
    queue->head = queue->head->next;

    // Если после удаления очередь пуста, обновляем указатель на последний элемент
    if (queue->head == NULL)
        queue->tail = NULL;

    free(temp);
}

//вывод всех элементов очереди
void printer(struct Queue* queue) {
    struct QueueNode* current = queue->head;

    while (current != NULL) {
        printf("%4d", current->data);
        current = current->next;
    }
    printf("\n");
}

//определение количества всех элементов в очереди
int count_of_el(struct Queue* queue) {
    int count = 0;
    struct QueueNode* current = queue->head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

//добавление n элементов со случайными значениями из интервала [a; b] в очередь
void add_random(struct Queue* queue, int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        int randomNumber = (rand() % (b - a + 1)) + a;
        add_el(queue, randomNumber);
    }
}

//удаление всей очереди
void delete_queue(struct Queue* queue) {
    struct QueueNode* current = queue->head;
    while (current != NULL) {
        delete_el(queue);
        current = queue->head;
    }
    free(queue);
}

int main() {
    struct Queue* queue = create_queue();
    int el;
    while (scanf("%d", &el)==1) add_el(queue, el);
    
    delete_el(queue);
    delete_el(queue);
    printer(queue);

    int count = count_of_el(queue);
    printf("%d\n", count);
    
    return 0;
}
