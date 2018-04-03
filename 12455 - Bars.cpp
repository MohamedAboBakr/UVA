#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
typedef pair<int,pi> ppi;

int main(){
  int t; scanf("%d",&t);
  while(t--){
      int n,p,pp; scanf("%d%d",&n,&p);
      vector<int> v;
      for(int i=0;i<p;i++){
           scanf("%d",&pp); v.push_back(pp);
      }
      int f=0;
      for(int bit=0;bit<(1<<p);bit++){
           int tmp = 1,c=0,sm=0;
           while(tmp<=bit){
                if(bit&tmp){
                        //printf("%d %d **\n",bit,tmp);
                        sm+=v[c];
                }
                c++;
                tmp=1<<c;
           }
           if(sm==n) f=1;
      }
      if(f==1)printf("YES\n");
      else printf("NO\n");
  }
  return 0;
}
