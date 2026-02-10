#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int f[2][N],vis[2][N],pt[N],pv[N];
vector<int> pre[N];

int minimumInstructions(int N, int M, int K, std::vector<int> C,
std::vector<int> A, std::vector<std::vector<int>> B){
	for(int i=0;i<=M;i++)vis[0][i]=-1;
    for(int i=0;i<M;i++){
        for(int j=0;j<A[i];j++){
            pre[B[i][j]].push_back(i);
        }
    }
    for(int i=0;i<=N+M-2;i++){
        int ni=i&1,li=(i&1)^1;
        for(auto j:pre[C[i%N]]){
            vis[ni][j]=i;
            f[ni][j]=1;
            if(i&&vis[li][(j-1+M)%M]==i-1)f[ni][j]=f[li][(j-1+M)%M]+1;
            if(f[ni][j]>=M){
                pt[i%N]=1;
            }
        }
    }
    int ans=0,len=N+M-1,llen=0,st=N-1;
    for(int i=N-1;i>=0;i--)if(pt[i]){st=i;break;}
    for(int i=N+st;i>st;i--){
        if(pt[i%N]){
            ans++;
            int ni=0;
            for(int j=max(i-M+1,st);j<=i;j++){
                pv[j%N]=1;
                if(!ni&&pt[j%N]&&j<i)ni=j;
            }
            if(pt[max(i-M,st)%N])ni=max(i-M,st);
            if(ni)i=ni+1;
            else i=max(i-M+1,st);
        }else return -1;
    }
    
    for(int i=0;i<N;i++)if(!pv[i])ans=-1;
    return ans;
}

int main()
{
	int N, M, K;
	assert(3 == scanf("%d %d %d", &N, &M, &K));

	std::vector<int> C(N);
	for (int i = 0; i < N; ++i)
	{
		assert(1 == scanf("%d", &C[i]));
	}

	std::vector<int> A(M);
	std::vector<std::vector<int>> B(M);
	for (int i = 0; i < M; ++i)
	{
		assert(1 == scanf("%d", &A[i]));
		B[i].resize(A[i]);
		for (int j = 0; j < A[i]; ++j)
		{
			assert(1 == scanf("%d", &B[i][j]));
		}
	}
	// cout<<"A";//
	int minimum_instructions = minimumInstructions(N, M, K, C, A, B);
	printf("%d\n", minimum_instructions);

	return 0;
}