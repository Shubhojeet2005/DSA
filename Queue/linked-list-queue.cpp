#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;


void enqueue(int x) {
    struct Node *t;
    t=new Node;
    if(t==NULL) 
      cout<<"queue is empty";


      else{
        t->data=x;
        t->next=NULL;

        if(front==NULL) 
           front=rear=t;

           else{
            rear->next=t;
            rear=t;
           }
      }
}


void display() {
     struct Node *p= front;
    
    while(p) {
        cout<<p->data;
        p=p->next;

    }
    cout<<"\n";
}


void dequeue() {
    struct Node *p= front;
    int x=-1;
    if(front==NULL) 
       cout<<"Queue is empty";

       else{
        p=front;
        front=front->next;
        x=p->data;
        delete p;

       }
}


int main() {
   enqueue(10);
    enqueue(20);
    enqueue(30);

    display();


    


}