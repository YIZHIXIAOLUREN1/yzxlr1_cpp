#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
int a[N],s[N],n1[N],b[N];
int ans,anx=N;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;
    cin >> _;
    while(_--){
        memset(a,0,sizeof a);
        memset(s,0,sizeof s);
        memset(b,0x3f,sizeof b);
        ans=0,anx=N;
        string str;
        cin >> str;
        n=str.size();
        for(int i=1;i<=n;i++){
            a[i]=str[i-1]-'0';
            s[i]=s[i-1]+(a[i]==0);
            b[s[i]]=min(b[s[i]],i);
        }

        for(int i=n,j=n;i>=0;i--){
            if(a[i]==1)j=i;
            n1[i]=j;
        }

        int mk=s[n]/2;
        for(int k=1;k<=mk;k++){
            int res=0;
            for(int i=0;i<=n;){
                if(s[i]+k>s[n])break;
                i=n1[b[s[i]+k]];
                res++;
            }
            if(res<=1)continue;
            res=res*(k+1)-1;
            if(ans<res){ans=res,anx=k;}
        }
        
        if(ans==0)cout << "-1 -1\n";
        else cout << ans << " " << anx << "\n";
    }
}