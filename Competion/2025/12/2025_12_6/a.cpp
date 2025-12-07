#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n,q,a[N],c[N];
int res;
vector<int> ud;
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
            if(res&&!a[x]){
                a[x]=1;
                res++;
            }
            if(!res&&!a[x])ud.push_back(x);
            if(a[x]){
                res++;
            }
            c[x]=0;
        }else{
            if(a[x])res--;
            c[x]=1;
        }
        if(res){
            for(auto u:ud){
                if(!c[u]&&!a[u]){
                    a[u]=1;
                    res++;
                }
            }
            ud.clear();
        }
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
}
