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

void display(struct  Node *p) {
    while(p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int isBalance(char *exp) {
    for(int i=0; exp[i]!='\0';i++) {
        if(exp[i]=='(') push(exp[i]);
        else if(exp[i]==')') {
            if(top==NULL) {
            return false;
            }else{
            pop();
        }
        } 
    }
    if(top==NULL)
    return 1;
    else 
    return 0;
}
int main() {

    
char *exp="((a+b)*(c-d))";
cout<<isBalance(exp);
display(top);
}



