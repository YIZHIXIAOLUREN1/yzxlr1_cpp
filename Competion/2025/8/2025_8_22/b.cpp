#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    char x,y;
    int z;
    cin>>x>>y>>z;
    if(x=='A'){
        if(y=='N'){
            cout<<"A320";
        }else{
            if(z==2)cout<<"A350";
            else cout<<"A380";
        }
    }else if(x=='B'){
        if(y=='N')cout<<"B737";
        else if(z==2)cout<<"B787";
        else cout<<"B747";
    }else cout<<"C919";
}
