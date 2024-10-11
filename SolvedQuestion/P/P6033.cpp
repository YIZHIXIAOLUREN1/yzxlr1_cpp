#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+7,maxn=1e5+7;
int n;
int a[N],cnt[maxn],b[N],lb=1,rb,lc=1,rc;
ll qc[2*N],ans;
#define gc() getchar()
#define pc(x) putchar(x)
void read(int &a){
    a=0;int w=1,ch=gc();while((ch<'0'||ch>'9')&&ch!='-')ch=gc();
    if(ch=='-')w=-1,ch=gc();while(ch>='0'&&ch<='9')a=a*10+ch-'0',ch=gc();
    a=a*w;
}

ll mi(){
    if(lb<=rb&&b[lb]<=qc[lc])return b[lb++];
    else return qc[lc++];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(n);
    memset(qc,0x3f,sizeof(qc));
    memset(b,0x3f,sizeof(b));
    for(int i=1;i<=n;i++){
        read(a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<maxn;i++){
        while(cnt[i]--)b[++rb]=i;
    }
    //for(int i=1;i<=rb;i++)cout<<b[i]<<" ";//
    qc[++rc]=b[1]+b[2];
    ans+=qc[rc];
    lb+=2;
    //cout<<qc[rc]<<" "<<lb<<endl;//
    while(rb-lb+rc-lc>-1){
    	ll m1=mi(),m2=mi();
    	//cout<<m1<<" "<<m2<<" ";//
        qc[++rc]=m1+m2;
        ans+=qc[rc];
        //cout<<qc[rc]<<" "<<lb<<endl;//
    }
    cout<<ans;
    return 0;
}
