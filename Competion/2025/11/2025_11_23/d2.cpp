#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
int n;
string S;
int a[N];
int pre[26][N],pi[26][N];//有i个,第i个

bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
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
            pair<int,int> ns[26]={{0,0}};
            for(int u=0;u<=25;u++){
                ns[u]={u,0};
                int cnt=pre[u][r]-pre[u][l-1];
                if(cnt%2==0)continue;
                ns[u].second=pi[u][pre[u][r]];
                //printf("%c %d:\n",u+'a',ns);//
                bool f=1;
            }
            sort(ns,ns+26,cmp);
            //for(int v=0;v<=25;v++)cout<<ns[v].second<<" \n"[v==25];//
            int st=0;
            for(int i=0;i<=25;i++){
                if(ns[i].second==0)st=i;
                else break;
            }
            st++;
            //cout<<st<<"\n";//
            for(int v=0;v<=25;v++){
                for(int u=st;u<=25;u++){
                    if(ns[u].second==0)continue;
                    if(ns[u].first==v)continue;
                    //printf("%c %d %d\n",v+'a',ns[u].second,pre[v][ns[u].second]-pre[v][l-1]);//
                    if(!(pre[v][r]-pre[v][ns[u].second]))break;
                    if((pre[v][ns[u].second]-pre[v][l-1])%2==1){
                    	//printf("n:%c %d:%d %d\n",v+'a',u,ns[u].second,pre[v][ns[u].second]-pre[v][l-1]);//
                        ns[u].second=0;
                        
                    }
                }
            }
            for(int u=st;u<=25;u++)if(ns[u].second)ans+=a[ns[u].second];
            
            cout<<ans<<"\n";
        }
    }
}