#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+7;
int n,K,a[N];
int pre[N];

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
        val=ch[0]->val+ch[1]->val;
    }
}*root1,*root2;

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
	return (query(cur->ch[0],L,R)+query(cur->ch[1],L,R));
}
void update1(node *cur,int tg,int v){
	if(cur->l==cur->r){cur->val+=v;return;}
    if(tg<=cur->mid)update1(cur->ch[0],tg,v);
    else update1(cur->ch[1],tg,v);
    cur->pushup();
}

class Fenw {
public:
    int n;
    vector<int> bit;
    Fenw(int n) : n(n), bit(n+1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) {
            s += bit[i];
        }
        return s;
    }
};

void upd(){
    vector<int> C(n+1);
    Fenw F_val(n);
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1) {
            C[i] = F_val.query(a[i]-1);
        } else {
            C[i] = 0;
        }
        F_val.update(a[i], 1);
    }

    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        p[a[i]] = i;
    }

    Fenw F_idx(n);

    for (int v = 1; v <= n; v++) {
        int i = p[v];
        if (K == 0) {
            pre[i] = i;
        } else if (K > C[i]) {
            pre[i] = 0;
        } else {
            int r = C[i] - K + 1;
            int low = 1, high = n;
            int pos = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                int s = F_idx.query(mid);
                if (s >= r) {
                    pos = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            pre[i] = pos;
        }
        F_idx.update(i, 1);
    }
}

void upd1(int x){
	if(query(root1,1,a[x]-1)<K)pre[x]=0;
    else{
    	int res=0;
	    for(int j=x-1;j>=1;j--){
	        if(a[j]<a[x])res++;
	        if(res==K){
	            pre[x]=j;
	            break;
	        }
	    }
    }
    update1(root1,a[x],1);
}

vector<tuple<int,int,int>> qq;
bool cmp1(tuple<int,int,int> &x,tuple<int,int,int> &y){
    return get<2>(x)<get<2>(y);
}
bool cmp2(tuple<int,int,int> &x,tuple<int,int,int> &y){
    return get<0>(x)<get<0>(y);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int Q;
    cin>>n>>K>>Q;
    root1=new node(1,n),root2=new node(0,n);
    build(root1);build(root2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
        //upd1(i);
    }
    upd();
    for(int i=1;i<=n;i++){
    	//cout<<i<<":"<<pre[i]<<"\n";//
    }
    for(int i=1;i<=Q;i++){
        int l,r;
        cin>>l>>r;
        qq.push_back(make_tuple(i,l,r));
    }
    sort(qq.begin(),qq.end(),cmp1);
    int j=1;
    update1(root2,pre[1],1);
    for(int i=1;i<=Q;i++){
        auto [ignore1,l,r]=qq[i-1];
        while(j<r){j++;update1(root2,pre[j],1);}
        get<1>(qq[i-1])=r-l+1-query(root2,l,r);
    }
    sort(qq.begin(),qq.end(),cmp2);
    for(auto [ignore1,ans,ignore3]:qq)cout<<ans<<"\n";
}
