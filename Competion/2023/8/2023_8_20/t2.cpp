#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2007;
int n,p[5];
bool a[N][N];
ll f[N],g[N];

ll check(int x,int y,int t1,int t2){
    ll res=0;
    if(t2==1){
        for(int i=x-t1+1;i<=x;i++){
            if(a[i][y])res+=p[1];
        }
        return res;
    }else if(t2==2){
        bool f=0;
        for(int i=x-t1+1;i<=x;i++){
            f=0;
            for(int j=y-1;j<=y;j++){
                
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> p[1] >> p[2] >> p[3] >> p[4];
    string s;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=0;j<n;j++)a[i][j+1]=(s[j]=='A'?1:0);
    }

    memset(f,0x3f,sizeof f);
    f[0]=0;

    for(int i=1;i<=n;i++){
        for(int t=1;t<=4;t++){
            if(i<t)break;
            memset(g,0x3f,sizeof g);
            g[0]=0;
            for(int j=1;j<=n;j++){
                for(int tt=1;tt<=t;tt++){
                    if(j<tt)break;
                    g[j]=min(g[j],g[j-tt]+check(i,j,t,tt));
                }
            }
        }
    }

}
