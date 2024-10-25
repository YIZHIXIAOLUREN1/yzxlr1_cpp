#include<bits/stdc++.h>
using namespace std;
const int N=102;
int n;
string line,base_def="#define",base_udf="#undef";
map<string,pair<string,bool>> def;
map<string,int> iszk;

string cts(int si){string res;res+=line[si];return res;}
bool check_name(string &x){
    bool res=1;
    for(int si=0;si<x.size();si++){
        if(x[si]=='_'||('A'<=x[si]&&x[si]<='Z')
        ||('a'<=x[si]&&x[si]<='z')
        ||('0'<=x[si]&&x[si]<='9'))continue;
        res=0;break;
    }
    return res;
}
bool check_una(int si,string &s){
    return !(s[si]=='_'||('A'<=s[si]&&s[si]<='Z')
    ||('a'<=s[si]&&s[si]<='z')
    ||('0'<=s[si]&&s[si]<='9'));
}
string getname(int &si,string &s){
    string res;
    while(si<s.size()&&(s[si]=='_'||('A'<=s[si]&&s[si]<='Z')
    ||('a'<=s[si]&&s[si]<='z')
    ||('0'<=s[si]&&s[si]<='9'))){
        res+=s[si];si++;
    }
    return res;
}
bool check_def(){
    if(line.size()<=7)return 0;
    for(int i=0;i<base_def.size();i++)if(line[i]!=base_def[i])return 0;
    string name,content;
    int ni=8;
    while(line[ni]!=' '){name+=line[ni];ni++;}
    ni++;
    for(;ni<line.size();ni++)content+=line[ni];
    def[name]={content,1};
    iszk[name]=1000;
    return 1;
}
bool check_udf(){
    if(line.size()<=6)return 0;
    for(int i=0;i<base_udf.size();i++)if(line[i]!=base_udf[i])return 0;
    string name,content;
    int ni=7;
    while(line[ni]!=' '){name+=line[ni];ni++;}
    ni++;
    for(;ni<line.size();ni++)content+=line[ni];
    def[name]={def[name].first,0};
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
        string nst=getname(si,line);
        puin(l1,nst,tot1);
        while(si<line.size()&&check_una(si,line)){
            puin(l1,cts(si),tot1);
            si++;
        }
    }
    for(int i=tot1-1;i>=0;i--)puin(l2,l1[i],tot2);
    while(tot2){
    	for(int i=tot2-1;i>=0;i--)cout<<l2[i]<<endl;//
        cout<<endl;//
        string now=l2[tot2-1];
        if(!check_name(now)){cout<<now<<endl<<endl;tot2--;continue;}
        bool isz=0;
        for(auto s1:def){
            string cname=s1.first,ccontent=s1.second.first;
            if(s1.second.second==0)continue;
            if(now==cname){
                if(iszk[now]<tot2)continue;
                cout<<now<<":"<<ccontent<<endl;
                iszk[now]=tot2-1;
                now=ccontent;
                cout<<now<<endl;
                int ni=0;
                tot1=0;
                while(ni<now.size()){
                    string nst=getname(ni,now);
                    cout<<nst<<endl;
                    puin(l1,nst,tot1);
                    while(ni<now.size()&&check_una(ni,now)){
                        puin(l1,cts(ni),tot1);
                        ni++;
                    }
                }
                cout<<l1[0]<<endl<<endl;
                tot2--;
                for(int i=tot1-1;i>=0;i--)puin(l2,l1[i],tot2);
                tot1=0;
                isz=1;
                break;
            }
        }
        if(!isz){cout<<now<<endl<<endl;tot2--;}
    }
}
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    getline(cin,line);
    while(n--){
        getline(cin,line);
        if(check_def()){cout<<"\n";continue;}
        if(check_udf()){cout<<"\n";continue;}
        zk();
        for(auto st:iszk)st.second=1000;
        cout<<"\n";
    }
    for(auto st:def)cout<<st.first<<" "<<st.second.first<<" "<<st.second.second<<"\n";
    
    return 0;
}
