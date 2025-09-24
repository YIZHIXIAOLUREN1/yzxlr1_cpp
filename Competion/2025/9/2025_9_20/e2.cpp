#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int N=1e5+7;
int n,K,X;
vector<pair<db,int> > a;
db ans;

bool cmp(pair<db,int> x,pair<db,int> y){
    return x.first<y.first;
}

ll check(db x){
    ll res=0;
    int c1=lower_bound(a.begin(),a.end(),make_pair(x,1),cmp)-a.begin();
    ll l=c1,nx=2;
    cout<<c1<<"\n";//
    for(db i=c1;l<n;i*=2,nx*=2){
        while(l<n&&a[l].first<=i){
            res+=(nx-1)*a[l].second;
            l++;
        }
    }
    return res;
}

void dd(db x){
    int c1=lower_bound(a.begin(),a.end(),make_pair(x, 1),cmp)-a.begin();
    ll l=c1,nx=2;
    for(db i=c1;l<n;i*=2,nx*=2){
        while(l<n&&a[l].first<=i){
            a[l].first=a[l].first/nx;
            a[l].second=a[l].second*nx;
            //res+=(nx-1)*al[l];
            l++;
        }
    }
    sort(a.begin(),a.end(),cmp);
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("1.in","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>K>>X;
        a.clear();
        for(int i=1;i<=n;i++){
            pair<db,int> aa;
            cin>>aa.first;
            aa.second=1;
            a.push_back(aa);
        }
        sort(a.begin(),a.end(),cmp);
        for(int i=0;i<n;i++)cout<<a[i].first<<" \n"[i==n-1];//
        db l=0,r=a[n-1].first;
        while(r-l>1e-9){
        	cout<<l<<" "<<r<<"\n";//
            db mid=(l+r)/2;
            ll res1=check(mid);
            if(res1<K){
                dd(mid);
                r=mid;
            }else if(res1>K){
                l=mid;
            }else{
                dd(mid);
                break;
            }
        }
        ans=0;
        ll i=n-1;
        while(X){
            if(X>=a[i].second){
                X-=a[i].second;
                ans+=a[i].first*a[i].second;
            }else{
                ans+=a[i].first*X;
                X=0;
            }
            i--;
        }
        cout<<ans<<"\n";
    }
}
