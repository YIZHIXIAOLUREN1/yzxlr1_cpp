#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
int n;
struct fl{
	string x;
	int i;
};

string zm[MAXN];
vector <fl> fll[MAXN];
int vis[MAXN];


string sx[MAXN];//�������� 
int sxi=0;

bool cmp(fl a,fl b){
	return a.x<b.x;
}

void output(){
	for(int i=0;i<n-1;i++){
		cout << sx[i] << ".";
	}
	cout << sx[n-1] << endl;
	exit(0);
	return;
}

void dfs(int k,int ni){
	//cout << ni << endl;//
	if(k==n){
		output();
	}
	int fir=zm[ni][zm[ni].size()-1]-'a';
	//cout << sx[sxi-1] << " " << zm[ni] << " ";//
	//cout << fir << " ";//
	//cout << endl;//
	if(!fll[fir].empty()){
		for(int i=0;i<fll[fir].size();i++){
			if(vis[fll[fir][i].i]==0){
				sx[sxi]=fll[fir][i].x;
				sxi++;
				//cout << fli[fir][i] << endl;//
				vis[fll[fir][i].i]=1;
				//for(int i=0;i<n;i++)cout << vis[i] << " ";//
				//cout << fl[fir][i] << endl;//	
				dfs(k+1,fll[fir][i].i);
				sxi--;
				vis[fll[fir][i].i]=0;
				//cout << endl;//
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	string xc;
	fl no;
	int frn[26]={0},lan[26]={0};
	for(int i=0;i<n;i++){
		cin >> xc;
		zm[i]=xc;
		no.x=xc;
		no.i=i;
		fll[xc[0]-'a'].push_back(no);
		frn[xc[0]-'a']++;
		lan[xc[xc.size()-1]-'a']++;
	}//���� 
	
	for(int i=0;i<26;i++){
		if(!fll[i].empty())
			sort(fll[i].begin(),fll[i].end(),cmp);
	}//���� 
	/*
	for(int i=0;i<26;i++){
		//cout << i << " "<< !fl[i].empty();//
		if(!fl[i].empty()){
			
			for(int j=0;j<fl[i].size();j++)cout << fl[i][j] << " ";
			cout << endl;
		}
	}
	*/
	int fir,las;
	int firn=0,lasn=0;
	for(int i=0;i<26;i++){
		if(frn[i]==lan[i]+1){
			fir=i;
			firn++;
		}else if(frn[i]==lan[i]-1){
			las=i;
			lasn++;
		}
	}
	
	if(firn==1&&lasn==1){
		for(int i=0;i<fll[fir].size();i++){
			fl str =fll[fir][i];
			if(str.x[str.x.length()-1]==las&&lan[las]==1)continue;
			sx[sxi]=fll[fir][i].x;
			sxi++;
			vis[fll[fir][i].i]=1;
			dfs(1,fll[fir][i].i);
			sxi--;
			vis[fll[fir][i].i]=0;
		}
	}
	else if(lasn+firn==0){
		for(int i=0;i<26;i++){
			if(!fll[i].empty()){
				for(int j=0;j<fll[i].size();j++){
					sx[sxi]=fll[i][j].x;
					sxi++;
					vis[fll[i][j].i]=1;
					dfs(1,fll[i][j].i);
					sxi--;
					vis[fll[i][j].i]=0;
				}
			}
		}
	}//�����жϽⲢdfs
	
	
	cout << "***\n";
	return 0;
}

