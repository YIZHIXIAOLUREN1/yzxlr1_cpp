#include<bits/stdc++.h>
using namespace std;

void Solve(){
    FILE *fp1;
    char ch[80];
    int i,j;
    fp1=fopen("data1.dat","w");
    
    for(i=1;i<=4;i++){
        fgets(ch,80,stdin);
        ch[strlen(ch)-1]='\0';
        j=0;
        while(ch[j]!='\0'){
            fputc(ch[j],fp1);
            j++;
        }
        fputc('\n',fp1);
    }
    fclose(fp1);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    while(T--){
        Solve();
    }
}