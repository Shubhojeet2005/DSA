#include<iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr) {
    int i;
    for(i=0;i<arr.length;i++) {
        cout<< arr.A[i];
    }
}

void swap(int *x,int *y) {
    int temp = *x;
    *x=*y;
    *y=temp;

}

int linear(struct Array *arr,int key) {
    for(int i=0;i<arr->length;i++) {
        if(key==arr->A[i]) {
            swap(arr->A[i],arr->A[0]);
            return 0;
        }
        
    }
    return -1;
}

int linear1(struct Array *arr,int key) {
    for(int i=0;i<arr->length;i++) {
        if(key==arr->A[i]) {
            swap(arr->A[i],arr->A[i-1]);
            return i-1;
        }
        
    }
    return -1;
}

int linear2(struct Array *arr,int key) {
    for(int i=0;i<arr->length;i++) {
        if(key==arr->A[i]) {
            return i;
        }
        
    }
    return -1;
}



     


int main() {
   struct Array arr = {{2,3,4,5,6},10,5};
   cout<<linear(&arr,100)<<endl;
   cout<<linear1(&arr,100)<<endl;
   cout<<linear2(&arr,100)<<endl;
   display(arr);
}
