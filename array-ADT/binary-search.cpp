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

int binarySearch(struct Array *arr,int key) {
    int l=0;
    int h=arr->length-1;
    while(l<=h) {
        int mid=(l+h)/2;
        if(key==arr->A[mid]) {
            return mid;
        } else if(key<arr->A[mid]) {
            h=mid-1;
        } else{
            l=mid+1;
        }
    }
    return -1;
}


int RbinarySearch(int a[], int key, int l, int h) {
    while (l <= h) {
        int mid = (l + h) / 2;
        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            return RbinarySearch(a, key, l, mid - 1);
        } else {
            return RbinarySearch(a, key, mid + 1, h);
        }
    }
    return -1;
}






     


int main() {
   struct Array arr = {{2,3,4,5,6},10,5};
   cout<<binarySearch(&arr,3)<<endl;
   cout<<RbinarySearch(arr.A,2,0,4)<<endl;

   display(arr);
   cout << endl;
}
