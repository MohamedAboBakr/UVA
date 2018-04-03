#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
typedef pair<int,pi> ppi;

int main(){

  string allperm[]={"BCG","BGC","CBG","CGB","GBC","GCB"};
  int b[4],g[4],c[4],index;

  while(scanf("%d %d %d %d %d %d %d %d %d",&b[1],&g[1],&c[1],&b[2],&g[2],&c[2],&b[3],&g[3],&c[3])==9){
        ll mn = 3e9;
        int curr=b[2]+b[3]+c[1]+c[3]+g[1]+g[2];
        if(curr<mn){
             mn=curr;
             index=0;
        }
        curr=b[2]+b[3]+g[1]+g[3]+c[1]+c[2];
        if(curr<mn){
             mn=curr;
             index=1;
        }
        curr=c[2]+c[3]+b[1]+b[3]+g[1]+g[2];
        if(curr<mn){
             mn=curr;
             index=2;
        }
        curr=c[2]+c[3]+g[1]+g[3]+b[1]+b[2];
        if(curr<mn){
             mn=curr;
             index=3;
        }
        curr=g[2]+g[3]+b[1]+b[3]+c[1]+c[2];
        if(curr<mn){
             mn=curr;
             index=4;
        }
        curr=g[2]+g[3]+c[1]+c[3]+b[1]+b[2];
        if(curr<mn){
             mn=curr;
             index=5;
        }
        cout << allperm[index]<<" "<<mn<<"\n";
  }
  return 0;
}
