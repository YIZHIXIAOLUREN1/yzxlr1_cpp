#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=17,M=2007,MM=1e4+7;
int n,m;
int tcd[M],toc;//totcard
//queue<int> hdcd[N];//handcard
int hdcd[N][MM];
bool vhd[N][MM];
int hdr[N];
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
void in(int user,int id){
    hdcd[user][++hdr[user]]=id;
    vhd[user][hdr[user]]=1;
}
int find(int user,int id){
    for(int i=1;i<=hdr[user];i++)
        if(vhd[user][i]&&hdcd[user][i]==id)return i;
    return 0;
}
int fius(int user,int id){//find use
    for(int i=1;i<=hdr[user];i++){
        if(vhd[user][i]&&hdcd[user][i]==id){
            vhd[user][i]=0;
            return i;
        }
    }
    return 0;
}
void gcd(int user,int num){//getcard
    while(num--){
        int cd;
        if(toc>0)cd=tcd[toc--];
        else cd=tcd[0];
        in(user,cd);
    }
}
void dead(int user,int reser){
    if(fius(user,0)){
        bld[reser]++;
        return;
    }
    die[reser]=1;
    if(bel[reser]==2){
        gcd(user,3);
    }else if(bel[user]==0&&bel[reser]==1){
        hdr[user]=0;
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
        if(!find(rreser,6))continue;
        if(!gx(user,reser,rreser,way))continue;
        return use(6,rreser,reser,way);
    }
}
bool use(int id,int user,int reser,int way){//id,来源,目标
    if(id==0){
        bld[user]=min(bld[user],4);
        return 1;
    }else if(id==1){
        //kw[user][reser]=2;
        if(fius(reser,2))return 0;
        else{
            bld[reser]--;
            if(bld[reser]==0)dead(user,reser);
            tf(user,reser);
            return 1;
        }
    }else if(id==3){
        if(wx(user,reser,0))return 0;
        int now=reser,bn=user;
        if(bel[reser]!=1||bel[user]!=0){
            while(fius(now,1)){
                now=(now==user)?reser:user;
                bn=(now==user)?reser:user;
            }
        }
        tf(bn,now);
        bld[now]--;
        if(bld[now]==0)dead(bn,now);
        return 1;
    }else if(id==4){

    }else if(id==5){

    }else if(id==6){
        if(wx(user,reser,))
    }else{

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
            if(car=="P")in(i,0);
            else if(car=="K")in(i,1);
            else if(car=="D")in(i,2);
            else if(car=="F")in(i,3);
            else if(car=="N")in(i,4);
            else if(car=="W")in(i,5);
            else if(car=="J")in(i,6);
            else in(i,7);
        }
    }
    
    return 0;
}
