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

void RDisplay(struct Node *p) { 
    if(p!=NULL) {
        cout<<p->data;
        RDisplay(p->next);
    }

}

int count(struct Node *p) {
    int l=0;
    while(p!=0) {
        l++;
        p=p->next;

    }
    return l;

}

int sum(struct Node *p) {
    int sum =0;
    while(p!=0) {
        sum+= p->data;
        p=p->next;

    }
    return sum;
}
void Display(struct Node *p) {
    while(p!=0){
        cout<<p->data;
        p=p->next;
    }
}

int main() {
    int A[]=  {3,5,8,9,5,4,6};

    create(A,7);

    Display(first);
    cout << endl;

    RDisplay(first);
 cout << endl;
   cout<< count(first)<<endl;
   cout<< sum(first);
}