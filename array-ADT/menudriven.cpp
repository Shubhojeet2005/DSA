#include<iostream>
using namespace std;

struct Array{
      int *A;
      int size;
      int length;
};



int main() {
    struct Array arr1;
    cin >> arr1.size;
    arr1.A = new int[arr1.size];
    
}