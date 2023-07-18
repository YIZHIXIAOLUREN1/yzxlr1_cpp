#include<bits/stdc++.h>
#define MAXN 10000
#define base 30
#define mod 20000
using namespace std;
struct srin{
	string a;
	vector<int> ans;
};

int n,l,nl=1;
char s[MAXN];
vector<srin> linker[mod+2];

inline void box(int hash,int x){
	int len=linker[hash][x].ans.size();
	//cout << len << " ";//
	if(len>0&&linker[hash][x].ans[len-1]==nl){
		//cout << "fi\n";//
		return;
	}
	linker[hash][x].ans.push_back(nl);
	//cout << linker[hash][x].ans[len] << " ";//
	//cout << endl;//
}

inline void insert(){
	int hash=1;
	for(int i=0;s[i];i++)
		hash=(hash*1ll*base+s[i]-'a')%mod;
	//cout << hash << " ";//
	srin t;
	t.a=s;
	//cout << linker[hash].size() << " ";//
	for(int i=0;i<linker[hash].size();i++){
		if(linker[hash][i].a==t.a){
			//cout << "i ";//
			box(hash,i);
			return;
		}
	}
	//cout <<  "no ";//
	linker[hash].push_back(t);
	box(hash,linker[hash].size()-1);
}

inline void qu(char q[]){
	int hash=1;
	for(int i=0;q[i];i++)
		hash=(hash*1ll*base+q[i]-'a')%mod;
	//cout << hash << " ";//
	srin t;
	t.a=q;
	//cout << linker[hash].size() << " ";//
	for(int i=0;i<linker[hash].size();i++){
		if(linker[hash][i].a==t.a){
			//cout << "fi ";//
			t=linker[hash][i];
			for(int i=0;i<t.ans.size();i++)
				cout << t.ans[i] << " ";
			break;
		}
	}
	cout << endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	while(nl<=n){
		cin >> l;
		for(int i=0;i<l;i++){
			cin >> s;
			//cout << s << " \n";//
			insert();
		}
		nl++;
	}
	
	int m;
	cin >> m;
	m++;
	char qq[MAXN];
	while(--m){
		cin >> qq;
		//cout << qq << " ";//
		qu(qq);
	}
}
