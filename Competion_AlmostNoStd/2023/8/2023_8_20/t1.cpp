#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
ll n,b[20];
string s;
int w[N*36],tot;
int G[N][10];

void init(int u,ll q,ll x){
    printf("%d:%lld:%lld:%d\n",u,q,x,w[u]);//
    int v,tt=x,f=0;
    while(tt>9)tt/=10,f++;
    if(G[u][tt])v=G[u][tt];
    else G[u][tt]=v=++tot;
    q=q*10+tt;
    if(x<10) w[u]++;
    else init(v,q,x-tt*10*f);
}

ll dfs(int u,ll q){

}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s;
        int top=0;
        for(int i=0;i<s.size();i++)b[++top]=s[i]-'0';
        sort(b+1,b+1+top);
        for(int i=0;i<s.size();i++)s[i]=b[i]+'0';
    }

    
}
