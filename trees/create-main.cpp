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

void preorder(struct Node *p) {
    if(p) {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p) {
    if(p) {
       
        inorder(p->lchild);
         cout << p->data << " ";
        inorder(p->rchild);
    }
}


void postorder(struct Node *p) {
    if(p) {
       
        postorder(p->lchild);
        postorder(p->rchild);
         cout << p->data << " ";
    }
}

int main() {
    createTree();
    cout << "Preorder traversal: ";
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}