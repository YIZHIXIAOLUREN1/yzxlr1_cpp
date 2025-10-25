#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int L,R;
int cnt;
vector<pair<int,int>> G[N];//2 - l1,l1+1 - l1+r1-1,20,20,++
vector<pair<int,int>> ans[N];
bool vis[N];
int nxt[N],ret[N];
vector<bool> trans(int x){
    vector<bool> res1,res2;
    while(x){
        if(x&1)res1.push_back(1);
        else res1.push_back(0);
        x>>=1;
    }
    for(int i=res1.size()-1;i>=0;i--)res2.push_back(res1[i]);
    return res2;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>L>>R;
    vector<bool>L1=trans(L),R1=trans(R);
    if(L==1){
    	if(R==1){
    		cout<<"2\n"<<"1 1\n"<<"0\n";
    		return 0;
    	}else{
            G[1].push_back({100,1});
            G[1].push_back({L1.size()+1,R1[0]});
            vis[L1.size()+1]=1;
            for(int i=1;i<R1.size()-1;i++){
                G[i+L1.size()].push_back({i+L1.size()+1,R1[i-1]});
                vis[i+L1.size()+1]=1;
            }
            G[L1.size()+R1.size()-1].push_back({100,R1[R1.size()-1]});
            vis[100]=1;
            cnt=L1.size()+R1.size()-1;
            
            for(int i=1;i<=R1.size()-3;i++){
                //cnt+2*i-1,2*i
                G[cnt+2*i-1].push_back({cnt+2*i+2,1});
                G[cnt+2*i-1].push_back({cnt+2*i+1,0});
                G[cnt+2*i].push_back({cnt+2*i+2,1});
                G[cnt+2*i].push_back({cnt+2*i+1,0});
            }
            G[cnt+2*R1.size()-5].push_back({100,1});
            G[cnt+2*R1.size()-5].push_back({100,0});
            G[cnt+2*R1.size()-4].push_back({100,1});
            G[cnt+2*R1.size()-4].push_back({100,0});
            
            int li=0;
            for(int i=1;i<=R1.size()-2;i++){
                if(R1[i])G[i+L1.size()].push_back({cnt+2*i-1,0}),vis[cnt+2*i-1]=1;
            }
            for(int i=2;i<=R1.size()-2;i++){
                if(vis[cnt+2*i-3]||vis[cnt+2*i-2]){
                    vis[cnt+2*i-1]=vis[cnt+2*i]=1;
                }
            }
            if(R1[R1.size()-1])G[R1.size()+L1.size()-1].push_back({100,0});
            int n=1,las=1;
            for(int i=2;i<=100;i++){
                //cout<<vis[i];//
                if(!vis[i])continue;
                n++;
                nxt[las]=i;
                ret[i]=n;
                las=i;
            }
            
            cout<<n<<"\n";
            las=1;
            for(int i=1;i<=n;i++){
                cout<<G[las].size()<<" ";
                for(auto [v,k]:G[las])cout<<ret[v]<<" "<<k<<" ";
                cout<<"\n";
                las=nxt[las];
            }
    	}
    }
    
    G[1].push_back({2,L1[0]});
    vis[1]=vis[2]=1;
    for(int i=2;i<L1.size();i++){
        G[i].push_back({i+1,L1[i-1]});
        vis[i+1]=1;
    }
    G[L1.size()].push_back({100,L1[L1.size()-1]});
    
    G[1].push_back({L1.size()+1,R1[0]});
    vis[L1.size()+1]=1;
    for(int i=1;i<R1.size()-1;i++){
        G[i+L1.size()].push_back({i+L1.size()+1,R1[i-1]});
        vis[i+L1.size()+1]=1;
    }
    G[L1.size()+R1.size()-1].push_back({100,R1[R1.size()-1]});
    vis[100]=1;
    cnt=L1.size()+R1.size()-1;
    
    for(int i=1;i<=R1.size()-3;i++){
        //cnt+2*i-1,2*i
        G[cnt+2*i-1].push_back({cnt+2*i+2,1});
        G[cnt+2*i-1].push_back({cnt+2*i+1,0});
        G[cnt+2*i].push_back({cnt+2*i+2,1});
        G[cnt+2*i].push_back({cnt+2*i+1,0});
    }
    G[cnt+2*R1.size()-5].push_back({100,1});
    G[cnt+2*R1.size()-5].push_back({100,0});
    G[cnt+2*R1.size()-4].push_back({100,1});
    G[cnt+2*R1.size()-4].push_back({100,0});
    
    int li=0;
    for(int i=1;i<=R1.size()-2;i++){
        int j=i-R1.size()+L1.size();
        if(j<1){
            if(R1[i])G[i+L1.size()].push_back({cnt+2*i-1,0}),vis[cnt+2*i-1]=1;
        }else{
            if(L1[i-1]==R1[i-1]&&i-li<=1){li=i;continue;}
            else{
                if(R1[i])G[i+L1.size()].push_back({cnt+2*i-1,0}),vis[cnt+2*i-1]=1;
                if(!L1[j])G[j+1].push_back({cnt+2*i,1}),vis[cnt+2*i]=1;
            }
        }
    }
    for(int i=2;i<=R1.size()-2;i++){
    	if(vis[cnt+2*i-3]||vis[cnt+2*i-2]){
    		vis[cnt+2*i-1]=vis[cnt+2*i]=1;
    	}
    }
	if(R1[R1.size()-1])G[R1.size()+L1.size()-1].push_back({100,0});
    if(!L1[L1.size()-1])G[L1.size()].push_back({100,1});
    int n=1,las=1;
    for(int i=2;i<=100;i++){
    	//cout<<vis[i];//
        if(!vis[i])continue;
        n++;
        nxt[las]=i;
        ret[i]=n;
        las=i;
    }
    
    cout<<n<<"\n";
    las=1;
    for(int i=1;i<=n;i++){
        cout<<G[las].size()<<" ";
        for(auto [v,k]:G[las])cout<<ret[v]<<" "<<k<<" ";
        cout<<"\n";
        las=nxt[las];
    }
}