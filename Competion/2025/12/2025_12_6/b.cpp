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
        }else if(st){
            if(a[i]<b[st]){
                sum1+=a[i];len2++;
                int u=upper_bound(b+1,b+n+1,a[i])-b-1;
                c[u]+=sum1;
                cl[u]++;
                //printf("%d %d\n",i,u);//
            }
        }
    }
    
    //printf("%d:%d %d %d %d\n",st,sum0,len1,sum1,len2);//
    if(!st||(sum0+sum1<=(len1+len2)*b[st])){cout<<"YES\n";return;}
    for(int i=st-1;i>=1;i--){
        sum1-=c[i];len2-=cl[i];
        if(a[i]<b[i]){
        	sum1+=a[i];len2++;
	        int u=upper_bound(b+1,b+n+1,a[i])-b-1;
	        c[u]+=sum1;
	        cl[u]++;
	        //printf("%d %d\n",i,u);//
        }
        //printf("%d:%d %d %d %d\n",i,sum0,len1,sum1,len2);//
        if(sum0+sum1<=(len1+len2)*b[i]){cout<<"YES\n";return;}
    }
    cout<<"NO\n";
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}
