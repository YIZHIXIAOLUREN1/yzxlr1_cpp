#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,K,ans;
pair<int,int> a[N],b[N];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.first>y.first;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> K;
        //cout<<n<<" "<<K<<"\n";//
        for(int i=1;i<=n;i++)cin>>a[i].first;
        for(int i=1;i<=n;i++)cin>>b[i].first;
        ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].first<b[i].first)swap(a[i].first,b[i].first);
            a[i].second=b[i].second=i;
            ans+=a[i].first-b[i].first;
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        //for(int i=1;i<=n;i++)cout<<a[i].first<<" "<<a[i].second<<" "<<b[i].first<<" "<<b[i].second<<"\n";//
        int up=1,down=1;
        int res=1e9+7;
        
        while(up<=n&&down<=n){
        	if(b[down].second!=a[up].second&&
        	b[down].first>=a[up].first){
        		res=min(res,b[down].first-a[up].first);
        		//cout<<up<<" "<<down<<" "<<res<<"a\n";//
        	}
            while(down<n&&b[down+1].first>=a[up].first){
                down++;
                if(b[down].second==a[up].second)continue;
                res=min(res,b[down].first-a[up].first);
                //cout<<up<<" "<<down<<" "<<res<<"b\n";//
            }
            up++;
        }
        //cout<<res<<"\n";//
        if(a[n].first>b[1].first)res=0;
        ans+=2*res;
        cout<<ans<<"\n";
    }
}
