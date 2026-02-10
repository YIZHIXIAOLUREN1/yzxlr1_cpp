#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;

map <string ,int> tinfo,peerid;
struct torrent{
    string hash;

} tor[N];

struct peerr{
    string id,ip,port;
    int uploaded,downloaded;
} peer[N];

void solve(string &s){
    if(s=="add"){
        cin>>s;
        
    }else if(s=="announce"){

    }else if(s=="scrape"){

    }else if(s=="del"){

    }else if(s=="run"){

    }else if(s=="report"){

    }else{
        cout<<"debug:"<<s;
        exit(0);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    while(cin>>s){
        solve(s);
    }
}
