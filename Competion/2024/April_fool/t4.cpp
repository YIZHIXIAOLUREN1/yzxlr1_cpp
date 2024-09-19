#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int T;
int a,b;
int jt(int x){int s=0;for(int j=1;j<=(int)1e6;j++)s+=j*j;return s+x;}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){a=jt(1000);cin >>a >> b;cout<< a+b;}
}
