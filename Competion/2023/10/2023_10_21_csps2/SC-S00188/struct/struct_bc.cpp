#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=125;

int n,q,m=3,opt,cnt,szall; map<string,int> mp;
struct Var{int Type,l,r; string Name;}b[N];
struct info{int cnt,req,sz; Var son[N];}a[N];
inline int Next_mtp(int x,int d){return (x+d-1)/d*d;}
signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>q,mp["byte"]=0,mp["short"]=1,mp["int"]=2,mp["long"]=3;
	for (int t=0;t<=3;t++)  a[t].req=a[t].sz=(1<<t);
	while (q--){
		cin>>opt;
		if (opt==1){
			string str,Type_Name; info &cur=a[++m];
			cin>>Type_Name>>cur.cnt,mp[Type_Name]=m;
			for (int i=1,typ;i<=cur.cnt;i++){
				cin>>str>>cur.son[i].Name;
				cur.son[i].Type=typ=mp[str];
				cur.son[i].l=Next_mtp(cur.sz,a[typ].req);
				cur.son[i].r=cur.son[i].l+a[typ].sz-1,cur.sz=cur.son[i].r+1;
				cur.req=max(cur.req,a[cur.son[i].Type].req);
			}
			cur.sz=Next_mtp(cur.sz,cur.req);
			printf("%lld %lld\n",cur.sz,cur.req);
		}
		else if (opt==2){
			int typ; string Type,Name;
			cin>>Type>>Name,typ=mp[Type];
			szall=Next_mtp(szall,a[typ].req),printf("%lld\n",szall);
			b[++n]=Var{typ,szall,szall+a[typ].sz-1,Name},szall+=a[typ].sz;
		}
		else if (opt==3){
			vector<string> Names;
			auto find_names=[&](){
				string str,cur=""; cin>>str;
				for (char ch:str){
					if (ch=='.')  Names.emplace_back(cur),cur="";
					else cur+=ch;
				}
				Names.emplace_back(cur);
			};
			function<void(int,int,int)> find_by_name=[&](int typ,int delt,int names_pos){
				if (names_pos==(int)Names.size()) {printf("%lld\n",delt);return;}
				for (int i=1;i<=a[typ].cnt;i++){
					if (a[typ].son[i].Name==Names[names_pos])
						find_by_name(a[typ].son[i].Type,delt+a[typ].son[i].l,names_pos+1);
				}
			};
			find_names();
			for (int i=1;i<=n;i++){
				if (b[i].Name==Names[0])  find_by_name(b[i].Type,b[i].l,1);
			}
		}
		else{
			int rnk; vector<string> Ans; cin>>rnk;
			function<bool(int,int)> find_by_rank=[&](int typ,int rnk){
				if (typ<=3)  return true;
				for (int i=1;i<=a[typ].cnt;i++){
					if (a[typ].son[i].l<=rnk&&rnk<=a[typ].son[i].r){
						Ans.emplace_back(a[typ].son[i].Name);
						return find_by_rank(a[typ].son[i].Type,rnk-a[typ].son[i].l);
					}
				}
				return false;
			};
			auto solve=[&](){
				for (int i=1;i<=n;i++){
					if (b[i].l<=rnk&&rnk<=b[i].r){
						Ans.emplace_back(b[i].Name);
						return find_by_rank(b[i].Type,rnk-b[i].l);
					}
				}
				return false;
			};
			if (solve()){
				for (int i=0;i<(int)Ans.size();i++){
					if (i)  putchar('.');
					cout<<Ans[i];
				}
				puts("");
			}
			else puts("ERR");
		}
	}
	return 0;
}