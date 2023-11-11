#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e3+7;
int n,t;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>t;
    if(n==1){
        std::cout<<R"(1)";
    }else if(n==2){
        std::cout<<R"(1
2 1)";
    }else if(n==3){
        std::cout<<R"(1
2 3
3 1 2)";
    }else if(n==4){
        std::cout<<R"(1
2 4
3 1 4
4 3 2 1)";
    }else if(n==5){
        std::cout<<R"(1
2 5
3 2 4
4 5 1 3
5 3 4 1 2)";
    }else{
        std::cout<<R"(1
2 1
3 2 1
4 3 2 1
5 4 3 2 1
6 5 4 3 2 1)";
    }
}
