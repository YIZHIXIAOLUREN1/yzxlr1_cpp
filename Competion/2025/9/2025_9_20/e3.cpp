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

bool cdy(db x,db y){
    db yy=x-((int)(x/y))*y;
    return (fabs(yy)<1e-9);
}

pair<int,int> check(db x){
    ll res1=0,res2=0;
    int c1=lower_bound(a.begin(),a.end(),make_pair(x,1),cmp)-a.begin();
    ll l=c1,nx=2;
    //cout<<c1<<" "<<x<<":\n";//
    for(db i=x*2;;i*=2,nx*=2){
        
        while(l<n&&a[l].first<i){
            res1+=(nx-1)*a[l].second;
            if(cdy(a[l].first,x))res2+=(nx/2-1)*a[l].second;
            else res2+=(nx-1)*a[l].second;
            l++;
        }
        //printf("%lf %d %d:%d %d\n",i,l,nx,res1,res2);//
        if(l==n)break;
    }
    //printf("%d %d\n",res1+1,res2);//
    return {res1+1,res2};
}

void dd(db x,int nj){
	//cout<<nj<<":\n";//
    int c1=lower_bound(a.begin(),a.end(),make_pair(x, 1),cmp)-a.begin();
    ll l=c1,nx=2;
    for(db i=x*2;;i*=2,nx*=2){
        while(l<n&&a[l].first<i){
            if(fabs(a[l].first/nx*2-x)<1e-9){
            	//printf("b%lf %d %d:%d:%d\n",i,l,nx,nj,a[l].second);//
                if(nj>=a[l].second*nx/2){
                    nj-=a[l].second*nx/2;
                    a[l].second=a[l].second*nx;
                    a[l].first=a[l].first/nx;
                }else{
                	a.push_back({a[l].first/nx*2,a[l].second*nx/2-nj});
                    a[l].second=nj*2;
                    a[l].first=a[l].first/nx;
                    nj=0;
                }
            }else{
                a[l].first=a[l].first/nx;
                a[l].second=a[l].second*nx;
            }
            //printf("f%lf %d %d:%d\n",i,l,nx,nj);//
            //res+=(nx-1)*al[l];
            l++;
        }
        if(l==n)break;
    }
    sort(a.begin(),a.end(),cmp);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1.in","r",stdin);
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
        //cout<<a.size();//
        sort(a.begin(),a.end(),cmp);
        //for(int i=0;i<n;i++)cout<<a[i].first<<" \n"[i==n-1];//
        db l=0,r=a[n-1].first;
        while(r-l>1e-9){
        	//cout<<l<<" "<<r<<"\n";//
            db mid=(l+r)/2;
            pair<int,int> res=check(mid);
            //printf("%lf:%d %d\n",mid,res.first,res.second);//
            if(res.first<=K){
                r=mid;
            }else if(res.second>K){
                l=mid;
            }else{
                
                dd(mid,K-res.second);
                break;
            }
        }
        //for(int i=0;i<a.size();i++)cout<<a[i].first<<":"<<a[i].second<<" \n"[i==a.size()-1];//
        ans=0;
        ll i=a.size()-1;
        while(X){
            if(X>=a[i].second){
                X-=a[i].second;
                ans=a[i].first;
            }else{
                ans=a[i].first;
                X=0;
            }
            i--;
        }
        cout<<ans<<"\n";
    }
}
