#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

int hashr(int key) {
    return key%10;
}

void SortedInsert(struct Node **H,int x) {
    struct Node *t, *q=NULL, *p=*H; 
    t=new Node;
    t->data=x;
    t->next=NULL;

    if(*H==NULL) {
        *H=t;
    } else{
        while(p && p->data<x) {
            q=p;
            p=p->next;
        }
        if(p==*H) {
            t->next=*H;
            *H=t;
        } else{
            t->next=q->next;
            q->next=t;
        }
    }
}

void Insert(struct Node *H[],int key){
    int index= hashr(key);
    SortedInsert(&H[index],key);
}

struct Node *Search(struct Node *p, int key) {
    while(p!=NULL) {
        if(key == p->data) {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

void Display(struct Node *H[]) {
    for(int i=0;i<10;i++) {
        cout << "Index " << i << ": ";
        struct Node *p = H[i];
        while(p!=NULL) {
            cout << p->data << " -> ";
            p=p->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    struct Node *HT[10];
    struct Node *temp;

    int i;

    for(i=0;i<10;i++) 
        HT[i]=NULL;

    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);
    Insert(HT,15);
    Insert(HT,25);
    Insert(HT,5);
    Insert(HT,35);

    cout << "Hash Table Contents:" << endl;
    Display(HT);

    // Search for elements
    int key_to_search = 22;
    int index = hashr(key_to_search);
    temp = Search(HT[index], key_to_search);
    if(temp != NULL) {
        cout << "\nElement " << key_to_search << " found in the hash table." << endl;
    } else {
        cout << "\nElement " << key_to_search << " not found in the hash table." << endl;
    }

    key_to_search = 100;
    index = hashr(key_to_search);
    temp = Search(HT[index], key_to_search);
    if(temp != NULL) {
        cout << "Element " << key_to_search << " found in the hash table." << endl;
    } else {
        cout << "Element " << key_to_search << " not found in the hash table." << endl;
    }

    return 0;
}