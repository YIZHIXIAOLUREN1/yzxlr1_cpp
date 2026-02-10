#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,p,k;
string a[N];
int as[N];
ll sum;
//bool vis[N];
map<string,int> st;
int anss,ansm;
void Solve(){
    cin>>n>>p>>k;
	ansm=anss=N;
	sum=0;
	st.clear();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>as[i];
		st[a[i]]=i;
		//vis[i]=0;
		sum+=as[i];
	}
	for(int i=1;i<=k;i++){
		string s;
		cin>>s;
		//vis[st[s]]=1;
		ansm=min(ansm,as[st[s]]);
	}
    anss=((sum-1)/p+1);
	if(anss>ansm||p<k){cout<<"-1\n";return;}
	
	cout<<anss<<" "<<ansm<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
