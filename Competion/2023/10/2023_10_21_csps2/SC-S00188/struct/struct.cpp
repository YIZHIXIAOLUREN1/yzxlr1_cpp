#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=107;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,ni,k;
vector<string> zjs;//nc_name
vector<int> zji;//nc_id
vector<int> zst;//nc_start
ll nle;//nc_r

bool vis[N];
struct node{
    int id;
    string na;//name
    ll sp;//duiqi
    ll r;
    ll len;//dqr
    vector<int> son;//son_id
    vector<int> sst;//son_start
    vector<string> sna;//son_name
}w[N];


void csh();
void cj1();
void my2();
void fy3();
void dj4();

signed main(){
    //freopen("struct.in","r",stdin);
    //freopen("struct.out","w",stdout);
    csh();
    cin >> n;
    while(n--){
        ni++;
        ll op;
        cin >> op;
        //cout <<op<<":";//
        if(op==1)cj1();
        if(op==2)my2();
        if(op==3)fy3();
        if(op==4)dj4();
    }

}

void csh(){
    node by,st,it,lo;
    by.id=101;by.sp=1;by.len=0;
    st.id=102;st.sp=2;st.len=1;
    it.id=103;it.sp=4;it.len=3;
    lo.id=104;lo.sp=8;lo.len=7;
    by.na="byte";st.na="short";
	it.na="int";lo.na="long";
    w[101]=by;w[102]=st;w[103]=it;w[104]=lo;
    vis[104]=vis[103]=vis[102]=vis[101]=1;
}

void cj1(){
    string s;int k;
    cin>>s;
    cin>>k;
    node res;
    res.na=s;res.id=ni;
    res.sp=res.len=0;
    vis[res.id]=1;
    bool ff=0;
    while(k--){
        string t,tn;
        cin>>t>>tn;
        for(int i=104;i>=1;i--){
            if(!vis[i])continue;
            node v=w[i];
            if(v.na==t){
                res.son.push_back(v.id);
                res.sna.push_back(tn);
                res.sp=max(res.sp,v.sp);
                if(res.len||ff)res.len=res.len+v.sp-res.len%v.sp;
                ff=1;
                res.sst.push_back(res.len);
                //if(ni==11)printf("%d:%d %d:%d %d %d\n",k,v.sp,v.len,res.sp,res.len,res.len+v.len);//
                res.len+=v.len;
                break;
            }
        }
    }
    res.r=res.len;
    res.len=res.len+res.sp-res.len%res.sp-1;
    w[res.id]=res;
    cout << res.len+1 <<" "<<res.sp<<"\n";
}

void my2(){
    string t,tn;
    cin>>t>>tn;
    for(int i=104;i>=1;i--){
        if(!vis[i])continue;
        node v=w[i];
        if(v.na==t){
            zjs.push_back(tn);
            zji.push_back(v.id);
            if(nle)nle=nle+v.sp-nle%v.sp;
            cout << nle <<"\n";
            zst.push_back(nle);
            nle+=v.len;
            break;
        }
    }
}

void fy3(){
    string s;
    cin>>s;
    string ns;
    ll res=0,f1=0;
    node v;
    for(int i=0;i<=s.size();i++){
        if(i<s.size()&&s[i]!='.')ns+=s[i];
        else if(!f1){
            for(int j=0;j<zjs.size();j++){
                if(ns==zjs[j]){
                    res=zst[j];
                    v=w[zji[j]];
                    break;
                }
            }
            ns.clear();
            f1=1;
        }else{
            for(int j=0;j<v.sna.size();j++){
                if(ns==v.sna[j]){
                    res=res+v.sst[j];
                    v=w[v.son[j]];
                }
            }
            ns.clear();
        }
    }
    cout << res <<"\n";
}


void dj4(){
	string ans;
    ans.clear();
    ll adr;
    cin>>adr;
    ll res=0,f1=0;
    node v;
    ll l=0;
    for(;l<zji.size();l++)if(zst[l]>adr)break;
	l--;

	if(l<0){cout <<"ERR\n";return;}
    ans+=zjs[l];
    res=zst[l];
    v=w[zji[l]];

    while(v.son.size()){
        l=0;
        for(;l<v.son.size();l++)if(res+v.sst[l]>adr)break;
        l--;
        if(l<0){cout <<"ERR\n";return;}
        ans+=".";
        ans+=v.sna[l];
        res=res+v.sst[l];
        v=w[v.son[l]];
        if(res+v.len<adr){cout <<"ERR\n";return;}
    }
    cout << ans<<"\n";

}
