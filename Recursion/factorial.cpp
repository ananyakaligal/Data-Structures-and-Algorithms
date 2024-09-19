#include<iostream>
using namespace std;

int factorial(int n){

    //base case
    if(n==0) return 1;

    int x=factorial(n-1);
    int y=n*x;

    return y;
}

int main(){
    int n;
    cin>>n;

    int ans=factorial(n);
    cout<<ans<<endl;

    return 0;
}
