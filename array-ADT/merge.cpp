#include<iostream>
using namespace std;

struct Array {
    int A[10];
    int length;
    int size;
};

void Display(struct Array *arr) {
    for(int i=0;i<arr->length;i++) {
        cout << arr->A[i] << " ";
    }
    cout << endl;
}

struct Array* merge(struct Array *arr, struct Array *arr1) {
    int i = 0, j = 0, k = 0;
    struct Array *arr2 = new Array;
   while(i<arr->length && j<arr1->length) {
    if(arr->A[i]<arr1->A[j]) {
        arr2->A[k++] = arr->A[i++];
    } else{
        arr2->A[k++] = arr1->A[j++];
    }
   }
   for(;i<arr->length;i++) {
    arr2->A[k++] = arr->A[i];
   }

   for(;j<arr1->length;j++) {
    arr2->A[k++] = arr1->A[j];
   }

   arr2->length= arr->length+ arr1->length;
   arr2->size=10;
   return arr2;
}




struct Array* Union(struct Array *arr, struct Array *arr1) {
    int i = 0, j = 0, k = 0;
    struct Array *arr2 = new Array;
   while(i<arr->length && j<arr1->length) {
    if(arr->A[i]<arr1->A[j]) {
        arr2->A[k++] = arr->A[i++];
    } else if(arr1->A[j]<arr->A[i]){
        arr2->A[k++] = arr1->A[j++];
    } else{
        arr2->A[k++] = arr->A[i++];
    }
   }
   for(;i<arr->length;i++) {
    arr2->A[k++] = arr->A[i];
   }

   for(;j<arr1->length;j++) {
    arr2->A[k++] = arr1->A[j];
   }

   arr2->length=k;
   arr2->size=10;
   return arr2;
}


int main() {
    struct Array arr = {{2,3,5,10,15}, 5, 10};
    struct Array arr1 = {{2,7,10,14,18}, 5, 10}; // Define and initialize arr1
    struct Array *arr2;
    arr2 = Union(&arr, &arr1);
    Display(arr2);
    Display(arr2);
    return 0;
}
