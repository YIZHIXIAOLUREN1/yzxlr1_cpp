#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int dfs(int x){
    if(x<=2)return 0;
    return dfs(x/3+x%3)+x/3;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<dfs(n)<<"\n";
    }
}
/*
3 1
4 1
5 2
6 2
7 3
8 3
9 3
10 4
11 4
12 5


f[i]=f[i/3+i%3]+i/3;
*/