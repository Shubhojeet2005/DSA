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
 

void todelete(struct Array *arr,int index) {
     int x= arr->A[index];
     for (int i = index; i < arr->length-1; i++)
     {
       arr->A[i]= arr->A[i+1];
     }
     arr->length--;
     
}

int main() {
   struct Array arr = {{2,3,4,5,6},10,5};
  todelete(&arr,2);
   display(arr);
}
