#include<bits/stdc++.h>
using namespace std;

int zt[9],mb[9]= {1,2,3,8,0,4,7,6,5};
int dx[4]={-3,3,-1,1};
int cs;
int dep=0,flag=0;
pair<int,double> zy[4];
map<int,long long> past;
map<int,long long>::iterator iter;

int h() {
	int res=0;
	for(int i=0; i<9; ++i)
		if(zt[i]!=mb[i]) res++;
	if(res<=2) return 1;
	return (int)res/1.8;
	
}

bool cmp(pair<int,double> aa,pair<int,double> bb){
	return aa.second < bb.second;
}

long long tz(){
	int res=0,resk=1;
	for(int i=0;i<9;i++){
		res+=zt[i]*resk;
		resk*=8;
	}
	return res;
}

bool pd(){
	iter=past.find(tz());
	if(iter==past.end()) return 1;
	return 0;
}

void cd(){
	int res=tz();
	if(past.empty()) past[1]=res;
	past[past.size()+1]=res;
	
}

void ckk(){//
	for(int i=0;i<9;i++){//
		cout << zt[i] << " ";
		if(i==2||i==5||i==8)cout << endl;
	}
	cout << endl;//
}

void dfs(int x,int dq,int pre){
	if(x+h()>dep||flag) return;
	if(h()==0){
		flag=1;
		return;
	}
	
	int ndq=dq;
	for(int i=0;i<4;i++){
		ndq=dq+dx[i];
		if(ndq<0||ndq>8||(i==2&&dq%3==0)||(i==3&&dq%3==2)||pre+i==3) {
			zy[i]=make_pair(114514,1919810);
			continue;
		}
		swap(zt[dq],zt[ndq]);
		if(pd()){
			zy[i]=make_pair(i,h());
		} else{
			zy[i]=make_pair(114514,1919810);
		}
		swap(zt[dq],zt[ndq]);
	}
	sort(zy,zy+4,cmp);
	for(int i=0;i<4;++i){
		if(zy[i].first>3) continue;
		ndq=dq+dx[zy[i].first];
		swap(zt[dq],zt[ndq]);
		cd();
		//ckk();
		dfs(x+1,ndq,zy[i].first);
		swap(zt[dq],zt[ndq]);
		
	}
}

int main() {
	char a;
	for(int i=0; i<9; ++i) {
		cin >> a;
		zt[i]=a-'0';
		if(zt[i]==0) cs=i;
		
	}
	if(h()==0){
		cout << 0;
		return 0;
	}
	
	
	while(!flag){
		past.clear();
		cd();
		dep++;
		cout << endl << dep << endl << endl;//
		dfs(0,cs,-1);
	}
	cout << dep;
	return 0; 
}
