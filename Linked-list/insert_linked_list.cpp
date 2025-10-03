#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first=NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(struct Node *p, int key, int pos) { 
    Node *t;
    if(pos == 0) {
        t = new Node;
        t->data = key;
        t->next = first;
        first = t;
    }
    else if(pos > 0) {
        p = first;
        for(int i = 0; i < pos-1 && p; i++) {
            p = p->next;
        }
        if(p) {
            t = new Node;
            t->data = key;
            t->next = p->next;
            p->next = t;
        }
        // If p is NULL, position is out of bounds; do nothing or handle error as needed.
    }
}

void Display(struct Node *p) {
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int A[] = {3, 5, 8, 9, 5, 4, 6};
    create(A, 7);

    Display(first);
    insert(first, 25, 2);
    Display(first); // Display after insertion to see the result
    
    return 0;
}