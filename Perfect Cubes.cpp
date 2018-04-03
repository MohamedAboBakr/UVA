#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){

  map<int,int>mp;
  for(int i=2;i<=200;i++){
     mp[i*i*i]=i;
  }
  for(int a=1;a<=200;a++){
      for(int b=2;3*b*b*b<=a*a*a;b++){
           for(int c=b;2*c*c*c<=a*a*a-b*b*b;c++){
               int d=a*a*a-b*b*b-c*c*c;
               if(mp.find(d)!=mp.end()){
                  printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,mp[d]);
               }
           }
      }
  }
  return 0;
}
