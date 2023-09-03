#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7,inf=0x3f3f3f3f;
int n,m,Q;
int fl[N][33],fr[N][33];
int gl[N][33],gr[N][33];
int hl[N],hr[N];
int q[N],head,top;
vector<int> Gl[N],Gr[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> Q;
    for(int i=0;i<=n+1;i++){
    	for(int j=0;j<=32;j++){
    		hl[i]=fr[i][j]=gr[i][j]=n+2;
    		hr[i]=-1;
		}
	}
    for(int i=1,u,v;i<=m;i++){
        cin >> u >> v;
        Gl[u].push_back(v);
        Gr[v].push_back(u);
        fl[u][0]=max(fl[u][0],v+1);
        fr[v][0]=min(fr[v][0],u-1);
        gl[u][0]=max(gl[u][0],v+1);
        gr[v][0]=min(gr[v][0],u-1);
        hl[u]=min(hl[u],v+1);
        hr[v]=max(hr[v],u-1);
    }
    
    head=1,top=0;
    for(int i=1;i<=n;i++){
        gl[i][0]=max(gl[i][0],gl[i-1][0]);
        if(gl[i][0]<=i)gl[i][0]=0;
        while(head<=top&&q[head]<=i)head++;
        sort(Gl[i].begin(),Gl[i].end());
        for(auto v:Gl[i]){
            while(head<=top&&q[top]>=v+1)top--;
            q[++top]=v+1;
        }
        if(head<=top)hl[i]=q[head];
        //printf("L%d:%d:%d %d\n",i,hl[i],head,top);//
    }
    head=1,top=0;
    for(int i=n;i>=1;i--){
        gr[i][0]=min(gr[i][0],gr[i+1][0]);
        if(gr[i][0]>=i)gr[i][0]=n+1;
        while(head<=top&&q[head]>=i)head++;
        sort(Gr[i].begin(),Gr[i].end(),cmp);
        for(auto v:Gr[i]){
            while(head<=top&&q[top]<=v-1)top--;
            q[++top]=v-1;
        }
        if(head<=top)hr[i]=q[head];
        //printf("R%d:%d\n",i,hr[i]);//
    }
    
    for(int i=1;i<=32;i++){
        for(int j=1;j<=n;j++){
            gl[j][i]=max(gl[gl[j][i-1]][i-1],gl[j][i-1]);
            fl[j][i]=max(gl[fl[j][i-1]][i-1],fl[j][i-1]);
        }
        for(int j=n;j>=1;j--){
            gr[j][i]=max(gr[gr[j][i-1]][i-1],gr[j][i-1]);
            fr[j][i]=max(gr[fr[j][i-1]][i-1],fr[j][i-1]);        }
    }
    
    int L,R;
    while(Q--){
        cin >> L >> R;
        int ml=L,mr=R;
        bool flag=1;
        while((gl[ml][0]<=R+1||(ml==L&&fl[ml][0]<=R+1))&&flag){
        	flag=0;
            for(int i=32;i>=0;i--){
            	//printf("L:%d:%d:%d %d\n",i,ml,fl[ml][i],gl[ml][i]);//
                if(ml==L){
                    if(fl[ml][i]>R+1||fl[ml][i]<=ml)continue;
                    ml=fl[ml][i];
                    flag=1;
                }else{
                    if(gl[ml][i]>R+1||gl[ml][i]<=ml)continue;
                    ml=gl[ml][i];
                    flag=1;
                }
            }
        }
        flag=1;
        while(hl[ml]<=R+1&&flag&&ml!=L){
        	//printf("l:%d:%d\n",ml,hl[ml]);//
            flag=0;
            if(hl[ml]>ml)ml=hl[ml],flag=1;
        }

		flag=1;
         while((gr[mr][0]>=L-1||(mr==R&&fr[mr][0]>=L-1))&&flag){
         	flag=0;
            for(int i=32;i>=0;i--){
            	//printf("R:%d:%d:%d %d\n",i,mr,fr[mr][i],gr[mr][i]);//
                if(mr==R){
                    if(fr[mr][i]<L-1||fr[mr][i]>=mr)continue;
                    mr=fr[mr][i];
                    flag=1;
                }else{
                    if(gr[mr][i]<L-1||gr[mr][i]>=mr)continue;
                    mr=gr[mr][i];
                    flag=1;
                }
            }
        }
        flag=1;
        while(hr[mr]>=L-1&&flag&&mr!=R){
        	//printf("r:%d:%d\n",mr,hr[mr]);//
            flag=0;
            if(hr[mr]<mr)mr=hr[mr],flag=1;
        }
		//printf("%d %d\n",ml,mr);//
        if(ml>mr)cout<<"YES\n";
        else cout<<"NO\n";
    }
}