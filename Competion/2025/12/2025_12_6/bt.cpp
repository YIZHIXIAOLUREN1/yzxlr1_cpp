#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,a[N],b[N];
ll c[N],cl[N];
pair<int,int> aa[N];
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.second==y.second)return x.first<y.first;
    return x.second<y.second;
}

ll sum0,sum1,len1,len2;

void Solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i].first>>aa[i].second;
    sort(aa+1,aa+n+1,cmp);
    for(int i=1;i<=n;i++)a[i]=aa[i].first,b[i]=aa[i].second;
    for(int i=1;i<=n;i++)c[i]=cl[i]=0;
    sum0=sum1=len1=len2=0;
    int st=0;
	//for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];//
	//for(int i=1;i<=n;i++)cout<<b[i]<<" \n"[i==n];//

    for(int i=1;i<=n;i++){
        if(a[i]>b[i]){
            if(!st)st=i;
            sum0+=a[i];len1++;
        }
    }
    
    //printf("%d:%d %d %d %d\n",st,sum0,len1,sum1,len2);//
    if(!st){cout<<"YES\n";return;}

    for(int i=st;i>=1;i--){
        sum1=len2=0;
        for(int j=i;j<=n;j++){
            if(a[j]<b[i]){sum1+=a[j],len2++;}
        }
        //printf("%d:%d %d %d %d\n",i,sum0,len1,sum1,len2);//
        if((sum0+sum1)<=(len1+len2)*b[i]){cout<<"YES\n";return;}
    }
    
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
