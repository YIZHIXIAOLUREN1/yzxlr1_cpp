#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7;
int n,a,b,c,ans;
string s;
int da,db,dc,sa,sb,sc;
void jq(int l,int r){
    if(r-l+1==3)ans++;
    else if(r-l+1==2){
        if(s[l]=='5'&&s[r]=='2')dc++;
        if(s[l]=='5'&&s[r]=='0')db++;
        if(s[l]=='2'&&s[r]=='0')da++;
    }else{
        if(s[l]=='5')sa++;
        if(s[l]=='2')sb++;
        if(s[l]=='0')sc++;
    }
}
void sor(){
    if(a>b){swap(sa,sb);swap(a,b);}
    if(b>c){swap(sb,sc);swap(b,c);}
    if(a>b){swap(sa,sb);swap(a,b);}
}
void Solve(){
    cin>>n>>a>>b>>c;
    cin>>s;
    s=' '+s;
    da=db=dc=sa=sb=sc=ans=0;
    for(int r=1,l=1;r<=n;r++){
        if(s[r]=='0'){
            jq(l,r);
            l=r+1;
        }
        if(s[r]=='5'){
            if(r>l){
                jq(l,r-1);
                l=r;
            }
        }
        if(s[r]=='2'){
            if(s[r-1]!='5'&&r>l){
                jq(l,r-1);
                l=r;
            }
        }
        if(r==n&&l<=r)jq(l,r);
    }

    int dt=min(da,a);
    a-=dt,da-=dt,ans+=dt;
    dt=min(db,b);
    b-=dt,db-=dt,ans+=dt;
    dt=min(dc,c);
    c-=dt,dc-=dt,ans+=dt;
    if(sb+sc<=a&&sa+sc<=b&&sa+sb<=c){
        ans+=sa+sb+sc;
        a-=sb+sc;
        b-=sa+sc;
        c-=sa+sb;
        cout<<ans+min(a,min(b,c))<<"\n";
        return;
    }
    sor();
    dt=min(a,sb);
    ans+=dt;
    a-=dt;c-=dt;sb-=dt;
    sor();
    dt=min(a,sc);
    ans+=dt;
    a-=dt;b-=dt;sc-=dt;
    if(b>c){swap(sb,sc);swap(b,c);}
    dt=min(b,sa);
    ans+=dt;
    b-=dt;c-=dt;sa-=dt;
    cout<<ans+min(a,min(b,c))<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
