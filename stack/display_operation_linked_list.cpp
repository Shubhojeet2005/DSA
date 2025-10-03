#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}  *top = NULL;

void push(int x) {
    struct Node *t;
    t= new Node;
    if(t==NULL) {
        cout<<"stack is full";
    } else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop() {
    int x = -1;

    if (top == NULL) {
        cout << "stack empty";
    } else {
        Node *p = top;
        top = top->next;

        x = p->data;
        delete p;
    }
    return x;
}

int stackTop() {
    if(top)
        return top->data;
    return -1;
}

void display(struct  Node *p) {
    while(p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
int main() {
push(10);
push(20);
pop();
display(top);
}



