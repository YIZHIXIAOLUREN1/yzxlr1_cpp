#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=107;
int n,m;
vector<pair<int,string>> c;
struct hbb{
    string hs,st,ed,th,tm;
    bool operator==(const hbb& b){
        if(b.st==st&&b.ed==ed&&b.th==th&&b.tm==tm){
            int mx=0,my=0;
            for(auto x:c){
                if(x.second==hs)mx=x.first;
            }
            for(auto x:c){
                if(x.second==b.hs)my=x.first;
            }
            if(mx==my&&mx&&my)return 1;
        }
        return 0;
    }
} ns;
vector<hbb> hb;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	int c1;
    	cin>>c1;
        while(c1--){
        	string cc;
        	cin>>cc;
        	c.push_back({i,cc});
        }
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        ns.hs=s.substr(0,2);
        ns.st=s.substr(7,3);
        ns.ed=s.substr(11,3);
        ns.th=s.substr(15,2);
        ns.tm=s.substr(18,2);
        bool fl=0;
        for(auto b:hb){
            if(b==ns){fl=1;break;}
        }
        if(!fl)hb.push_back(ns);
    }
    cout<<hb.size();
}
