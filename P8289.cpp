#include<bits/stdc++.h>
using namespace std;
const int N=102;
int n;
string line,base_def="#define",base_udf="#undef";
map<string,string> def;
map<string,bool> bdf;

string getname(int si){
    string res;
    while(si<line.size()&&(line[si]=='_'||('A'<=line[si]&&line[si]<='Z')
    ||('a'<=line[si]&&line[si]<='z')
    ||('0'<=line[si]&&line[si]<='9'))){
        res+=line[si];si++;
    }
    return res;
}

bool check_def(){
    if(line.size()<=7)return 0;
    for(int i=0;i<base_def.size();i++)if(line[i]!=base_def[i])return 0;
    string name,content;
    int ni=9;
    while(line[ni]!=' '){name+=line[ni];ni++;}
    ni++;
    for(;ni<line.size();ni++)content+=line[ni];
    def[name]=content;
    bdf[name]=1;
    return 1;
}

bool check_udf(){
    if(line.size()<=6)return 0;
    for(int i=0;i<base_udf.size();i++)if(line[i]!=base_udf[i])return 0;
    string name,content;
    int ni=8;
    while(line[ni]!=' '){name+=line[ni];ni++;}
    ni++;
    for(;ni<line.size();ni++)content+=line[ni];
    bdf[name]=0;
    return 1;
}
vector<string> l1,l2;
int tot1,tot2;
void puin(vector<string> &li,string x,int &tot){
    if(x.size()==0)return;
    if(tot<li.size())li[++tot-1]=x;
    else{li.push_back(x);tot++;}
}
void zk(){
    tot1=tot2=0;
    int si=0;
    while(si<line.size()){
        string nst=getname(si);
        puin(l1,nst,tot1);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    while(n--){
        getline(cin,line);
        if(check_def())continue;
        if(check_udf())continue;
    }
    
    
    return 0;
}
