#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+7;
int n;
int a[N],fm[N];
vector<int> G[N];
int col[N];
int q[N],q1[N],q2[N];
int t,t1,t2;
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    fm[n]=n+1;
    for(int i=n;i>=2;i--)fm[i-1]=min(a[i],fm[i]);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(a[i]>=a[j]||fm[j]>=a[i])continue;
            G[i].push_back(j);
            G[j].push_back(i);
            //printf("%d %d\n",i,j);//
        }
    }
    for(int i=1;i<=n;i++)if(!col[i]){
    	q[++t]=i;
    	col[i]=1;
    	while(t){
        	int u=q[t--];
        	for(auto v:G[u]){
            	if(!col[v]){
            	    col[v]=3-col[u];
            	    q[++t]=v;
        	    }else if(col[v]+col[u]!=3){
        	        puts("0");
        	        return 0;
        	    }
    	    }
	    }
    }
    //for(int i=1;i<=n;i++)printf("%d ",col[i]);//
    q1[0]=q2[0]=N;
    int now=1,i=1;
    while(now<n){
    	//cout << now<<i<<"\n";//
    	int p1=q1[t1],p2=q2[t2];
    	if(col[i]==1&&a[i]<p1)q1[++t1]=a[i++],cout<<"a ";
    	else if(p1==now)now++,t1--,cout<<"b ";
        else if(col[i]==2&&a[i]<p2)q2[++t2]=a[i++],cout<<"c ";
        else if(p2==now)now++,t2--,cout<<"d ";
	}
    while(now<=n){
    	int p1=q1[t1],p2=q2[t2];
    	if(col[i]==1&&a[i]<p1)q1[++t1]=a[i++],cout<<"a ";
    	else if(p1==now)now++,t1--,cout<<"b";
        else if(col[i]==2&&a[i]<p2)q2[++t2]=a[i++],cout<<"c ";
        else if(p2==now)now++,t2--,cout<<"d";
	}
}
