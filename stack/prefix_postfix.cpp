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

char *convert(char *infix) {
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = new char[len + 1];

    while (infix[i] != '\0') {
        if (isoperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (pre(infix[i]) > pre(stackTop())) {
                push(infix[i++]);
            } else {
                postfix[j++] = pop();
            }
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[] = "a+b*c"; 
    char *postfix = convert(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    delete[] postfix; 
    return 0;
}