#include<iostream>
using namespace std;

int main(){
    string str="Ananya";

    stack <char> s;

    for (int i=0;i<s.size()i++){
        s.push(str[i]);
    }

    string ans="";

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    cout<< reversed string: << ans << endl;

    return 0;
}

