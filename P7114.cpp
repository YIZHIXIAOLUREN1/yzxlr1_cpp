#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll bs1=29,bs2=37,mod1=1e9+7,mod2=998244353;
const int N=1.2e6+7;
ll s1[N],s2[N],p1[N],p2[N];
ll np1[N],np2[N];
int n;
int a[N],qjs[N],hjs[N],cnt=0;
int pr[27][N];
bool yj[bs1];
ll ans=0;

ll qp(ll x,ll q,const ll mod){
    ll res=1;
    while(q){
        if(q&1)res=res*x%mod;
        x=x*x%mod;
        q>>=1;
    }
    return res;
}
ll inv(ll x,const ll mod){return qp(x,mod-2,mod);}
void pre(){
    for(int i=1;i<=n;i++){
        np1[i]=inv(p1[i],mod1);
        np2[i]=inv(p2[i],mod2);
        //printf("%d:%lld:%lld %lld %lld\n",i,p1[i],np1[i],p2[i],np2[i]);//
    }
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        for(int i=0;i<26;i++)yj[i]=0;
        cnt=0,ans=0;
        memset(pr,0,sizeof pr);
        string s;
        cin >> s;
        n=s.size();

        p1[1]=p2[1]=1;
        s1[1]=s2[1]=a[1]=s[0]-'a';
        yj[a[1]]=1;cnt++;
        for(int i=1;i<=26;i++)pr[i][1]=1;
        for(int i=2;i<=n;i++){
            a[i]=s[i-1]-'a';

            p1[i]=p1[i-1]*bs1%mod1;
            p2[i]=p2[i-1]*bs2%mod2;
            s1[i]=(1ll*a[i]*p1[i]%mod1+s1[i-1])%mod1;
            s2[i]=(1ll*a[i]*p2[i]%mod2+s1[i-1])%mod2;

            if(yj[a[i]])yj[a[i]]=0,cnt--;
            else yj[a[i]]=1,cnt++;
            qjs[i]=cnt;
            for(int j=0;j<cnt;j++)pr[j][i]=pr[j][i-1];
            for(int j=cnt;j<=26;j++)pr[j][i]=pr[j][i-1]+1;
            //printf("%d %d:%lld %lld:%lld %lld:%d\n",i,a[i],p1[i],p2[i],s1[i],s2[i],cnt);//
        }

        for(int i=0;i<26;i++)yj[i]=0;
        cnt=0;
        for(int i=n;i>=1;i--){
            if(yj[a[i]])yj[a[i]]=0,cnt--;
            else yj[a[i]]=1,cnt++;
            hjs[i]=cnt;
        }

        pre();
        for(int i=2;i<=n-1;i++){
            ll st1=s1[i],st2=s2[i];
            ans+=pr[hjs[i+1]][i-1];
            for(int j=2;j<=(n-1)/i;j++){
                int k=i*j,lk=(i-1)*j;
                ll nt1=(s1[k]-s1[lk]+mod1)%mod1*np1[lk]%mod1;
                ll nt2=(s2[k]-s2[lk]+mod2)%mod2*np2[lk]%mod2;
                printf("%d:%d:%lld %lld:%lld %lld\n",i,j,st1,nt1,st2,nt2);//
                if(nt1!=st1||nt2!=st2)break;
                ans+=pr[hjs[k+1]][i-1];
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
