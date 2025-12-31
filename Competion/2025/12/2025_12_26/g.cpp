#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;

int n,q;
int c[N],sm[N];

void add(int bit[],int i,int v){for(;i<=n;i+=i&-i)bit[i]+=v;}
ll sum(int bit[],int i){ll r=0;for(;i>0;i-=i&-i)r+=bit[i];return r;}

struct S{int a,b,m;};
void Solve(){
    cin>>n>>q;
    vector<S> v(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        v[i]={a,b,(a+b)/2};
    }
    vector<pair<int,int>> qs(q);
    for(int i=0;i<q;i++){int x;cin>>x;qs[i]={x,i};}
    sort(v.begin(),v.end(),[](const S&x,const S&y){return x.m<y.m;});
    sort(qs.begin(),qs.end());
    for(int i=1;i<=n;i++){c[i]=0;sm[i]=0;}
    for(auto &s:v){add(c,s.a,1);add(sm,s.a,s.a);}
    vector<ll> ans(q);
    int p=0;
    for(auto &qi:qs){
        int x=qi.first,idx=qi.second;
        while(p<n && v[p].m<x){
            add(c,v[p].a,-1);add(sm,v[p].a,-v[p].a);
            add(c,v[p].b,1); add(sm,v[p].b,v[p].b);
            p++;
        }
        ll cntL=sum(c,x-1),sumL=sum(sm,x-1);
        ll left=(ll)(x-1)*cntL-sumL;
        ll totc=sum(c,n),tots=sum(sm,n);
        ll cntR=totc-sum(c,x),sumR=tots-sum(sm,x);
        ll right=sumR-(ll)(x+1)*cntR;
        ans[idx]=left+right;
    }
    for(int i=0;i<q;i++){if(i)cout<<' ';cout<<ans[i];}
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)Solve();
    return 0;
}