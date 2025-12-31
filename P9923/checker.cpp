#include"testlib.h"
#define M 500009
using namespace std;
int n,m,u[M],v[M];bool w[M],deg[M];
main(int ac,char**av)
{
	registerTestlibCmd(ac,av);
	string a=ans.readToken();
	ouf.readToken(a);
	if(a=="NIE")quitf(_ok,"NIE");
	int n=inf.readInt(1,100000),m=inf.readInt(1,500000);
	for(int i=1;i<=m;++i)u[i]=inf.readInt(1,n),v[i]=inf.readInt(1,n)+n;
	if(!ouf.eof())ouf.readEoln();
	if(ouf.eof())quitp(0.5,"TAK");
	int k=ouf.readInt(0,m,"k");
	if(!k)quitp(0.5,"k=0");
	for(int x;k--;)
	{
		x=ouf.readInt(1,m);
		if(w[x])quitp(0.5,"duplicate");
		w[x]=1;deg[u[x]]^=1;deg[v[x]]^=1;
	}
	for(int i=1;i<=n<<1;++i)if(deg[i]^deg[1])quitp(0.5,"neq");
	quitf(_ok,"TAK");
}