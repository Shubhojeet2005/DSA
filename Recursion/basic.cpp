#include<iostream>
using namespace std;

// calling complete first and then print while returning

// void fun(int n) {
//     if(n>0) {
//         fun(n-1);
//         cout << n;
//     }
// }

int main () {
    int x=3;
    fun(3);
}

void fun(int n) {
    if(n>0) {
        cout << n;
        fun(n-1);
        
    }
}

int main () {
    int x=3;
    fun(3);
}



// Refer page 16
// int fun(int n) {
    
//     if (n > 0) {
         
//         return fun(n - 1) + n;
//     }
//     return 0; 
// }

// int main () {
//     int x=5;
//     cout<<fun(x);
// }


// use of static variable for explaination refer pg 17
// int fun(int n) {
//     static int x=0;
//     if (n > 0) {
//          x++;
//         return fun(n - 1) + x;
//     }
//     return 0; 
// }

// int main () {
//     int x=5;
//     cout<<fun(x);
// }


//global variable

int x=0;
int fun(int n) {
   
    if (n > 0) {
         x++;
        return fun(n - 1) + x;
    }
    return 0; 
}

int main () {
    int x=5;
    cout<<fun(x)<<endl;
    cout<<fun(x);  // progress gets saved in second printing works on first result
}