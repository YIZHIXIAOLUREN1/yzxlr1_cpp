#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=17,M=2007;
int n,m;
int tcd[M],toc;//totcard
queue<int> hdcd[N];//handcard
//P桃0,K杀1,D闪2,F决3,N南4,W万5,J无懈6,Z连弩7
int bld[N],bel[N],kw[N];//blood,belong,know(0,unkonw,1,z,2,f,3,lf)
bool die[N];
int l[N],r[N];

int jl(int user,int reser){
    int res=0,now=user;
    while(now!=reser)now=r[now],res++;
    return res;
}
void gcd(int id,int num){//getcard
    while(num--){
        int cd;
        if(toc>0)cd=tcd[toc--];
        else cd=tcd[0];
        hdcd[id].push(cd);
    }
}
void dead(int user,int reser){
    die[reser]=1;
    if(bel[reser]==2){
        gcd(user,3);
    }else if(bel[user]==0&&bel[reser]==1){
        while(!hdcd[reser].empty())hdcd[reser].pop();
    }
}
void dy(int user,int reser){//敌意

}
void use(int id,int user,int reser){//id,来源,目标
    if(id==0){
        bld[user]=min(bld[user],4);
    }else if(id==1){
        //kw[user][reser]=2;
        if(hdcd[reser].front()==2){
            hdcd[reser].pop();
        }else{
            bld[reser]--;
            if(bld[reser]==0){
                if(hdcd[reser].front()==0)bld[reser]++,hdcd[reser].pop();
                else dead(user,reser);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    toc=m;
    for(int i=1;i<=n;i++){
        l[i]=(i-1<1)?n:(i-1);
        r[i]=(i+1>n)?1:(i+1);
        string be,car;
        cin >> be;
        if(be=="MP")bel[i]=0;
        else if(be=="ZP")bel[i]=1;
        else bel[i]=2;
        for(int j=1;j<=4;j++){
            cin >> car;
            if(car=="P")hdcd[i].push(0);
            else if(car=="K")hdcd[i].push(1);
            else if(car=="D")hdcd[i].push(2);
            else if(car=="F")hdcd[i].push(3);
            else if(car=="N")hdcd[i].push(4);
            else if(car=="W")hdcd[i].push(5);
            else if(car=="J")hdcd[i].push(6);
            else hdcd[i].push(7);
        }
    }
    
    return 0;
}
