#include<iostream>
using namespace std;

int fun(int n) {
   
        if(n>100) {
            return (n-10);
        } else {
           fun(fun(n+11));

        }
    }

    int main() {
        int n = 95;
       cout<<fun(95);
    }