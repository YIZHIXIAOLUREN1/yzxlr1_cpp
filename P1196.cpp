#include<bits/stdc++.h>
using namespace std;
#define N 30001
int fa[N],fs[N],num[N],T;

int find(int x){
    if(x==fa[x])return x;
    int k=fa[x];
    fa[x]=find(fa[x]);
    fs[x]+=fs[k];
    return fa[x];
}

void hb(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    fa[fx]=fy;
    fs[fx]+=num[fy];
    num[fy]+=num[fx];
}

int cx(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy)return -1;
    else return abs(fs[x]-fs[y])-1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<N;i++)fa[i]=i,num[i]=1;
    cin >> T;
    while(T--){
        int i,j;char tb;
        cin >> tb >> i >> j;
        if(tb=='M') hb(i,j);
        else cout << cx(i,j) << "\n";
    }
}