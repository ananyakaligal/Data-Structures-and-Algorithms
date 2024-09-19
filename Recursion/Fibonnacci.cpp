#include<iostream>
using namespace std;

int Fibonnacci(int n){

    //base case
    if(n==0) return 0;

    if(n==1) return 1;

    return Fibonnacci(n-1)+Fibonnacci(n-2);
}

int main(){
    int n;
    cin>>n;

    Fibonnacci(n);

    return 0;
}
