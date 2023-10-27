#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=17,M=2007;
int n,m;
int tcd[M],toc;//totcard
queue<int> hdcd[N];//handcard
//P桃0,K杀1,D闪2,F决3,N南4,W万5,J无懈6,Z连弩7
int bld[N],bel[N],kw[N];//blood,belong,(0,zhu,1,zhong,2,f)
//know(0,unknow,1,know,2,lf)
bool zb[N];
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
    if(!hdcd[reser].empty()&&hdcd[reser].front()==0){
        bld[reser]++;
        hdcd[reser].pop();
        return;
    }
    die[reser]=1;
    if(bel[reser]==2){
        gcd(user,3);
    }else if(bel[user]==0&&bel[reser]==1){
        while(!hdcd[user].empty())hdcd[user].pop();
        zb[user]=0;
    }
}
void tf(int user,int reser){//跳
    if(kw[reser])kw[user]=1;
}
bool gx(int user,int reser,int rreser,int way){//是否无懈
    if(kw[reser]==0)return 0;
    if(way==2||way==0){//4,5,dy
        if(bel[rreser]==0&&(bel[reser]==0||bel[reser]==1))return 1;
        if(bel[rreser]==1&&(bel[reser]==0||bel[reser]==1))return 1;
        if(bel[rreser]==2&&bel[reser]==2)return 1;
    }else{
        if(bel[rreser]==0&&(bel[reser]==2||(kw[reser]==2)))return 1;
        if(bel[rreser]==1&&(bel[reser]==2))return 1;
        if(bel[rreser]==2&&(bel[reser]==1||bel[reser]==0))return 1;
    }
    return 0;
}
bool wx(int user,int reser,int way){//way,0,dy,1,yq,2,zdy
    for(int rreser=user;rreser!=user;rreser=r[rreser]){
        if(hdcd[rreser].empty()||hdcd[rreser].front()!=6)continue;


    }
}
void use(int id,int user,int reser){//id,来源,目标
    if(id==0){
        bld[user]=min(bld[user],4);
    }else if(id==1){
        //kw[user][reser]=2;
        if(!hdcd[reser].empty()&&hdcd[reser].front()==2){
            hdcd[reser].pop();
        }else{
            bld[reser]--;
            if(bld[reser]==0)dead(user,reser);
            tf(user,reser);
        }
    }else if(id==3){//!!!!
        int now=reser,bn=user;
        while(!hdcd[now].empty()&&hdcd[now].front()==1){
            hdcd[now].pop();
            now=(now==user)?reser:user;
            bn=(now==user)?reser:user;
        }
        tf(bn,now);
        bld[now]--;
        if(bld[now]==0)dead(bn,now);
    }else if(id==4){

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
