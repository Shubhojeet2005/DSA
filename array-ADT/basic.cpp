#include<iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr) {
    int i;
    for(i=0;i<arr.length;i++) {
        cout<< arr.A[i];
    }
}

int main() {
    struct Array arr;
    int n,i;
   cout<<"Enter size of array";
   cin>>arr.size;
   arr.A= new int[10];
   arr.length=0;

   cout<<"Enter number of numbers";
   cin>> n;

   cout<<"enter all elements";
   for(i=0;i<n;i++) {
    cin>> arr.A[i];
   }

   arr.length=n;

   display(arr);
}
