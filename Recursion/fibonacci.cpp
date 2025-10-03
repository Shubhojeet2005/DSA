#include<iostream>
using namespace std;

int fibo(int n) {
    if(n<2) {
        return n;
    } else{
        return fibo(n-1) + fibo(n-2);
    }
}

    int main() {
        int n=5;
       cout<<fibo(5);
    }