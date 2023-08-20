#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1007;
int n,T;
int ax[N],ay[N];
vector<int> G[N];
int f[N][N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ax[i] >> ay[i];
    }
    memset(f,0x3f,sizeof f);

    for(int i=1;i<=n;i++){
        f[i][i]=0;
        for(int j=i+1;j<=n;j++){
            if((abs(ax[j]-ax[i])==1&&ay[i]==ay[j])||(abs(ay[j]-ay[i])==1&&ax[i]==ax[j])){
                G[i].push_back(j);
                G[j].push_back(i);
                f[i][j]=f[j][i]=1;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
            	int a,b;
            	a=(i<=k)?f[i][k]:f[k][i];
            	b=(j<=k)?f[j][k]:f[k][j];
                f[i][j]=min(f[i][j],a+b);
            }
        }
    }
    cin >> T;
    while(T--){
        int s,t;
        cin >> s >> t;
        cout<< (s<=t?f[s][t]:f[t][s]) << "\n";
    }

}
