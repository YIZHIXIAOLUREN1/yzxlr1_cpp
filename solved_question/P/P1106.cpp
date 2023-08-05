#include<bits/stdc++.h>
using namespace std;
string jian(string a,int fir,int las){//��ȥ[fir,las)
	string ans=a.substr(0,fir);
	ans+=a.substr(las,a.length()-las);
	a=ans;
	return ans;
}
string qu0(string a){
	while(!(a[0]-'0')&&a.length()>1){
		a=a.substr(1,a.length()-1);
	}
	return a;
}
void shuans(string a,int mlen,int k){
	int len=a.length()-mlen;
	if(len==k){
		cout << qu0(a.substr(0,mlen)); 
	}
	else{
		int minx;
		char mina='9';
		for(int i=mlen;i<=k+mlen;i++){
			if(mina-a[i]>0){
				minx=i;
				mina=a[i];
			}
		}
		a=jian(a,mlen,minx);
		k=k+mlen-minx;
		if(k<=0){
			cout << qu0(a);
		}
		else{
			shuans(a,1+mlen,k);
		}
	}
}
int main(){
	string a;
	int k,n=a.length();
	cin >> a >> k;
	shuans(a,0,k);
	return 0;
}
