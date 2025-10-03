#include<iostream>
using namespace std;

//method 1
// int pow(int m,int n) {
//     if(n==0) {
//         return 1;
//     } else {
//         return m*pow(m,n-1);
//     }
//     }

//     int main() {
//         int n = 3;int m=3;
//        cout<<pow(3,3);
//     }


//method 2

int pow(int m,int n) {
    if(n==0) {
        return 1;

    } if(n%2==0) {
        return pow(m*m,n/2);
    } else {
        return m*pow(m*m,(n-1)/2);
    }
}

int main() {
            int n = 3;int m=3;
           cout<<pow(3,3);
        }