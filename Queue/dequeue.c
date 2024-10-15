#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct de {
    int n;
    int front;
    int rear;
    int *arr;
} de;

de* createde(int n) {
    de *q = (de*)malloc(sizeof(de));
    if (q == NULL) {
        return NULL;
    }
    q->arr = (int *)malloc(n * sizeof(int));
    if (q->arr == NULL) {
        free(q);
        return NULL;
    }
    q->n = n;
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueuefront(de *q, int num) {
    if ((q->front == 0 && q->rear == q->n - 1) || (q->front == q->rear + 1)) {
        printf("Queue is Full\n");
        return;
    } else if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->arr[q->front] = num;
    } else if (q->front == 0) {
        q->front = q->n - 1;
        q->arr[q->front] = num;
    } else {
        q->front--;
        q->arr[q->front] = num;
    }
    printf("Enqueued at front: %d\n", num);
}

void enqueuerear(de *q, int num) {
    if ((q->front == 0 && q->rear == q->n - 1) || (q->front == q->rear + 1)) {
        printf("Queue is Full\n");
        return;
    } else if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->arr[q->rear] = num;
    } else if (q->rear == q->n - 1) {
        q->rear = 0;
        q->arr[q->rear] = num;
    } else {
        q->rear++;
        q->arr[q->rear] = num;
    }
    printf("Enqueued at rear: %d\n", num);
}

void dequeuefront(de *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Dequeued from front: %d\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == q->n - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
}

void dequeuerear(de *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Dequeued from rear: %d\n", q->arr[q->rear]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->rear == 0) {
        q->rear = q->n - 1;
    } else {
        q->rear--;
    }
}

void display(de *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is Empty\n");
        return;
    } else {
        int i = q->front;
        while (true) {
            printf("%d ", q->arr[i]);
            if (i == q->rear) break;
            i = (i + 1) % q->n;
        }
        printf("\n");
    }
}


int main() {
    int n = 5;
    de *q = createde(n);
    
    enqueuefront(q, 10);
    enqueuerear(q, 20);
    display(q);
    
    dequeuefront(q);
    display(q);
    
    enqueuerear(q, 30);
    display(q);
    
    dequeuerear(q);
    display(q);
    return 0;
}
