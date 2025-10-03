#include<iostream>
using namespace std;

struct Queue {
    int front;
    int rear;
    int size;
    int *Q;
};

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new int[size];
}

void enqueue(struct Queue *q, int x) {
    if((q->rear + 1) % q->size == q->front) {
        cout << "Queue is full\n";
    }
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if(q->front == q->rear) {
        cout << "Queue is empty\n";
    }
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue *q) {
    if(q->front == q->rear) {
        cout << "Queue is empty\n";
        return;
    }
    
    int i = (q->front + 1) % q->size;
    cout << "Queue elements: ";
    do {
        cout << q->Q[i] << " ";
        i = (i + 1) % q->size;
    } while(i != (q->rear + 1) % q->size);
    cout << endl;
}

int main() {
    Queue q;
    create(&q, 5);  // Queue of size 5

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);  // Shows 10 20 30 40

    cout << "Dequeued: " << dequeue(&q) << endl;  // Removes 10
    cout << "Dequeued: " << dequeue(&q) << endl;  // Removes 20

    display(&q);  // Shows 30 40

    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);  // This will fail (queue full)

    display(&q);  // Shows 30 40 50 60

    return 0;
}