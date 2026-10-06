#include<stdio.h>
#include<windows.h>

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

    // Checking is the queue is full.
    if(que->rear == Capacity - 1){
        printf("Queue is full!\n");
        return 0;
    }

    if(que->front == -1 && que->rear == -1){
        que->items[++(que->rear)] = newItem;
        (que->front)++;
        return 1;
    }
    que->items[++(que->rear)] = newItem;
}

int dequeue(Queue* que){
    
    // Check if the queue is empty.
    if((que->front > que->rear) || que->front == -1){
        printf("Queue is empty!\n");
        return -1;
    }

    return que->items[(que->front)++];
}

void Display(Queue *que){
    int start = que->front;
    int end = que->rear;

    for(int i = start; i <= end; i++){
        printf("%d ", que->items[i]);
    }
    printf("\n");
}

int main(){

    Queue que;
    initialize(&que);

    enqueue(&que, 2);
    enqueue(&que, 8);
    enqueue(&que, 9);
    enqueue(&que, 5);
    enqueue(&que, 7);
    enqueue(&que, 12);
    enqueue(&que, 87);
    enqueue(&que, 93);
    enqueue(&que, 10);
    enqueue(&que, 32);

    printf("%d \n", dequeue(&que));
    printf("%d \n", dequeue(&que));
    printf("%d \n", dequeue(&que));

    enqueue(&que, 8);
    enqueue(&que, 18);
    enqueue(&que, 38);

    Display(&que);

return 0;
}