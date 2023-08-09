#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e8+7;
int n,ans=0;
bool vis[N];
int pri[N/10],tot=0;
int mn[N];

void getprime(){
    for(int i=2;i<=N-7;i++){
        if(!vis[i]){
        	pri[++tot]=i;
        	mn[i]=i;
        	//printf("%d:%d\n",tot,i);//
		}
        for(int j=1;j<=tot&&(ll)pri[j]*i<=N-7;j++){
            vis[i*pri[j]]=1;
            mn[i*pri[j]]=pri[j];
            if(i%pri[j]==0)break;
        }
    }
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);
    int T;
    getprime();
    cin >> T;
    while(T--){
        cin >> n;
        ans=0;
        while(n>1)ans^=mn[n],n/=mn[n];
        
        cout << ans << "\n";
    }
}