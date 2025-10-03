#include<iostream>
using namespace std;

double e(int x,int n) {
  float s =1.0;
    for(; n > 0; n--) {
        s=1+x*s/n;
    }
    return s;
    }

    int main() {
        int x=1;
        int n = 3;
       cout<<e(1,10);
    }