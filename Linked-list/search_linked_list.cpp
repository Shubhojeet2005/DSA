#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first=NULL;

void create(int A[], int n){
    int i;
    struct Node *t,*last;
    first= new Node;
    first->data= A[0];
    first->next = NULL;
    last= first;


    for(i=1;i<n;i++) {
        t= new Node;
        t->data=A[i];
        t->next= NULL;
        last->next = t;
        last = t;
    }
}


void Display(struct Node *p) {
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

struct Node * LSearch(struct Node *p, int key) {
    while(p!=NULL) {
      if(key==p->data) {
        return p;
      }
      p = p->next;
    }
    return NULL;
}

struct Node *RSearch(struct Node *p,int key) {
    if(p==NULL) 
    return NULL;
    if(key==p->data)
    return p;
    RSearch(p->next,key);
}
int main() {
    int A[]=  {3,5,8,9,32,4,6};

    create(A,7);

    Display(first);
    cout << endl;
   Node* result = LSearch(first,32);
if(result!=NULL)
        cout << "Key found: " << result->data << endl;
    else
        cout << "Key not found" << endl;

         
  
}