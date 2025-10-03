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

void RemoveDuplicate(struct Node *p) {
    struct Node *q= p->next;
    while(p!=NULL) {
        if(p->data!=q->data) {
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
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

    RemoveDuplicate(first);
    Display(first);
  
    
    return 0;
}