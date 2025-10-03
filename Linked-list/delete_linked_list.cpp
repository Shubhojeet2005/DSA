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

int Delete(struct Node *p,int pos) {
    struct Node *q;
    int x = -1;
    if(pos==1) {
        p=first;
        if (first != NULL) {
            x = first->data;
            first=first->next;
            delete p;
        }
        return x;
    }

    else{
        p=first;
        q=NULL;

        for(int i=0;i<pos-1 && p; i++) {
            q=p;
            p=p->next;
        }
       if(p) {
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
       }
    }
    return x;
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

    Delete(first,2);
    Display(first);
  
    
    return 0;
}