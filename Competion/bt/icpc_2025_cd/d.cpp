#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int A,B,n,P,k;
char ans[N],ta;
bool check(int x,int y){
    int res=1;
    if(x)res&=(A==x||(A>=x+2&&A<=x*8));
    else res&=A==0;
    if(y)res&=(B==y||(B>=y+2&&B<=y*8));
    else res&=B==0;
    return res;
}
bool svd;
int kt[N];
void pr(int x,int y){
	//printf("%d %d:\n",x,y);//
    ta=0;
    int ca=A,cb=B;
    int xj;
    if(A==x)xj=0;
    else xj=(A-x+6)/7;
    while(x--){
        //cout<<"1";
        ans[++ta]='1';
        A--;
        if(xj){
            if((A-x)%7==1){
                //cout<<"6";
                ans[++ta]='6';
                A-=6;
            }else{
                //cout<<min(A-x,7);
                ans[++ta]=min(A-x,7)+'0';
                A-=min(A-x,7);
            }
            xj--;
        }else{
            //cout<<"//";
            ans[++ta]='/';
            ans[++ta]='/';
        }
    }
    ans[++ta]='/';
    int yj;
    if(B==y)yj=0;
    else yj=(B-y+6)/7;
    while(y--){
        ans[++ta]='1';
        B--;
        if(yj){
            if((B-y)%7==1){
                ans[++ta]='6';
                B-=6;
            }else{
                ans[++ta]=min(B-y,7)+'0';
                B-=min(B-y,7);
            }
            yj--;
        }else{
            ans[++ta]='/';
            ans[++ta]='/';
        }
    }
    ans[++ta]='/';
    int ni=1;
    for(int i=2;i<=k+1;i++){
        if(kt[i]==ni)ans[++ta]=i+'0';
        else{
            ans[++ta]='/';
            ans[++ta]=i+'0';
            ni=3-ni;
        }
    }
    if(ni==2)ans[++ta]='/';
    if(P)ans[++ta]='/';
    for(int i=1;i<=ta;i++){
        if(i>=3&&ans[i]=='/'&&ans[i-1]=='/'&&ans[i-2]=='/'){
            for(int j=i-1;j<=ta-2;j++)ans[j]=ans[j+2];
            ta-=2;
            i-=2;
        }
        if(i==ta&&ans[i]=='/'&&ans[i-1]=='/'){
            ta-=2;
            i-=3;
        }
    }
    if(n==21&&ans[ta]=='/'){
    	A=ca,B=cb;
    	return;
    }
    svd=1;
}
void chec(){
    int mn=min(n,15);
    for(int i=0;i<=mn;i++){
        if(check(i,mn-i)){
            pr(i,mn-i);
        }
    }
}

void dfs(int u,int ki,int kj){//2,3,...7
    if(svd)return;
    if(u>k+1){
        if(ki+kj==k){
        	//printf("c%d,%d:%d %d\n",A,B,ki,kj);//
            chec();
        }
        return;
    }
    if(ki+kj<k&&A>=u){
    	//printf("+a:%d\n",u);//
        A-=u;
        kt[u]=1;
        dfs(u+1,ki+1,kj);
        A+=u;
        //printf("-a:%d\n",u);//
        kt[u]=0;
    }
    if(svd)return;
    if(ki+kj<k&&B>=u){
    	//printf("+b:%d\n",u);//
        B-=u;
        kt[u]=2;
        dfs(u+1,ki,kj+1);
        B+=u;
        //printf("-b:%d\n",u);//
        kt[u]=0;
    }
    if(svd)return;
    //if(7-u>=k-ki-kj)dfs(u+1,ki,kj);
}

void Solve(){
    for(int i=2;i<=7;i++)kt[i]=0;
    svd=ta=k=0;
    cin>>A>>B>>n>>P;
    n=21-n;
    if(n<=15){
        chec();
    }else{
        k=n-15;
        dfs(2,0,0);
    }
    if(!svd){
        cout<<"NA\n";
        return;
    }
    for(int i=1;i<=ta;i++)cout<<ans[i];
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*
n=21-n//!!!

i j[0-i]

i+2*j,i+7*j
->i,[i+2,i+7*i]
i [0-15]
->a ->b

n>15{
    k=n-15
    2-7
    k
    (k+3)*k/2,(15-k)*k/2
}
O(lk*15)->2000*27*15
C(6,i)*C(6-i,k-i)=>C(6,k)*2^k//3,320;4,240
2000*320*15//1e7
*/