#include<iostream>
using namespace std;

int reachHome(int src,int dest){

    //base case
    if(src==dest) {

        cout <<"reached"<<endl;
        cout<<"source is"<<src<<"destination is"<<dest<<endl;
    }

    reachHome(src+1,dest);
}

int main(){
    int dest=10;
    int src;

    reachHome(src,dest);

    return 0;
}
