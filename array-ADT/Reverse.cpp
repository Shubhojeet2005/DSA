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
// Function to reverse the array elements
// void reverse(struct Array &arr) {
//     int i, j;
//     int temp;
//     for(i = 0, j = arr.length - 1; i < j; i++, j--) {
//         temp = arr.A[i];
//         arr.A[i] = arr.A[j];
//         arr.A[j] = temp;
//     }
// }

void reverse2(struct Array *arr) {
    int *B = new int[arr->length]; 
    int i, j;
    for(i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }

    for(int k = 0; k < arr->length; k++) {
        arr->A[k] = B[k];
    }

    delete[] B;
}

int main() {
   struct Array arr = {{2,3,4,5,6},10,5};

   display(arr);
   cout << endl;
}
