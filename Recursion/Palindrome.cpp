#include <iostream>
using namespace std;

bool Palindrome(string str, int i,int j){

    if(i>j) return true;

    if(str[i]==str[j]){
        return Palindrome(str,i+1,j-1);
    }else{
        return false;
    }
}


int main() {

    string name ="abcca";

    bool isPalindrome= Palindrome(name,0,name.length()-1);

    cout<<name <<endl;
    cout<< (isPalindrome ? "Yes" : "No")<<endl;
}
