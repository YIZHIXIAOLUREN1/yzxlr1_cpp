#include<bits/stdc++.h>
using namespace std;
#define MAXN 114514
int l;
struct Matrix{
	long long M[MAXN][MAXN];
	void clear(){
		memset(M,0,sizeof(M));
	}
	void reset(){
		clear();
		for(int i=0;i<l;++i)M[i][i]=1; 
	}
	Matrix friend operator *(const Matrix &A,const Matrix &B){
		Matrix Ans;Ans.clear();
		for(int i=0;i<l;++i)
			for(int j=0;j<l;++j)
				for(int k=0;k<l;++k)
					Ans.M[i][j]+=A.M[i][k]*B.M[k][j];
		return Ans;
	}
};
