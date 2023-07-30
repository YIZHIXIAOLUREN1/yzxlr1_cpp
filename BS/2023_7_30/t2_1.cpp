#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,M=2e6+7;
int n,m;
int deg[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        deg[u]++,deg[v]++;
    }
    int nn=0;
    for(int i=1;i<=n;i++)
    	if(deg[i]>0)nn++;
    cout << m-nn+1;
}