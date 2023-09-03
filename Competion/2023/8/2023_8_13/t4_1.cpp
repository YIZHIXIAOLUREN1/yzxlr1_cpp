#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7,inf=0x3f3f3f3f;
int n,m,q;
int fl[N][33],fr[N][33];
int gl[N][33],gr[N][33];
vector<int> Gl[N],Gr[N];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for(int i=0;i<=n+1;i++){
    	for(int j=0;j<=32;j++)
    		fr[i][j]=gr[i][j]=n+1;
	}
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        Gl[u].push_back(v);
        Gr[v].push_back(u);
        fl[u][0]=max(fl[u][0],v+1);
        fr[v][0]=min(fr[v][0],u-1);
        gl[u][0]=max(gl[u][0],v+1);
        gr[v][0]=min(gr[v][0],u-1);
    }
    //cout<<"A";//
    for(int i=1;i<=n;i++){
        gl[i][0]=max(gl[i][0],gl[i-1][0]);
        if(gl[i][0]<=i)gl[i][0]=0;
        //printf("L%d:%d %d\n",i,gl[i][0],fl[i][0]);//
    }
    for(int i=n;i>=1;i--){
        gr[i][0]=min(gr[i][0],gr[i+1][0]);
        if(gr[i][0]>=i)gr[i][0]=n+1;
        //printf("R%d:%d %d\n",i,gr[i][0],fr[i][0]);//
    }
    //cout<<"C";//
    for(int i=1;i<=32;i++){
        for(int j=1;j<=n;j++){
            gl[j][i]=max(gl[gl[j][i-1]][i-1],gl[j][i-1]);
            fl[j][i]=max(gl[fl[j][i-1]][i-1],fl[j][i-1]);
            //printf("L%d:%d:%d %d\n",i,j,gl[j][i],fl[j][i]);//
        }
        for(int j=n;j>=1;j--){
            gr[j][i]=max(gr[gr[j][i-1]][i-1],gr[j][i-1]);
            fr[j][i]=max(gr[fr[j][i-1]][i-1],fr[j][i-1]);
            //printf("R%d:%d:%d %d\n",i,j,gr[j][i],fr[j][i]);//
        }
    }
    //cout<<"B";//
    int L,R;
    while(q--){
        cin >> L >> R;
        int ml=L,mr=R;
        bool flag=1;
        while(gl[ml][0]<=R&&flag){
        	flag=0;
            for(int i=32;i>=0;i--){
            	//printf("l:%d:%d:%d %d\n",i,ml,fl[ml][i],gl[ml][i]);//
                if(ml==L){
                    if(fl[ml][i]>R||fl[ml][i]<=ml)continue;
                    ml=fl[ml][i];
                    flag=1;
                }else{
                    if(gl[ml][i]>R||gl[ml][i]<=ml)continue;
                    ml=gl[ml][i];
                    flag=1;
                }
            }
        }
        for(auto v:Gl[ml]){
            if(v<=R)ml=max(ml,v);
        }
		flag=1;
         while(gr[mr][0]>=L&&flag){
         	flag=0;
            for(int i=32;i>=0;i--){
            	//printf("r:%d:%d:%d %d\n",i,mr,fr[mr][i],gr[mr][i]);//
                if(mr==R){
                    if(fr[mr][i]<L||fr[mr][i]>=mr)continue;
                    mr=fr[mr][i];
                    flag=1;
                }else{
                    if(gr[mr][i]<L||gr[mr][i]>=mr)continue;
                    mr=gr[mr][i];
                    flag=1;
                }
            }
        }
        for(auto v:Gr[mr]){
            if(v>=L)mr=min(mr,v);
        }
        ml--;
        if(ml>=mr)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
