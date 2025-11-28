#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n;
string S;
int a[N];
int pre[26][N],pi[26][N];//有i个,第i个

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
        //for(int u=0;u<=25;u++)printf("%d %c:%d\n",i,u+'a',pre[u][i]);//
    }
    
    for(int u=0;u<=25;u++){
    	//for(int i=1;i<=pre[u][n];i++)printf("%c %d:%d\n",u+'a',i,pi[u][i]);//
    }

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
            for(int u=0;u<=25;u++){
                int cnt=pre[u][r]-pre[u][l-1];
                if(cnt%2==0)continue;
                int ns=pi[u][pre[u][r]];
                //printf("%c %d:\n",u+'a',ns);//
                bool f=1;
                for(int v=0;v<=25;v++){
                	if(u==v)continue;
                    if((pre[v][ns]-pre[v][l-1])%2==1&&(pre[v][r]-pre[v][ns])){
                        f=0;
                        //printf("n:%c %d\n",v+'a',pre[v][ns]-pre[v][l-1]);//
                        break;
                    }
                }
                if(!f)continue;
                ans+=a[ns];
            }
            cout<<ans<<"\n";
        }
    }
}