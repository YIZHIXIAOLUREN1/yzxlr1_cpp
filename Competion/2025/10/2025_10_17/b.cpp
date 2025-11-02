#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
string s;
int p[N],cnt;
int res[N],cnt2;
bool ans=0;
void check(){
    int j=0;
    cnt2=0;
    //cout<<"A\n";
    //for(int i=1;i<=cnt;i++)cout<<p[i]<<" \n"[i==cnt];//
    for(int i=1;i<=n;i++){
    	while(j<cnt&&p[j]<i)j++;
        if(i==p[j]){
            continue;
        }
        res[++cnt2]=s[i-1]-'0';
    }
    
    //for(int i=1;i<=cnt2;i++)cout<<res[i]<<" \n"[i==cnt2];//
    
    bool re=1;
    for(int i=1;i<=cnt2;i++){
        if(res[i]!=res[cnt2-i+1]){re=0;break;}
    }
    if(re){
        cout<<cnt<<"\n";
        for(int i=1;i<=cnt;i++)cout<<p[i]<<" \n"[i==cnt];
        ans=1;
    }
    //cout<<"B\n";
}

void dfs(int u,int fa){
	if(ans)return;
    if(u==n){
        check();
        return;
    }
    dfs(u+1,fa);
    if(!fa||s[fa-1]<=s[u-1]){
        p[++cnt]=u;
        dfs(u+1,u);
        cnt--;
    }
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        cnt=0;
        cin>>s;
        dfs(0,0);
    }
}