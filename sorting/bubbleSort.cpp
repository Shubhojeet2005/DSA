#include<iostream>

using namespace std;

void swap(int *x,int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubble(int A[],int n) {
    int i,j,flag=0;

    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1-i;j++) {
            if(A[j]>A[j+1]) 
             swap(&A[j],&A[j+1]);
             flag=1;
        }
          if(flag==0) break;
    }
  
   
}

int main() {
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;

    bubble(A,10);
    for(int i=0;i<10;i++) {
        cout<<A[i]<<endl;

    }
    
}