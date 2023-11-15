#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int bs1=29,bs2=131,mod1=1e9+7,mod2=998244353;
const int N=1.2e6+7,M=(1<<19)+7;
int s1[N],s2[N],p1[N],p2[N];
int n;
int a[N],qjs[N],hjs[N],cnt=0;
int pr[N][27];
bool yj[bs1];
ll ans=0;

void pre(){
    p1[0]=p2[0]=1;
    for(int i=1;i<=M;i++){
        p1[i]=1ll*p1[i-1]*bs1%mod1;
        p2[i]=1ll*p2[i-1]*bs2%mod2;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    pre();
    while(T--){
        for(int i=0;i<26;i++)yj[i]=0;
        cnt=0,ans=0;
        //memset(pr,0,sizeof pr);
        string s;
        cin >> s;
        n=s.size();

        //s1[1]=s2[1]=a[1]=s[0]-'a';
        //yj[a[1]]=1;cnt++;
        pr[1][0]=0;
        for(int i=1;i<=26;i++)pr[1][i]=1;
        for(int i=1;i<=n;i++){
            a[i]=s[i-1]-'a';

            s1[i]=(1ll*s1[i-1]*bs1+a[i])%mod1;
            s2[i]=(1ll*s2[i-1]*bs2+a[i])%mod2;
            //printf("%d:%lld %lld\n",i,s1[i],s2[i]);//

            if(yj[a[i]])yj[a[i]]=0,cnt--;
            else yj[a[i]]=1,cnt++;
            qjs[i]=cnt;
            for(int j=0;j<cnt;j++)pr[i][j]=pr[i-1][j];
            for(int j=cnt;j<=26;j++)pr[i][j]=pr[i-1][j]+1;
            //printf("%d %d:%lld %lld:%lld %lld:%d\n",i,a[i],p1[i],p2[i],s1[i],s2[i],cnt);//
        }

        for(int i=0;i<26;i++)yj[i]=0;
        cnt=0;
        for(int i=n;i>=1;i--){
            if(yj[a[i]])yj[a[i]]=0,cnt--;
            else yj[a[i]]=1,cnt++;
            hjs[i]=cnt;
        }

        for(int i=2;i<=n-1;i++){
            ll st1=s1[i],st2=s2[i];
            ans+=pr[i-1][hjs[i+1]];
            for(int j=2;j<=(n-1)/i;j++){
                int k=i*j,lk=i*(j-1);
                ll nt1=(s1[k]-1ll*s1[lk]*p1[k-lk]%mod1+mod1)%mod1;
                ll nt2=(s2[k]-1ll*s2[lk]*p2[k-lk]%mod2+mod2)%mod2;
                //printf("%d:%d:%lld %lld:%lld %lld\n",
                //i,j,st1,nt1,st2,nt2);//
                if(nt1!=st1||nt2!=st2)break;
                ans+=pr[i-1][hjs[k+1]];
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
