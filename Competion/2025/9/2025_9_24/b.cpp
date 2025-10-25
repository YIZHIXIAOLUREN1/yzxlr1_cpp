#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n,m;
string s;
vector<int> h;

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        h.clear();
        cin>>n>>m;
        cin>>s;

        for(int i=1,b;i<=m;i++){
            cin>>b;
            h.push_back(b);
        }

        int lj=1,j=0;
        while(j<=m-1&&h[j]<=lj)j++;
        if(s[0]=='A'){
            if(j<=m-1&&h[j]==lj+1){
                lj++;j++;
            }else{
                lj++;
                h.push_back(lj);
            }
        }else{
            while(j<=m-1&&h[j]==lj+1){
                j++,lj++;
            }
            lj++;
            while(j<=m-1&&h[j]<=lj)j++;
            h.push_back(lj);
        }
        //printf("1:%d %d\n",j,lj);//
        for(int i=2;i<=n;i++){
            if(s[i-2]=='A'){
                if(s[i-1]=='A'){
                    if(j<=m-1&&h[j]==lj+1){
                        lj++;j++;
                    }else{
                        lj++;
                        h.push_back(lj);
                    }
                }else{
                    while(j<=m-1&&h[j]==lj+1){
                        j++,lj++;
                    }
                    lj++;
                    while(j<=m-1&&h[j]<=lj)j++;
                    h.push_back(lj);
                }
            }else{
            	while(j<=m-1&&h[j]==lj+1){
                    j++,lj++;
                }
                lj++;
                while(j<=m-1&&h[j]<=lj)j++;
                if(s[i-1]=='A'){
                    if(h[j]==lj+1){
                        lj++;j++;
                    }else{
                        lj++;
                        h.push_back(lj);
                    }
                }else{
                    while(j<=m-1&&h[j]==lj+1){
                        j++,lj++;
                    }
                    lj++;
                    while(j<=m-1&&h[j]<=lj)j++;
                    h.push_back(lj);
                }
            }
            //printf("%d:%d %d\n",i,j,lj);//
        }
        sort(h.begin(),h.end());
        cout<<h.size()<<"\n";
        for(int i=0;i<h.size();i++)cout<<h[i]<<" \n"[i==h.size()-1];
    }
}
