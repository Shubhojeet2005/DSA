#include<iostream>
using namespace std;

void Insert(int A[],int n) {
    int x,j;
    for(int i=1;i<n;i++) {
       j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x) {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }

}



int main() {
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;

    Insert(A,10);
    for(int i=0;i<10;i++) {
        cout<<A[i]<<endl;

    }
    
}