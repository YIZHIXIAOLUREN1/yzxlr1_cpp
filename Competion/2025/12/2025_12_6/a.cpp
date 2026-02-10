#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n,q,a[N],c[N];
int res;
int ud[N],tot;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=1;
    }
    while(q--){
        int x;
        cin>>x;
        if(c[x]){
            if(a[x]){
                res++;
                for(int i=1;i<=tot;i++){
                    int u=ud[i];
                    if(!c[u]&&!a[u]){
                        a[u]=1;
                        res++;
                    }
                }
                tot=0;
            }else{
                if(res)a[x]=1,res++;
                else ud[++tot]=x;
            }
            c[x]=0;
        }else{
            if(a[x])res--;
            c[x]=1;
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
}