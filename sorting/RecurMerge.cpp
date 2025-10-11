#include<iostream>
using namespace std;
void Merge(int A[],int l,int mid,int h) {
    int i,j,k;
    int B[100];
     i=l,j=mid+1,k=l;

    while(i<=mid && j<=h) {
        if(A[i]<A[j]) {
            B[k++]=A[i++];
        } else{
            B[k++]=A[j++];

        }
    }

    for(;i<=mid;i++) {
        B[k++]=A[i];
    }
    
    for(;j<=h;j++) {
        B[k++]=A[j];
    }

    for(i=l;i<=h;i++) {
        A[i]=B[i];
    }

}

void RMergeSort(int A[],int l, int h) {
    if(l<h) {
        int mid=(l+h)/2;
        RMergeSort(A,l,mid);
        RMergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }

}


int main() {
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;

    RMergeSort(A,0,9);
    
    for(int i=0;i<10;i++) {
        cout<<A[i]<<endl;

    }
    
}