#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,LM=1e6+7,mod=998244353;
int T;
int n,m,L,V;
int ud[N],li[N],ri[N],P[N];
int ans1,ans2;
struct llrr{
    int l;
	int r;
}lr[N];

bool cmp(llrr x,llrr y){
    if(x.l==y.l)return x.r<y.r;
    else return x.l<y.l;
}

int efq(int x){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(x<P[mid])r=mid-1;
        else if(x==P[mid])return mid;
        else l=mid+1;
        //cout<<l<<" "<<r<<"\n";//
    }
    while(l>0&&P[l]>x)l--;
    while(l<m+1&&P[l+1]<=x)l++;
    return l;
}
int efh(int x){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(x<P[mid])r=mid-1;
        else if(x==P[mid])return mid;
        else l=mid+1;
        //cout<<l<<" "<<r<<"\n";//
    }
    while(r<m+1&&P[r]<x)r++;
    while(r>0&&P[r-1]>=x)r--;
    return r;
}

void solve(){
	ans1=ans2=0;
    cin >> n >> m >> L >> V;
    P[0]=0,P[m+1]=L+1;
    for(int i=1;i<=n;i++){
        int d,v,a;
        cin >> d >> v >> a;
        ud[i]=0;
        if(v>V&&a>=0){li[i]=d,ri[i]=L;}
        else if(v>V&&a<0){
            int sd=((ll)v*v-(ll)V*V)/(2*(-a));
            if((ll)2*sd*(-a)==1ll*v*v-1ll*V*V)sd--;
            li[i]=d,ri[i]=d+sd;
        }else if(v<=V&&a<=0){ud[i]=1;}
        else{//v<=V&&a>0
            int sd=((double)((ll)V*V-(ll)v*v))/(2*a)+1;
            if(1ll*sd*2*a==1ll*V*V-1ll*v*v)sd++;
            li[i]=d+sd,ri[i]=L;
        }
    }
    
    for(int i=1;i<=m;i++)cin>>P[i];
    for(int i=1;i<=n;i++){
        if(ud[i])continue;
        int l=efh(li[i]),r=efq(ri[i]);
        if(l>r)continue;
        ans1++;

        //printf("%d:%d %d:%d %d\n",i,li[i],ri[i],l,r);//
        
        lr[ans1].l=l,lr[ans1].r=r;
    }
    cout<<ans1<<" ";
    sort(lr+1,lr+ans1+1,cmp);
    /*if(T==15){
	cout<<"LR:\n";//
    for(int i=1;i<=ans1;i++)printf("%d:%d %d\n",i,lr[i].l,lr[i].r);//
    cout<<"2:\n";//
	}*/
    int rmi=m+1,ln=0;
    for(int i=1;i<=ans1;i++){
    	if(lr[i].l<ln)continue;
        rmi=min(rmi,lr[i].r);
        if(ln==lr[i].l){
		}else if(rmi>lr[i].l){
        	
        }else if(rmi==lr[i].l){
			ln=lr[i].l+1;
			ans2++;
			rmi=m+1;
			//if(T==15)cout<<"add\n";//
		}
        else{
        	ln=lr[i].l;
        	ans2++;rmi=lr[i].r;
        	//if(T==15)cout<<"add\n";//
		}
        //if(T==15)printf("%d:%d %d\n",i,ln,rmi);//
    }
    if(ln<=lr[ans1].l&&ans1!=0)ans2++;
    cout<<m-ans2<<"\n";
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    while(T--){
        solve();
    }
}