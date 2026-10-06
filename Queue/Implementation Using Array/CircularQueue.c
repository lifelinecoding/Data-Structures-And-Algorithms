#include <stdio.h>
#include <windows.h>

#define Capacity 10

struct Queue{
    int items[Capacity];
    int front;
    int rear;
};

typedef struct Queue Queue;

void initialize(Queue *que){
    que->front = -1;
    que->rear = -1;
}

int enqueue(Queue *que, int newItem){

    if ((que->rear + 1) % Capacity == que->front){
        printf("Queue is full!\n");
        return 0;
    }

    if (que->front == -1 && que->rear == -1){
        que->rear = (que->rear + 1);
        que->front = (que->front + 1);
        que->items[que->rear] = newItem;
        return 1;
    }

    que->rear = (que->rear + 1) % Capacity;
    que->items[que->rear] = newItem;
    return 1;
}

int dequeue(Queue *que){

    if (que->front == -1){
        printf("Queue is empty!\n");
        return -1;
    }

    int value = que->items[que->front];

    if (que->rear == que->front){
        initialize(que);
    }
    else{
        que->front = (que->front + 1) % Capacity;
    }
    return value;
}

void Display(Queue *que){
    int start = que->front;

    if (start == -1)
        return;

    while(1){
        printf("%d ", que->items[start]);
        if (start == que->rear)
            break;
        start = (start + 1) % Capacity;
    }
    printf("\n");
}

int main(){
    Queue que;
    initialize(&que);

    enqueue(&que, 8);
    enqueue(&que, 2);
    enqueue(&que, 1);
    enqueue(&que, 3);
    enqueue(&que, 9);
    enqueue(&que, 6);
    enqueue(&que, 63);
    enqueue(&que, 45);
    enqueue(&que, 45);
    enqueue(&que, 45);

    dequeue(&que);
    dequeue(&que);
    dequeue(&que);
    dequeue(&que);
    dequeue(&que);
    dequeue(&que);
    dequeue(&que);
    dequeue(&que);
    dequeue(&que);
    dequeue(&que);

    enqueue(&que, 45);
    enqueue(&que, 45);
    enqueue(&que, 45);

    Display(&que);

    return 0;
}
