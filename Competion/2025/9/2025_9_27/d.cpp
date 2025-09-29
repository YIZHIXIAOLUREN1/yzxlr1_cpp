#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+7;
int n,m;
int S[N];
int q[2][N],tq[2];
int ans;
int tij(int x,int y){
	return x*(m+1)+y;
}
bool che(int i,int j){
	//printf("%d %d:%d %d:%d\n",i,j,i+1,tij(i+1,j),S[tij(i+1,j)]);//
	//printf("%d %d:%d:%d %d %d %d\n",i,j,S[tij(i,j)],S[tij(i-1,j)],S[tij(i+1,j)],S[tij(i,j-1)],S[tij(i,j+1)]);//
    return (!S[tij(i,j)])&&((S[tij(i-1,j)]+S[tij(i+1,j)]+S[tij(i,j-1)]+S[tij(i,j+1)])==1);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            S[tij(i,j)]=s[j-1]=='#';
            if(S[tij(i,j)])q[0][++tq[0]]=tij(i,j);
        }
    }
    int qi=0,lqi=!qi;
    while(tq[qi]){
        swap(qi,lqi);
        for(int i=1;i<=tq[lqi];i++)S[q[lqi][i]]=1;
        while(tq[lqi]){
        	//cout<<"A";//
            int u=q[lqi][tq[lqi]--];
            int i=(u-1)/(m+1),j=(u-1)%(m+1)+1;
            //printf("%d %d\n",i,j);//
            if(i>1&&che(i-1,j)){
                q[qi][++tq[qi]]=tij(i-1,j);
            }
            if(i<n&&che(i+1,j)){
                q[qi][++tq[qi]]=tij(i+1,j);
            }
            if(j>1&&che(i,j-1)){
                q[qi][++tq[qi]]=tij(i,j-1);
            }
            if(j<m&&che(i,j+1)){
                q[qi][++tq[qi]]=tij(i,j+1);
            }
        }
        //cout<<"B:"<<tq[qi]<<"\n";//
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S[tij(i,j)])ans++;
        }
    }
    cout<<ans;
}
