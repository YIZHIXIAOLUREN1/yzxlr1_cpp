#include<bits/stdc++.h>
using namespace std;
const int N=107,M=507;
int n,m,T;
bool con[4][N][N];
struct point
{
    int x,y;
} st[2],en[2];
bool f[M][N][N];
int pre[4][N][N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("testcase_1_steps22.txt","r",stdin);
    freopen("1.out","w",stdout);
    cin>>n>>m;
    cin>>st[0].x>>st[0].y>>st[1].x>>st[1].y;
    cin>>en[0].x>>en[0].y>>en[1].x>>en[1].y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=3;k++){
                cin>>con[k][i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        int res=0;
        for(int j=1;j<=m;j++)
            if(con[3][i][j])pre[3][i][j]=res,res++;
            else res=0;
        for(int j=m;j>=1;j--)
            if(con[1][i][j])pre[1][i][j]=res,res++;
            else res=0;
    }
    for(int j=1;j<=m;j++){
        int res=0;
        for(int i=1;i<=n;i++)
            if(con[0][i][j])pre[0][i][j]=res,res++;
            else res=0;
        for(int i=n;i>=1;i--)
            if(con[2][i][j])pre[2][i][j]=res,res++;
            else res=0;
    }

    cin>>T;
    f[0][st[0].x][st[0].y]=f[0][st[1].x][st[1].y]=1;
    
    int lx=0,ly=0,res[4];
    for(int t=1;t<=T;t++){
        int x173,y173,x96,y96,f96,x106,y106,x939,y939,L;
        
        cin>>x173>>y173>>x96>>y96>>f96>>x106>>y106>>L>>x939>>y939;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                res[0]=res[1]=res[2]=res[3]=0;
                f[t][i][j]=f[t-1][i][j];
                if(x106&&y106&&(i-x106)*(i-x106)+(j-y106)*(j-y106)<=L*L){f[t][i][j]=0;continue;}
                if(i==x173&&j==y173){f[t][i][j]=0;continue;}
                if(i==x173&&i==x96){
                    if(j<y173&&pre[2][i][j]>=y173-j&&j<y96&&f96==0&&pre[2][i][j]>=y96-j){f[t][i][j]=0;continue;}
                    else if(j>y173&&pre[0][i][j]>=j-y173&&j>y96&&f96==2&&pre[0][i][j]>=j-y96){f[t][i][j]=0;continue;}
                }else if(i==x173&&i==x96){
                    if(i<x173&&pre[1][i][j]>=x173-i&&i<x96&&f96==3&&pre[1][i][j]>=x96-i){f[t][i][j]=0;continue;}
                    else if(i>x173&&pre[3][i][j]>=i-x173&&i>x96&&f96==1&&pre[3][i][j]>=i-x96){f[t][i][j]=0;continue;}
                }
                if(f[t-1][i-1][j]&&con[3][i][j])res[3]=1;
                if(f[t-1][i+1][j]&&con[1][i][j])res[1]=1;
                if(f[t-1][i][j-1]&&con[2][i][j])res[2]=1;
                if(f[t-1][i][j+1]&&con[0][i][j])res[0]=1;
                if(i==x939&&j==y939){
                    if(lx==i-1&&ly==j)res[3]=0;
                    else if(lx==i+1&&ly==j)res[1]=0;
                    else if(lx==i&&ly==j-1)res[2]=0;
                    else if(lx==i&&ly==j+1)res[0]=0;
                }

                if(i==x173){
                    if(j<y173&&pre[2][i][j]>=y173-j)res[2]=0;
                    else if(j>y173&&pre[0][i][j]>=j-y173)res[0]=0;
                }else if(j==y173){
                    if(i<x173&&pre[1][i][j]>=x173-i)res[1]=0;
                    else if(i>x173&&pre[3][i][j]>=i-x173)res[3]=0;
                }
                if(i==x96){
                    if(j<y96&&f96==0&&pre[2][i][j]>=y96-j)res[0]=0;
                    else if(j>y96&&f96==2&&pre[0][i][j]>=j-y96)res[2]=0;
                }else if(j==y96){
                    if(i<x96&&f96==3&&pre[1][i][j]>=x96-i)res[3]=0;
                    else if(i>x96&&f96==1&&pre[3][i][j]>=i-x96)res[1]=0;
                }

                if(res[0]||res[1]||res[2]||res[3])f[t][i][j]=1;
                if(f[t][i][j]==1&&i==1&&(j==en[0].y||j==en[1].y)){
                    cout<<T+1;
                    return 0;
                }
            }
        }
        lx=x939,ly=y939;
    }
}
