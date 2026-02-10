#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7,LOG=20;
int n;
string S;
int a[N];
int pre[26][N],pi[26][N];//有i个,第i个
int pg[N];

int st[LOG][N],lg2[N];

void ps(){
    lg2[1]=0;
    for(int i=2;i<N;i++)lg2[i]=lg2[i/2]+1;

    for(int i=1;i<=n;i++)st[0][i]=(1<<(S[i]-'a'));
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[j][i]=st[j-1][i]|st[j-1][i+(1<<(j-1))];
        }
    }
}

int query(int l,int r){
    if(l>r)return 0;
    int k=lg2[r-l+1];
    return st[k][l]|st[k][r-(1<<k)+1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>S;
    S='0'+S;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int u=0;u<=25;u++){
            pre[u][i]=pre[u][i-1];
        }
        pre[S[i]-'a'][i]++;
        pi[S[i]-'a'][pre[S[i]-'a'][i]]=i;
        for(int u=0;u<=25;u++){
            pg[i]^=(1<<(u))*(pre[u][i]&1);
        }
    }
    
    ps();

    int Q;
    cin>>Q;
    while(Q--){
        int type;
        cin>>type;
        if(type==1){
            int x,y;
            cin>>x>>y;
            a[x]=y;
        }else{
            int l,r;
            cin>>l>>r;
            ll ans=0;
            int g=pg[r]^pg[l-1];
            for(int u=0;u<=25;u++){
                if((g&(1<<u))==0)continue;
                int ns=pi[u][pre[u][r]];
                if(!((pg[ns-1]^pg[l-1])&query(ns+1,r))){
                    ans+=a[ns];
                }
                
            }
            cout<<ans<<"\n";
        }
    }
}