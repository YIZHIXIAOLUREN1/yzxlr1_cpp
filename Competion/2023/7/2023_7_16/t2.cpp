#include<bits/stdc++.h>
using namespace std;
#define N 100050
//#define int long long
#define inf 2e9
#define ll long long
int n,m;
ll ans=0;
bool tr=1;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        int a[n+5][m+5];
        int acn[n+5];
        int acm[m+5];
        memset(a,0,sizeof a);
        memset(acn,0,sizeof acn);
        memset(acm,0,sizeof acm);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1,x;j<=m;j++){
                cin >> x;
                a[i][j]=x-a[i][j];
            }
        }
        for(int st=1;st<=50;st++){
        for(int i=1;i<=n;i++){
            int t=inf;
            for(int j=1;j<=m;j++)t=min(t,a[i][j]);
            acn[i]+=t;
            for(int j=1;j<=m;j++)a[i][j]-=t;
        }
        for(int i=1;i<=m;i++){
            int t=inf;
            for(int j=1;j<=n;j++)t=min(t,a[j][i]);
            acm[i]+=t;
            for(int j=1;j<=n;j++)a[j][i]-=t;
        }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]!=0){
                	tr=0;
                	break;
                	//printf("%d %d\n",i,j);//
                }
            }
        }

        for(int i=1;i<=n;i++) ans+=abs(acn[i]);
        for(int i=1;i<=m;i++) ans+=abs(acm[i]);

        sort(acn+1,acn+n+1);
        sort(acm+1,acm+m+1);
        if(n<m)swap(n,m);
        int ttr=1;
        while(ttr){
        	int dt=inf;
            for(int i=1;i<=n;i++)if(acn[i]!=0)dt=min(dt,abs(acn[i]));
            for(int i=1;i<=m;i++)if(acm[i]!=0)dt=min(dt,abs(acm[i]));
            //cout << dt << endl;//
            ll da=0;
            for(int i=1;i<=n;i++)da+=abs(acn[i]-dt);
            for(int i=1;i<=m;i++)da+=abs(acm[i]+dt);
            if(da>=ans)ttr=0;
            else {
            	ttr=1;
            	ans=da;
            	for(int i=1;i<=n;i++)acn[i]-=dt;
            	for(int i=1;i<=m;i++)acm[i]+=dt;
            }
            da=0;
            for(int i=1;i<=n;i++)da+=abs(acn[i]+dt);
            for(int i=1;i<=m;i++)da+=abs(acm[i]-dt);
            if(da>=ans)ttr=0;
            else {
            	ttr=1;
            	ans=da;
            	for(int i=1;i<=n;i++)acn[i]+=dt;
            	for(int i=1;i<=m;i++)acm[i]-=dt;
            }
            //puts("A");//
        }
		//for(int i=1;i<=n;i++)printf("%d:%d\n",i,acn[i]);//
        //for(int i=1;i<=m;i++)printf("%d:%d\n",i,acm[i]);//

        if(tr)cout << ans;
        else cout << "-1";
    }
}