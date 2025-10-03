#include<iostream>
using namespace std;

int f[10];


   
  

int fibo(int n) {
    if(n<=1) {
       f[n]=n;
       return n;
    } else{
       if(f[n-2] == -1) {
        f[n-2]=fibo(n-2);
       }

       if(f[n-1] == -1) {
        f[n-1]=fibo(n-1);
       }
    }
    return f[n-2] + f[n-1];
}
   int main() {
    for(int i=1;i<=10;i++) {
        f[i] = -1;
    }
       int n = 5;
       cout << fibo(n);
       return 0;
   }
