#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n;
pair<pair<int,int>,vector<int>> a[N];
pair<int,vector<int>> b[N];
vector<int> ans[N];
int cnt3;
int lsh[N],cnt1,cnt2;
bool cmp(pair<pair<int,int>,vector<int>> x,pair<pair<int,int>,vector<int>> y){
    return x.first.first<y.first.first;
}
int din[N],dout[N];
int rc[N];
bool vis1[N],vis2[N];
int nxt[N],fro[N];
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int ma;
        cin>>ma;
        for(int j=1;j<=ma;j++){
            int c;
            cin>>c;
            a[i].second.push_back(c);
            a[i].first.first=max(a[i].first.first,c);
            lsh[++cnt1]=c;
        }
        a[i].first.second=i;
    }
    sort(a+1,a+n+1,cmp);
    sort(lsh+1,lsh+cnt1+1);
    cnt2=unique(lsh+1,lsh+cnt1+1)-lsh-1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].second.size();j++){
            a[i].second[j]=lower_bound(lsh+1,lsh+cnt2+1,a[i].second[j])-lsh;
        }
        a[i].first.first=lower_bound(lsh+1,lsh+cnt2+1,a[i].first.first)-lsh;
    }
    
    for(int i=1;i<=n;i++){
    	//cout<<a[i].first<<":";
    	//for(auto v:a[i].second)cout<<v<<" ";
    	//cout<<"\n";//
    }
    
    for(int i=1;i<=n;i++){
        if(a[i].first.first!=a[i-1].first.first){
            ++cnt3;
            b[cnt3].first=a[i].first.first;
        }
        for(auto v:a[i].second){
            b[cnt3].second.push_back(v);
        }
        ans[cnt3].push_back(a[i].first.second);
    }
    
    for(int i=1;i<=cnt3;i++){
        sort(b[i].second.begin(),b[i].second.end());
        b[i].second.erase(unique(b[i].second.begin(),b[i].second.end()),b[i].second.end());
        
        for(auto v:b[i].second){
            if(rc[v]){
            	//printf("%d:%d %d\n",i,v,rc[v]);//
                din[i]++;
                dout[rc[v]]++;
                if(!vis1[rc[v]])nxt[rc[v]]=i,vis1[rc[v]]=1;
            }
        }
        rc[b[i].first]=i;
    }
    for(int i=1;i<=cnt3;i++){
    	cout<<i<<":"<<b[i].first<<":"<<nxt[i]<<":\n";
    	for(auto v:b[i].second)cout<<v<<" ";
    	cout<<"\n";//
    }
    //cout<<cnt3<<"\n";//
    int ans1=n-cnt3;
    int ai=0,ao=0;
    for(int i=1;i<=cnt3;i++){
        if(din[i])ai++;
        if(dout[i])ao++;
    }
    cout<<ans1+min(ai,ao)<<"\n";
    int res=n;
    queue<int> q,qq;
    for(int i=1;i<=n;i++)qq.push(i);
    while(res){
        q.push(qq.front());
        qq.pop();
    	while(!q.empty()){
	        int u=q.front();
	        q.pop();
	        if(vis2[u])continue;
	        vis2[u]=1;
            res--;
	        int froo=0;
	        for(auto v:ans[u]){
	            for(auto vv:a[v].second){
	                if(vv==b[fro[u]].first){
	                    froo=v;
	                    cout<<v<<" ";
	                    break;
	                }
	            }
	            if(froo)break;
	        }
	        for(auto v:ans[u]){
	            if(v==froo)continue;
	            cout<<v<<" ";
	        }
	        if(nxt[u]){
	            fro[nxt[u]]=b[u].first;
	            q.push(nxt[u]);
	        }
	    }
    }
}
