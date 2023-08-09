#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
bool vis[N];
int pri[N],tot=0;


void getprime(){
    for(int i=2;i<=n;i++){
        if(!vis[i])pri[++tot]=i;
        for(int j=1;j<=tot&&(ll)pri[j]*i<=n;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
}