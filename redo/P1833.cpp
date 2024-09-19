#include<bits/stdc++.h>
using namespace std;
#define ll long long
int tget(){
	string T;
	cin >> T;
	int res1=0,res=0;
	bool tr=0;
	for(int i=0;i<T.length();i++){
		if(!tr&&T[i]!=':'){res1*=10;res1+=T[i]-'0';}
		else if(T[i]!=':'){res1*=10;res1+=T[i]-'0';}
		else{res+=res1*60;tr=1;res1=0;}
	}
	res+=res1;
	return res;
}
const int N=1e4+7,T=1e3+7;
int n,W;
int v[N],w[N],p[N];
int f[2][T],q[T],head,tail;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    W-=tget();W+=tget();
    cin >> n;
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i]>>p[i];

    for(int i=1;i<=n;i++){
        int ni=i&1,li=(i&1)^1;
        for(int j=0;j<=W;j++)f[ni][j]=f[li][j];
        if(p[i]==1)for(int j=w[i];j<=W;j++)
            f[ni][j]=max(f[li][j],f[li][j-w[i]]+v[i]);
        else if(p[i]==0)for(int j=w[i];j<=W;j++)
            f[ni][j]=max(f[ni][j],f[ni][j-w[i]]+v[i]);
        else{
            for(int c=0;c<min(W,w[i]);c++){
                head=1,tail=0;
                q[head]=c;
                for(int j=c;j<=W;j+=w[i]){
                    while(head<=tail&&q[head]<j-w[i]*p[i])head++;
                    while(head<tail&&f[li][q[tail]]+(j-q[tail])/w[i]*v[i]<=f[li][j])tail--;
                    q[++tail]=j;
                    f[ni][j]=max(f[li][j],f[li][q[head]]+(j-q[head])/w[i]*v[i]);
                    //printf("%d:%d:%d:%d %d\n",j,head,tail,q[head],q[tail]);//
                }
            }
        }
        //for(int j=0;j<=W;j++)printf("%d:%d ",j,f[ni][j]);//
        //cout<<endl;//
    }
    int ans=0;
    for(int i=0;i<=W;i++)ans=max(ans,f[n&1][i]);
    cout<<ans;
    return 0;
}
