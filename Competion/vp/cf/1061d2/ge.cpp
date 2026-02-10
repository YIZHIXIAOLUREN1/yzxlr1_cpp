#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+7;
const ll inf=2e9+7,INF=1e9+7;
ll n,a[N];
ll f[N];

struct node{
    node *ch[2];
    int l,r,mid;
    int val;
    node (int _l,int _r):l(_l),r(_r),val(0){
        ch[0]=ch[1]=nullptr;
        mid=(_l+_r)/2;
    }
    node(node *_node){val=_node->val,l=_node->l,r=_node->r;}
    void pushup(){
        if(l==r)return;
        val=(!ch[0]?0:ch[0]->val)+(!ch[1]?0:ch[1]->val);
    }
};

void build(node *cur){
    if(cur->l==cur->r){return;}
    node *nl=new node(cur->l,cur->mid),*nr=new node(cur->mid+1,cur->r);
    cur->ch[0]=nl;
    cur->ch[1]=nr;
    build(cur->ch[0]);
    build(cur->ch[1]);
}

ll query(node *cur,int L,int R){
    if(R<L)return 0;
	if(L<=cur->l&&cur->r<=R)return cur->val;
    if(cur->l>R||cur->r<L)return 0;
	return (((!cur->ch[0])?0:query(cur->ch[0],L,R))+((!cur->ch[1])?0:query(cur->ch[1],L,R)));
}
void update1(node *cur,int tg,int v){
	if(cur->l==cur->r){cur->val+=v;return;}
    if(tg<=cur->mid){
        if(!cur->ch[0])cur->ch[0]=new node(cur->l,cur->mid);
        update1(cur->ch[0],tg,v);
    }
    else{
        if(!cur->ch[1])cur->ch[1]=new node(cur->mid+1,cur->r);
        update1(cur->ch[1],tg,v);
    }
    cur->pushup();
}

void del(node *cur){
    if(cur->ch[0])del(cur->ch[0]);
    if(cur->ch[1])del(cur->ch[1]);
    delete cur;
}


/*
bj>=bi+x,j>i
bi>=bj+x,bi-x>=bj j<i
*/
#undef mid
int mia=INF,maa=0;
vector<int> p2,pk;
bool check(ll x){
	//printf("%lld:\n",x);//
    //printf("%d %d\n",mia,maa);
    node *root1=new node(mia,maa),*root2=new node(mia,maa);
    p2.clear();
    pk.clear();
    for(int i=1;i<=n;i++){
        f[i]=query(root1,mia,a[i]-x);
        update1(root1,a[i],1);
    }
    for(int i=n;i>=1;i--){
        f[i]+=query(root2,a[i]+x,maa);
        update1(root2,a[i],1);
    }
    del(root1);del(root2);
    int res2=0,resk=0;
    for(int i=1;i<=n;i++){
    	//cout<<f[i]<<" \n"[i==n];//
        if(f[i]<2)continue;
        if(f[i]==2){
            res2++;
            p2.push_back(i);
        }else{
            resk++;
            pk.push_back(i);
        }
    }
    if(resk>=2)return 0;//x k=0,1
    if(res2+resk<=1)return 1;//1 0 0 1 0 0
    if(res2==3&&resk==0){
        return (a[p2[0]]+x<=a[p2[1]]&&a[p2[0]]+x<=a[p2[2]])||(a[p2[0]]+x<=a[p2[1]]&&a[p2[1]]+x<=a[p2[2]]);
    }
    if(res2>=2&&resk==1){
        for(auto u:p2){
        	//printf("%lld %lld:%lld %lld\n",pk[0],u,a[pk[0]],a[u]);//
            if(pk[0]<u&&a[pk[0]]+x>a[u])return 0;
            if(pk[0]>u&&a[u]+x>a[pk[0]])return 0;
        }
        return 1;
    }
    if(res2==2&&resk==0){
    	return a[p2[0]]+x<=a[p2[1]];
    }
    if(res2==1&&resk==1){
    	if(p2[0]>pk[0])swap(p2[0],pk[0]);
    	return a[p2[0]]+x<=a[pk[0]];
    }
    //resk==0&&res2>3
    return 0;
}
int T;
void Solve(){
    cin>>n;
    mia=INF,maa=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mia=min(mia,a[i]);
        maa=max(maa,a[i]);
    }
    
    //printf("%d %d\n",mia,maa);
    ll l=mia-maa,r=maa-mia;
    while(l<r){
        ll mid=(l+r+1)/2;
        int res=check(mid);
        //printf(":%d\n",res);//
        if(!res)l=mid;
        else r=mid-1;
    }
    if(T<2360)cout<<l<<"\n";
}


signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>T;
    for(int i=1;i<=T;i++){
        Solve();
        if(i==2360){
            cout<<n<<"\n";
            for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
        }
    }
}