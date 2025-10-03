#include<iostream>
using namespace std;
struct Node {
struct Node *prev;
int data;
struct Node *next;
}*first=NULL;


void create(int A[],int n) { 
 struct Node *t,*last;
 int i;
 first= new Node;
 first->prev=first->next=NULL;
 last = first;

 for(int i=1;i<n;i++) {
    t=new Node;
    t->data=A[i];
    t->next=last->next;
    t->prev=last;
    last->next=t;
    last=t;
 }
}

void display(struct Node *p) {
    while(p){
        cout<<p->data;
        p=p->next;
    }
}

int main() {
    int A[]= {10,20,30,40,50};
    create(A,5);
    display(first);
}