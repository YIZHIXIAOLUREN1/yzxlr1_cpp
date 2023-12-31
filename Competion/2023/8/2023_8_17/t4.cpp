#include<bits/stdc++.h>
using namespace std;
#define db double
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
//#define len (r-l+1)
const int N=1e6+7,inf=-1000000;
int n,m;
int a[N];
struct node{
    int l,r;
    int cnt;
    int ans,lea;
    int la,lel,ra,ler;
    void ou(){
    	printf("%d %d:%d:%d %d:%d %d:%d %d\n",//
    	l,r,cnt,ans,lea,la,lel,ra,ler);//
    }
}w[N*4],ze;

bool cmp(int a,int b,int c,int d){
	return a*d>b*c;
}

node operator + (node a,node b){
    if(a.la==inf)return b;
    if(b.la==inf)return a;
    node res;
    res.l=a.l,res.r=b.r;
    res.cnt=a.cnt+b.cnt;
    if(((db)a.ans)/a.lea>((db)b.ans)/b.lea)res.ans=a.ans,res.lea=a.lea;
    else res.ans=b.ans,res.lea=b.lea;
    if(((db)res.ans)/res.lea<((db)(a.ra+b.la))/(a.ler+b.lel))
    res.ans=a.ra+b.la,res.lea=a.ler+b.lel;

    if(((db)a.la/a.lel)>((db)(a.cnt+b.la))/(a.r-a.l+1+b.lel))res.la=a.la,res.lel=a.lel;
    else res.la=a.cnt+b.la,res.lel=a.r-a.l+1+b.lel;

    if(((db)b.ra)/b.ler>((db)(b.cnt+a.ra))/(b.r-b.l+1+a.ler))res.ra=b.ra,res.ler=b.ler;
    else res.ra=b.cnt+a.ra,res.ler=b.r-b.l+1+a.ler;

    if(res.lel>1&&((db)res.ans)/res.lea<((db)res.la)/res.lel)
        res.ans=res.la,res.lea=res.lel;
    if(res.ler>1&&((db)res.ans)/res.lea<((db)res.ra)/res.ler)
        res.ans=res.ra,res.lea=res.ler;
    return res;
}

int laz[N*4];

void pushup(int u){
    w[u]=w[ls]+w[rs];
}

void maketag(int u,int x){
    laz[u]+=x;
    w[u].cnt+=x*(w[u].r-w[u].l+1);
    w[u].ans+=x*w[u].lea;
    w[u].la+=x*w[u].lel;
    w[u].ra+=x*w[u].ler;
}

void pushdown(int u){
    maketag(ls,laz[u]);
    maketag(rs,laz[u]);
    laz[u]=0;
}

void build(int u,int l,int r){
    laz[u]=0;
    if(l==r){
        w[u].l=w[u].r=l;
        w[u].lea=w[u].lel=w[u].ler=1;
        w[u].cnt=w[u].la=w[u].ra=a[l];
        w[u].ans=inf;
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
    //printf("%d:%d %d:\n",u,l,r);//
    //w[u].ou();//
}

void changeq(int u,int L,int R,int x){
	//printf("%d:%d %d:%d:\n",u,L,R,x);//
    if(w[u].r<L||w[u].l>R)return;
    if(w[u].l>=L&&w[u].r<=R){
        maketag(u,x);
        //w[u].ou();//
        return;
    }
    pushdown(u);
    changeq(ls,L,R,x);
    changeq(rs,L,R,x);
    pushup(u);
    //w[u].ou();//
}

node query(int u,int L,int R){
	node res;
    if(w[u].r<L||w[u].l>R)res=ze;
    else if(w[u].l>=L&&w[u].r<=R){
        res=w[u];
    }else{
    	pushdown(u);
    	res=query(ls,L,R)+query(rs,L,R);
    }
    //printf("%d:\n",u);//
    //res.ou();//
    return res;
}

int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ze.l=ze.r=ze.lea=ze.lel=ze.ler=1;
    ze.cnt=ze.ans=ze.la=ze.ra=inf;
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    int ch,ll,rr,xx;
    build(1,1,n);
    while(m--){
        cin >> ch >> ll >> rr;
        if(ch==1){
            cin >> xx;
            changeq(1,ll,rr,xx);
        }else{
        	int fl=1;
            node an = query(1,ll,rr);
            if(an.ans<0)fl=-1,an.ans=-an.ans;
            int g=gcd(an.ans,an.lea);
            cout << fl*an.ans/g << "/" << an.lea/g <<"\n";
        }
    }
}