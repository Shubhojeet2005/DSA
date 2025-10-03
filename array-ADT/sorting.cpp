#include<iostream>
using namespace std;

struct Array {
    int A[10];
    int length;
    int size;
};

void Display(struct Array arr) {
    for(int i=0;i<arr.length;i++) {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

bool Checksort(struct Array *arr) {
    for(int i=0; i < arr->length - 1; i++) {
        if(arr->A[i+1] < arr->A[i]) {
            return false;
        }
    }
    return true;
}

int insertelement(struct Array *arr,int x) {
    int i;
    i=arr->length-1;
    while(arr->A[i]>x) {
        arr->A[i+1]= arr->A[i];
        i--;
    }

    arr->A[i+1]=x;
    arr->length++;
}



int main() {
    struct Array arr = {{2,3,5,10,15}, 5, 10};
    cout<< Checksort(&arr)<<endl ;
    insertelement(&arr,6);
    Display(arr);
    return 0;
}