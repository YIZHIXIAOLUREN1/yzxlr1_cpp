#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,ni,k;
vector<string> zjs;
vector<int> zji;
vector<int> zss;
ll nle;

string si(){
	string s;
	s="            ";
	int len=0;
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	while((ch>='a'&&ch<='z')||ch=='.'){
		s[len++]=ch;
		ch=getchar();
	}
	return s;
}

bool vis[N];
struct node{
    int id;
    string na;
    ll sp;
    ll len;
    vector<int> son;
    vector<int> sss;
    vector<string> sna;
}w[N];


void csh();
void cj();
void my();
void fy();
void dj(){
	string ans="                                                            ";
	ll alen=-1;
    ll adr;
    cin >> adr;
    ll res=0,f1=0;
    node v;
    ll l=0;
    for(;l<zji.size();l++){
    	//printf("%d:%d\n",l,zss[l]);//
    	if(zss[l]>adr){
    		l--;
    		break;
		}
	}
	if(l==zji.size())l--;
	if(l<0)cout <<"ERR\n";
	for(int i=0;i<zjs[l].size();i++){
		if(zjs[l][i]!=' '){
			ans[++alen]=zjs[l][i];
		}
		else break;
	}
    res=zss[l];
    v=w[zji[l]];
    //printf("%d:%d:%d\n",zji[l],l,v.sss.size());//
    while(v.son.size()){
        for(int i=0;i<v.son.size();i++){
        	//printf("%d:%d\n",i,res+v.sss[i]);//
            if(res+v.sss[i]>adr){
                l=i-1;
                break;
            }
            l=i;
        }
        ans[++alen]='.';
        for(int i=0;i<v.sna[l].size();i++){
			if(v.sna[l][i]!=' ')ans[++alen]=v.sna[l][i];
			else break;
		}
        res=res+v.sss[l];
        v=w[v.son[l]];
        //printf("%d:%d\n",l,res);//
        if(l<0||res+v.len-1<adr){
            cout <<"ERR\n";
            return;
        }
    }
    for(int i=0;i<ans.size();i++)if(ans[i]!=' ')cout<<ans[i];
    cout <<"\n";
    //cout << res <<"\n";//
}

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    csh();
    cin >> n;
    while(n--){
        ni++;
        ll op;
        cin >> op;
        if(op==1)cj();
        if(op==2)my();
        if(op==3)fy();
        if(op==4)dj();
    }

}

void csh(){
    node by,st,it,lo;
    by.id=101;by.sp=1;by.len=1;
    st.id=102;st.sp=2;st.len=2;
    it.id=103;it.sp=4;it.len=4;
    lo.id=104;lo.sp=8;lo.len=8;
    by.na="byte        ";st.na="short       ";
	it.na="int         ";lo.na="long        ";
    w[101]=by;w[102]=st;w[103]=it;w[104]=lo;
    vis[104]=vis[103]=vis[102]=vis[101]=1;
}

// const int m1=998244353,m2=1e9+7;
// int hx2(string s){
//     int r1,r2;
//     for(int i=0;i<s.size();i++){
//         r1+=s[i]-'a';r1%=m1;
//         r2+=s[i]-'a';r2%=m2;
//     }
//     return r1,r2;
// }

void cj(){
    string s;int k;
    s=si();
    cin >> k;
    node res;
    res.na=s;res.id=ni;
    res.sp=res.len=0;
    vis[res.id]=1;
    bool ff=0;
    while(k--){
        string t,tn;
        t=si();tn=si();
        //cout << t << tn<<"\n";//
        for(int i=104;i>=1;i--){
            if(!vis[i])continue;
            node v=w[i];
            //cout << i << v.na<<"\n";//
            if(v.na==t){
                res.son.push_back(v.id);
                res.sna.push_back(tn);
                res.sp=max(res.sp,v.sp);
                if(res.len||ff)res.len=res.len+v.sp-res.len%v.sp;
                ff=1;
                res.sss.push_back(res.len);
                res.len+=v.len-1;
                //cout << i << v.na<<v.len<<" "<< res.len<<"\n";//
                break;
            }
        }
    }
    res.len=res.len+res.sp-res.len%res.sp-1;
    w[res.id]=res;
    cout << res.len+1 <<" "<<res.sp<<"\n";
}

void my(){
    string t,tn;
    t=si();tn=si();
    for(int i=104;i>=1;i--){
        if(!vis[i])continue;
        node v=w[i];
        if(v.na==t){
            zjs.push_back(tn);
            zji.push_back(v.id);
            if(nle)nle=nle+v.sp-nle%v.sp;
            cout << nle <<"\n";
            zss.push_back(nle);
            nle+=v.len-1;
            break;
        }
    }
}

void fy(){
    string s;
    s=si();
    char ns[12];
    ll lns=-1,res=0,f1=0;
    node v;
    for(int i=0;i<12;i++){
        if(s[i]!='.'&&s[i]!=' '){
        	ns[++lns]=s[i];
		}
        else if(!f1){
        	//cout << ns <<"\n";//
            for(int j=0;j<zjs.size();j++){
                string t=zjs[j];
                bool f=1;
                //cout << t<<":\n";//
                for(int k=0;k<=lns;k++){
                	//printf("%c:%c:%d\n",ns[k],t[k],ns[k]!=t[k]);//
                	if(ns[k]!=t[k])f=0;
				}
                //cout <<f;//
                if(lns<11&&t[lns+1]!=' ')f=0;
                //cout <<f;//
                if(f){
                    res=zss[j];
                    //printf("%d:\n",res);//
                    v=w[zji[j]];
                    break;
                }
            }
            lns=-1;
            f1=1;
        }else{
        	//cout << ns <<"\n";//
            for(int j=0;j<v.sna.size();j++){
                string s=v.sna[j];
                bool f=1;
                for(int k=0;k<=lns;k++)if(ns[k]!=s[k])f=0;
                if(lns<11&&s[lns+1]!=' ')f=0;
                if(f){
                    res=res+v.sss[j];
                    //printf("%d:\n",res);//
                    v=w[v.son[j]];
                }
            }
            lns=-1;
        }
        if(s[i]==' ')break;
    }
    cout << res <<"\n";
}