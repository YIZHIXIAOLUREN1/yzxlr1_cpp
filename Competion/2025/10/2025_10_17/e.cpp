#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,k,a[N],fa[N];
pair<int,int> sum[N];

bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first!=y.first)return x.first<y.first;
    else return fa[x.second]<fa[y.second];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)sum[i].first=fa[i]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!fa[a[i]])fa[a[i]]=i;
            sum[i].second=i;
            sum[a[i]].first++;
        }
        sort(sum+1,sum+n+1);
        //for(int i=1;i<=n;i++)printf("%d:%d\n",sum[i].second,sum[i].first);//
        for(int i=1;i<=k;i++){
        	cout<<sum[i].second<<" \n"[i==k];
        }
    }
}
