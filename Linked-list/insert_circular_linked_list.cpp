#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n){
    struct Node *t,*last;
    Head =new Node;
    Head->data=A[0];
    Head->next=Head;
    last = Head;

    for(int i=1;i<n;i++) {
           t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void insert(struct Node *p,int x,int pos) {
    struct Node *t;
    if(pos==0) { 
       t= new Node;
       t->data=x;
       if(Head==NULL) {
        Head = t;
        Head->next=Head;
       } else{
        while(p!=Head) {
            p=p->next;
        }
        p->next=t;
        Head=t;
       }

}

else{
   for (int i=1;i<pos-1 ; i++) {
    p=p->next;

    }
    t=new Node;
    t->data=x;
    t->next=p->next;
    p->next=t;
}
}

void display(struct Node *h) {
    do{
        cout<<h->data;
        h=h->next;
    } while(h!=Head);
    cout<<endl;
}

int main() {
    int A[] = {2,3,7,6,8};
    create(A,5);
    display(Head);
    insert(Head,5,3);
      display(Head);
}
