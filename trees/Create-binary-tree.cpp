#include<iostream>
using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    Node **Q;  // Pointer to an array of Node pointers
};

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;  // Initialize both to 0 (or -1 if you prefer)
    q->Q = new Node*[size];  // Allocate array of Node pointers
}

void enqueue(struct Queue *q, Node *x) {
    if((q->rear + 1) % q->size == q->front)
        cout << "Queue is full";
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node* dequeue(struct Queue *q) {  // Changed return type to Node*
    Node* x = NULL;
    if(q->front == q->rear) {  // Fixed assignment (=) to comparison (==)
        cout << "Queue is Empty";
    }
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}