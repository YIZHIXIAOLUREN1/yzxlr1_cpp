#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n;
int sa[N],sb[N];
int ssa[N],ssb[N];
ll ans;
int ef(int x){
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(2*(sa[x]+sb[mid])<x+mid){
            l=mid+1;
        }else if(2*(sa[x]+sb[mid])>x+mid) r=mid-1;
        else{l=mid;break;}
    }
    //cout<<"A";//
    //while(l>=1&&2*(sa[x]+sb[l-1])>x+l-1)l--;
    //while(l<=n&&2*(sa[x]+sb[l+1])<x+l+1)l++;
    return l;
}
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        ans=0;
        sa[0]=sb[0]=0;
        string s;
        cin>>s;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1')sa[i]=sa[i-1]+1;
            else sa[i]=sa[i-1];
            ssa[i]=ssa[i-1]+sa[i];
        }
        cin>>s;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1')sb[i]=sb[i-1]+1;
            else sb[i]=sb[i-1];
            ssb[i]=ssb[i-1]+sb[i];
        }
        int res=0;
        //for(int i=1;i<=n;i++)printf("%d %d %d\n",i,sa[i],sb[i]);//
        for(int i=1;i<=n;i++){
            int y=ef(i);
            printf("%d：%d\n",i,y);//
            ans+=sa[i]*y+ssb[y]+(n-y)*(i-sa[i])+(n+y+1)*(n-y)/2-(ssb[n]-ssb[y]);
        }
        cout<<ans<<"\n";
    }
}