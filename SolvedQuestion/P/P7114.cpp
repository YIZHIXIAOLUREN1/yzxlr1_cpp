#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int bs=29;
const int N=1.2e6+7,M=(1<<19)+7;
ll s2[N],p2[N];
int n;
int a[N],qjs[N],hjs[N],cnt=0;
int pr[N][27];
bool yj[bs];
ll ans=0;

void pre(){
    p2[0]=1;
    for(int i=1;i<=M;i++){
        p2[i]=p2[i-1]*bs;
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
        string s;
        cin >> s;
        n=s.size();

        pr[1][0]=0;
        for(int i=1;i<=26;i++)pr[1][i]=1;
        for(int i=1;i<=n;i++){
            a[i]=s[i-1]-'a';
            s2[i]=s2[i-1]*bs+a[i];

            if(yj[a[i]])yj[a[i]]=0,cnt--;
            else yj[a[i]]=1,cnt++;
            qjs[i]=cnt;
            for(int j=0;j<cnt;j++)pr[i][j]=pr[i-1][j];
            for(int j=cnt;j<=26;j++)pr[i][j]=pr[i-1][j]+1;
        }

        for(int i=0;i<26;i++)yj[i]=0;
        cnt=0;
        for(int i=n;i>=1;i--){
            if(yj[a[i]])yj[a[i]]=0,cnt--;
            else yj[a[i]]=1,cnt++;
            hjs[i]=cnt;
        }

        for(int i=2;i<=n-1;i++){
            ll st=s2[i];
            ans+=pr[i-1][hjs[i+1]];
            for(int j=2;j<=(n-1)/i;j++){
                int k=i*j,lk=i*(j-1);
                ll nt=s2[k]-s2[lk]*p2[k-lk];
                if(nt!=st)break;
                ans+=pr[i-1][hjs[k+1]];
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
