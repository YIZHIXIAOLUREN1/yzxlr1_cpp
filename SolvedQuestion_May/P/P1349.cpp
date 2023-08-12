#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,mod;
int a1,a2;
struct Matrix{
	long long M[2][2];
	void clear(){
		memset(M,0,sizeof(M));
	}
	void reset(){
		clear();
		for(int i=0;i<2;++i)M[i][i]=1; 
	}
	Matrix friend operator *(const Matrix A,const Matrix B){
		Matrix Ans;Ans.clear();
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					Ans.M[i][j]=(Ans.M[i][j]+1ll*A.M[i][k]*B.M[k][j])%mod;
		return Ans;
	}
	void pr(){
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				cout << M[i][j] << " \n"[j==1];
			}
		}
	}
}base;

Matrix qp(Matrix a,int q){
    Matrix res;
    res.reset();
    while(q){
        if(q&1)res=res*a;
        a=a*a;
        q>>=1;
        // cout<<q<<":\n";//
        // res.pr();//
        // a.pr();//
        // cout<<"\n";//
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    base.clear();
    cin >> base.M[0][0] >> base.M[0][1] >> a1 >> a2 >> n >> mod;
    //mod=1145141919;//
    base.M[1][0]=1;
    if(n==1)cout << a1;
    else if(n==2)cout << a2;
    else{
        base=qp(base,n-2);
        //base.pr();//
        cout << (base.M[0][0]*a2+base.M[0][1]*a1)%mod;
    }
}
