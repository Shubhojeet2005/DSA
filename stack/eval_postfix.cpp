#include <iostream>
#include <cstring> 
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *t = new Node;
    if (t == NULL) {
        cout << "stack overflow";
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    int x = -1;
    if (top == NULL) {
        cout << "stack underflow";
    } else {
        Node *p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int stackTop() {
    if (top)
        return top->data;
    return -1;
}

int isEmpty() {
    return top ? 0 : 1;
}

int pre(char x) {
    if (x == '+' || x == '-') {
        return 1;
    } else if (x == '*' || x == '/') {
        return 2;
    } else {
        return 0;
    }
}

int isoperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    } else {
        return 1;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int Eval(char *postfix) {
int i,x1,x2,r;
for(int i=0;postfix[i]!='\0';i++) {
    if(isoperand(postfix[i])) {
        push(postfix[i]);
    } else{
        x2=pop();
        x1=pop();

        switch(postfix[i]) {
            case '+' : r=x1+x2; break;
            case '-' : r=x1-x2; break;
            case '*' : r=x1*x2; break;
            case '/' : r=x1/x2; break;
        }
        push(r);
    }
}
return top->data;
}



int main() {
   
    char *postfix = "234*+82/";
    cout<<Eval(postfix);
    delete[] postfix; 
    return 0;
}