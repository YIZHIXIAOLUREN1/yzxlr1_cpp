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

    ll bestAdd=0;
    auto relax=[&](ll x,ll y,ll z){
        if(x<0||y<0||z<0) return;
        if(x>sa||y>sb||z>sc) return;
        if(x+y>c) return;
        if(x+z>b) return;
        if(y+z>a) return;

        ll t=min({(ll)a-y-z,(ll)b-x-z,(ll)c-x-y});
        ll val=x+y+z+t;
        if(val>bestAdd) bestAdd=val;
    };

    for(ll x=0;x<=sa;x++){
        if((ll)b-x<0) break;
        for(ll y=0;y<=sb;y++){
            if(x+y>(ll)c) break;
            if((ll)a-y<0) break;

            ll p=(ll)a-y;
            ll q=(ll)b-x;
            ll r=(ll)c-x-y;
            ll zmax=min({(ll)sc,p,q});

            if(zmax<0) continue;
            ll mn=min(p,q);
            ll z0=mn-r;
            ll cand[7]={0,zmax,z0,z0-1,z0+1,max(0LL,min(zmax,z0)),max(0LL,min(zmax,z0+1))};
            
            for(ll z:cand){
                if(z<0||z>zmax) continue;
                relax(x,y,z);
            }
        }
    }
    cout<<(ll)ans+bestAdd<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}