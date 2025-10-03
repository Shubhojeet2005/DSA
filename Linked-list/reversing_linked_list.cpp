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

void Reverse1(struct Node *p) {
    struct Node *q = p;
    int i = 0;
    int *A = new int[100];

    // Store data in array
    while (q != NULL) {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    // Assign data in reverse order
    while (q != NULL) {
        q->data = A[i];
        q = q->next;
        i--;
    }

    delete[] A;
}

void Reverse2(struct Node *p) {
    struct Node *q = NULL, *r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q,struct Node *p) {
    if(p) {
        Reverse3(p,p->next);
        p->next=q;

    } else{
        first=q;
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
    int A[] = {3, 5, 8, 9, 5, 4, 5};
    create(A, 7);
    cout<<endl;

    Display(first);

    Reverse2(first);
    Display(first);
  
    
    return 0;
}