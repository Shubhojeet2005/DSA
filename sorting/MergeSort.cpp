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

void IMerge(int A[],int n) {
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2) {
        for(i=0;i+p-1<n;i=i+p) {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n) {
        Merge(A,0,p/2-1,n-1);
    }
}


int main() {
    int A[]={3,7,9,10,6,5,12,4,11,2},n=10;

    IMerge(A,n);
    
    for(int i=0;i<10;i++) {
        cout<<A[i]<<endl;

    }
    
}