#include<iostream>
using namespace std;

int Counting(int n){

    //base case
    if(n==0) return ;
    return Counting(n-1);
    cout<<n<<endl;
}

int main(){
    int n;
    cin>>n;

    int ans=factorial(n);
    cout<<ans<<endl;

    return 0;
}
