#include<iostream>
#include<queue>
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
    Node **Q;  // Array to store Node pointers
};

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node*[q->size];
}

void enqueue(struct Queue *q, Node *x) {
    if((q->rear+1)%q->size == q->front)
        cout << "Queue is full\n";
    else {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

Node* dequeue(struct Queue *q) {
    Node* x = NULL;
    if(q->front == q->rear)
        cout << "Queue is empty\n";
    else {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

bool isEmpty(struct Queue q) {
    return q.front == q.rear;
}

struct Node *root = NULL;

void createTree() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);
    
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    
    while(!isEmpty(q)) {
        p = dequeue(&q);
        
        cout << "Enter left child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if(x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        
        cout << "Enter right child of " << p->data << " (-1 for no child): ";
        cin >> x;
        if(x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void LevelOrder(struct Node *p) {
    Queue q;
    createQueue(&q, 100); // Initialize the queue before use
    if (p == NULL) return;
    cout << p->data << " ";
    enqueue(&q, p);
    while (!isEmpty(q)) {
        p = dequeue(&q);
        if (p->lchild) {
            cout << p->lchild->data << " ";
            enqueue(&q, p->lchild);
        }
        if (p->rchild) {
            cout << p->rchild->data << " ";
            enqueue(&q, p->rchild);
        }
    }
}
int main() {
    createTree();
    LevelOrder(root);
   
}