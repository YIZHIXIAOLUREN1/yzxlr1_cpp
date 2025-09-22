#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m,K;
int a[N],b[N];
vector<pair<int,int>> ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>K;
    while(K--){
        int c,d;
        cin>>c>>d;
        a[c]++;
        if(a[c]==m)b[c]=K;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==m)ans.push_back({b[i],i});
        //printf("%d:%d %d\n",i,a[i],b[i]);//
    }
    sort(ans.begin(),ans.end());
    for(int i=ans.size()-1;i>=0;i--){
    	//printf("%d:%d %d\n",i,ans[i].first,ans[i].second);//
    }
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i].second<<" \n"[i==0];
}
