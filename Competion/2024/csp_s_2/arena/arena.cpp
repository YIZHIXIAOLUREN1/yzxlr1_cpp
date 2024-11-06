#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,mod=998244353;
int T,n,m,K;
int sa[N],qc[N],RG[N*2][20];
int a[N],b[N],bb[N];

void sc(){
    int x[4];
    cin>>x[0]>>x[1]>>x[2]>>x[3];
    for(int i=1;i<=n;i++){
    	a[i]=sa[i]^x[i%4];
    	//cout<<a[i]<<" \n"[i==n];//
	}
}

ll solve(int c){
    int k=1;
    ll ans=0;
    while((1<<k)<c)k++;
    for(int i=1;i<=c;i++)b[i]=a[i];
    for(int i=c+1;i<=1<<k;i++)b[i]=-1;
    for(int i=1;i<=1<<k;i++)bb[i]=i;

    for(int i=1;i<=k;i++){
        for(int j=1;j<=1<<(k-i);j++){
            int xi=2*j-1,yi=2*j;
            if(b[yi]!=-1){
                if(RG[j][i]==1&&b[yi]>=i||RG[j][i]==0&&b[xi]<i){b[j]=b[yi];bb[j]=bb[yi];}
                else {b[j]=b[xi];bb[j]=bb[xi];}
            }else if(b[xi]!=-1){
                if(RG[j][i]==0&&b[xi]>=i){b[j]=b[xi];bb[j]=bb[xi];}
                else if(RG[j][i]==0&&b[xi]<i){b[j]=b[yi];bb[j]=bb[yi];}
                else{b[j]=-1;bb[j]=bb[xi]+bb[yi];}
            }else{
                b[j]=-1;bb[j]=bb[xi]+bb[yi];
            }
            //printf("%d %d:%d %d\n",i,j,b[j],bb[j]);//
        }
    }
    //cout<<bb[1]<<endl;//
    return bb[1];
}

int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> sa[i];
    for(int i=1;i<=m;i++)cin >> qc[i];
    K=1;
    while((1<<K)<n)K++;
    string s;
    for(int i=1;i<=K;i++){
    	cin >> s;
        for(int j=1;j<=1<<(K-i);j++){
        	RG[j][i]=s[j-1];
		}
    }
    cin >> T;
    while(T--){
        sc();
        ll ans=solve(qc[1])*a[1];
        for(int i=2;i<=m;i++){
            ans=ans^(1ll*a[i]*solve(qc[i]));
        }
        cout<<ans<<"\n";
    }


}