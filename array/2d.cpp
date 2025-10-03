#include<iostream>
using namespace std;
int main() {
    int A[3][4]={{1,2,3,4},{6,8,7,5},{5,7,3,1}};

    int *B[3];
    B[0]= new int[4];
    B[1]=new int[4];
    B[2]=new int[4];

    int **C;
    C=new int *[3];
    C[0]= new int[4];
    C[1]=new int[4];
    C[2]=new int[4];
}