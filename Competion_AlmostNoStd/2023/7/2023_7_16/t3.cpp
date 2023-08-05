#include<bits/stdc++.h>
using namespace std;
#define N 300050
#define T 10050
#define ll long long
int n,tma;
struct node{
    int s,t,x;
    ll c;
}sj[N];

ll f[T];
int q[N],l,r,cnt;
bool cmp(node x,node y){
    if(x.s!=y.s)return x.s<y.s;
    else if(x.t!=y.t) return x.t<y.t;
    else return x.c>y.c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> sj[i].s >> sj[i].t >> sj[i].x >> sj[i].c;
        sj[i].s+=sj[i].x;
        sj[i].t+=sj[i].x;
        tma=max(tma,sj[i].t);
    }
    sort(sj+1,sj+n+1,cmp);
    
    l=1,r=0,cnt=1;
    for(int i=1;i<=tma;i++){
        while(l<=r&&sj[q[l]].t<i)l++;
        while(sj[cnt].s<=i&&sj[cnt].t>=i){
            while(l<=r&&sj[q[r]].c+f[i-sj[q[r]].x]<=
            sj[cnt].c+f[i-sj[q[cnt]].x])r--;
            q[++r]=cnt;
            cnt++;
        }
        //cout << i << ":";//
        //for(int j=l;j<=r;j++)printf("%d ",q[i]);//
        //cout << "\n";//
        f[i]=max(f[i-1],f[i-sj[q[l]].x]+sj[q[l]].c);
        printf("%d:%lld\n",i,f[i]);//
    }
    cout << f[tma];
}