#include<bits/stdc++.h>
using namespace std;
int n,m,tr=1;
int nx[4]= {-1,1,0,0};
int ny[4]= {0,0,-1,1};
struct qq {
    int x;
    int y;//x,y
    int dx;
    int dy;//duiying
    char node;
    int k;//queue k
};
qq dt[305][305],in,out;
queue<qq> q;

int main() {
    char x;
    cin >> n >> m;
    string s;
    qq zm[26];//x,y qian;dx,dy hou;
    for(int i=0; i<26; i++) {
        zm[i].x=0;
        zm[i].y=0;
        zm[i].dx=0;
        zm[i].dy=0;
    }

    for(int i=1; i<=n; i++) {
        cin >> s;
        for(int j=1; j<=m; j++) {
            x=s[j-1];
            //cout << i << j << " " << x << endl;//
            dt[j][i].x=j;
            dt[j][i].y=i;
            dt[j][i].node=x;
            dt[j][i].k=-1;
            if(x-'A'>=0&&'Z'-x>=0) {
                if(zm[x-'A'].x==0) {
                    zm[x-'A'].x=j;
                    zm[x-'A'].y=i;
                } else {
                    zm[x-'A'].dx=j;
                    zm[x-'A'].dy=i;
                    dt[zm[x-'A'].x][zm[x-'A'].y].dx=j;
                    dt[zm[x-'A'].x][zm[x-'A'].y].dy=i;
                    dt[j][i].dx=zm[x-'A'].x;
                    dt[j][i].dy=zm[x-'A'].y;
                }
            } else if(x=='@') {
                in.x=j;
                in.y=i;
                dt[j][i].k=0;
            }
        }
    }
    //cout << zm['W'-'A'].x << " "<< zm['W'-'A'].y << " " << zm['W'-'A'].dx << " " << zm['W'-'A'].dy;//
    //cout << dt[3][2].dx << dt[3][2].dy;//

//------------------------------------------------------------------------------------a-----------------
    qq now,noww;
    dt[in.x][in.y].k=0;
    now=dt[in.x][in.y];
    q.push(now);
    while(!q.empty()&&tr) {
        now=q.front();
        q.pop();
        if(now.node=='='){
            cout << now.k;
            return 0;
        }

        for(int i=0; i<4; i++) {
            int tx=nx[i]+now.x,ty=ny[i]+now.y;
            if(dt[tx][ty].node>='A'&&dt[tx][ty].node<='Z'&&dt[tx][ty].dx!=0){
                int nx=dt[tx][ty].dx;
                int ny=dt[tx][ty].dy;
                tx=nx;ty=ny;
            }
            if(tx<1||tx>m||ty<1||ty>n||(dt[tx][ty].k!=-1&&(dt[tx][ty].node<'A'||dt[tx][ty].node>'Z'))||dt[tx][ty].node=='#'){
                continue;
            }
            dt[tx][ty].k=now.k+1;
            q.push(dt[tx][ty]);
        }
    }
}
