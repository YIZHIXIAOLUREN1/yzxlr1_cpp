#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
vector<int> a[N],b[N];
int m;
list<int> ans;
void hb(int x,int y){
    if(!ans.size()){
        ans.push_front(y);
        ans.push_front(x);
    }else{
        auto pos=find(ans.begin(),ans.end(),x);
        ans.insert(pos,y);
    }
    printf("h%d %d\n",x,y);//
    for(int i=0;i<b[y].size();i++){
        b[x].push_back(b[y][i]);
        while(b[x][b[x].size()-1]==0&&b[x][b[x].size()-2]==1)
            b[x].pop_back(),b[x].pop_back();
    }
    b[y].clear();
}
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    string s;
    for(int i=1;i<=n;i++){
        cin >> s;
        for(int j=0;j<s.size();j++){
            a[i].push_back((s[j]=='(')?1:0);
            while(a[i][a[i].size()-1]==0&&a[i][a[i].size()-2]==1)
            a[i].pop_back(),a[i].pop_back();
        }
        a[i].swap(b[i]);
        a[i].clear();
        a[i].shrink_to_fit();
    }
    m=n;
    bool flag=1;
    while(m>1&&flag){
    	printf("%d:%d\n",m,flag);//
    	for(int i=1;i<=n;i++){
    		for(int j=0;j<b[i].size();j++)printf("%d ",b[i][j]);
    		puts("");
    	}
        if(b[m].size()==0){
            m--;
            continue;
        }
        flag=0;
        int tm=b[m].size()-1;
        for(int i=m-1;i>=1;i--){
            int tn=b[i].size()-1;
            if(tn==-1)continue;
            if(b[m][0]==0&&b[i][tn]==1){hb(i,m);flag=1;break;}
            if(b[m][tm]==1&&b[i][0]==0){hb(m,i);flag=1;break;}
        }
    }
    //if(m>1)puts("-1");
    for(auto& i:ans)cout<<i<<" ";
}