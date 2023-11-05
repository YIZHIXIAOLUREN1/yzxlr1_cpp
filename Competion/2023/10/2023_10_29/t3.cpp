#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
const db jd=1e-8;
const int N=2e5+7;
int n,m;
db d[N],a[N];

bool pd(db a,db b){
    return (a-b<=jd)&&(b-a<=jd);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> d[i];
        a[i]=d[i];
    }
    while(m--){
        int opt,x;
        cin >> opt;
        db v;
        if(opt==1){
            cin >> x >> v;
            int l1=x,r1=x,l2=x,r2=x;
            while(v>0){
                if(a[x]==0)break;
                while(pd(a[l2+1],a[l2]))l2++;
                while(pd(a[r2-1],a[r2]))r2--;
                while(a[l2-1]<a[l2])l2--;
                while(a[r2+1]<a[r2])r2++;
                l1=l2,r1=r2;
                while((pd(a[l1-1],a[l1])))l1--;
                while(pd(a[r1+1],a[r1]))r1++;
                db dl=min(a[l1-1]-a[l1],a[l2+1]-a[l2]),
                   dr=min(a[r1+1]-a[r1],a[r2-1]-a[r2]);
                db d;
                if((l2-l1+1)*dl<(r1-r2+1)*dr){
                    db d=min(v,2*(l2-l1+1)*dl);
                    v-=d;
                }else{
                    db d=min(v,2*(r1-r2+1)*dr);
                    v-=d;
                }
                for(int i=l1;i<=l2;i++)a[i]+=d/(l2-l1+1)/2;
                for(int i=r2;i<=r1;i++)a[i]+=d/(r1-r2+1)/2;
            }
        }else{
            cin >> x;
            cout<<a[x]<<"\n";
        }
    }
}
