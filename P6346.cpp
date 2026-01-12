#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n;
pair<int,int> a[N];
priority_queue<int,vector<int>,greater<int>> q;
int ans,tot;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1,[](pair<int,int> x,pair<int,int> y){
        if(x.first!=y.first)return x.first<y.first;
        return x.second>y.second;
    });
	//for(int i=1;i<=n;i++)cout<<a[i].first<< " "<<a[i].second<<"\n";//
    for(int i=n;i>=1;i--){
        q.push(a[i].second);
        tot++;
        if(n-tot<a[i].first){
            ans+=q.top();q.pop();
            tot--;
        }
    }
    cout<<ans<<"\n";
}
