#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int L,res,ans;
int q[N],top,tot,fd;
string qq[N];
map<string,int> ss;
string s;
void Solve(){
    cin>>L>>s;
    if(s=="O(1)")ans=0;
    else{
        ans=0;
        for(int i=4;i<s.size()-1;i++){
            ans*=10;ans+=s[i]-'0';
        }
    }
    res=top=tot=fd=0;
    ss.clear();
    while(L--){
        if(res==-1){
            
            //getline(cin,s);
            cin>>s;
            if(s=="F")cin>>s>>s>>s;
            ///cout<<s<<"\n";//
            continue;
        }
        char ch;
        cin>>ch;
        if(ch=='F'){
            cin>>s;
            if(ss[s]==1){
            	//cout<<"A"<<L;//
                res=-1;
                cin>>s;
                cin>>s;
                continue;
            }
            ss[s]=1;
            q[++tot]=0;
			qq[tot]=s;
			
			int l=0,r=0;
            cin>>s;
            if(s=="n")l=-1;
            else{
                for(int i=0;i<s.size();i++){
                    l*=10;l+=s[i]-'0';
                }
            }
            cin>>s;
            if(s=="n")r=-1;
            else{
                for(int i=0;i<s.size();i++){
                    r*=10;r+=s[i]-'0';
                }
            }
			
			if((l==-1&&r!=-1)||(l!=-1&&r!=-1&&l>r)){
				q[tot]=-1;
				fd++;
				continue;
			}
            if(l!=-1&&r==-1&&!fd){
            	top++;
            	q[tot]=1;
            }
        }else{
            if(tot){
            	ss[qq[tot]]=0;
            	if(q[tot]==1)top--;
            	else if(q[tot]==-1)fd--;
            	tot--;
            }
            else{
            	//cout<<"C";//
                res=-1;
                continue;
            }
        }
        res=max(res,top);
    }
    //printf("%d:%d:%d:",res,tot,top);//
    if(res==-1||tot)cout<<"ERR\n";
    else if(res==ans)cout<<"Yes\n";
    else cout<<"No\n";
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1,TT;
    cin>>T;
    TT=T;
    while(T--){
    	//cout<<TT-T<<":";//
        Solve();
    }
}
