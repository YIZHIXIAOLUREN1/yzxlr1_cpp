#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,K,L,R;
int a[N],b[N],cnt;
int c1[N],c2[N];
ll ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>K>>L>>R;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
            c1[i]=c2[i]=0;
        }
        sort(b+1,b+n+1);
        cnt=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=n;i++)
            a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
		
		//for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];//
        int l=1,r=1,ck1=0,ck2=0;
        // for(int i=1;i<=L-1;i++){
            // if(!c1[a[i]])ck1++;ck2++;
            // c1[a[i]]++;c2[a[i]]++;
        // }
        //cout<<ck1<<" "<<ck2<<"\n";//
        for(int i=1;i<=n;i++){
            if(!c1[a[i]])ck1++;
            if(!c2[a[i]])ck2++;
            c1[a[i]]++;c2[a[i]]++;
            while(r<i-R+1){c2[a[r]]--;if(!c2[a[r]])ck2--;r++;}
            while(l<i-R+1){c1[a[l]]--;if(!c1[a[l]])ck1--;l++;}
            while(r<i-L+1&&ck2>K){c2[a[r]]--;if(!c2[a[r]])ck2--;r++;}
            while(r<i-L+1&&ck2==K&&c2[a[r]]>1){c2[a[r]]--;r++;}
            while(l<i-L+1&&ck1>K){c1[a[l]]--;if(!c1[a[l]])ck1--;l++;}
            if(ck1==K&&ck2==K&&(i-l+1)<=R&&(i-r+1)>=L){
                ans=ans+(r-l+1);
            }
        }
        cout<<ans<<"\n";
    }
}
