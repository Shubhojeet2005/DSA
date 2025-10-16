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

void SortedInsert(struct Node *p,int x) {
  struct Node *t, *q=NULL; 
  t=new Node;
  t->data=x;
  t->next=NULL;

  if(first==NULL) {
    first=t;
  } else{
     while(p && p->data<x) {
        q=p;
        p=p->next;
     }
     if(p==first) {
        t->next=first;
        first=t;
     } else{
       t->next=q->next;
       q->next=t;
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
    int A[] = {2,3,5,8,9,10,12};
    create(A, 7);
    SortedInsert(first,7);

    Display(first);

    
 
  
    
    return 0;
}

