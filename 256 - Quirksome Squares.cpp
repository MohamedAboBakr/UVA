#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
typedef pair<int,pi> ppi;

map<int, vector< int > > mp;

int main(){
 for(int i=0;i<10;i++){
     for(int j=0;j<10;j++){
         if((i+j)*(i+j) == i*10+j) mp[2].push_back(i*10+j);
     }
 }
 for(int i=0;i<100;i++){
     for(int j=0;j<100;j++){
         if((i+j)*(i+j) == i*100+j) mp[4].push_back(i*100+j);
     }
 }
 for(int i=0;i<1000;i++){
     for(int j=0;j<1000;j++){
         if((i+j)*(i+j) == i*1000+j) mp[6].push_back(i*1000+j);
     }
 }
  for(int i=0;i<10000;i++){
     for(int j=0;j<10000;j++){
         if((i+j)*(i+j) == i*10000+j) mp[8].push_back(i*10000+j);
     }
 }

 int n;
 while(scanf("%d",&n)==1){
     for(int i=0;i<mp[n].size();i++){
          if(n==2)printf("%0.2d\n",mp[n][i]);
          else if(n==4) printf("%0.4d\n",mp[n][i]);
          else if(n==6) printf("%0.6d\n",mp[n][i]);
          else printf("%0.8d\n",mp[n][i]);
     }
 }
 return 0;
}
