#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main(){

  int t; scanf("%d",&t);
  while(t--){
  int k; scanf("%d",&k);
        int flag=0;
        for(ll a=0;a*a*3<=k;a++){
            for(ll b=a;a*a+b*b*2<=k;b++){
                    ll c = k-(a*a+b*b);
                    if((ll)sqrt(c)*(ll)sqrt(c)==c){
                         printf("%lld %lld %lld\n",a,b,(ll)sqrt(c));
                         flag=1;
                         break;
                    }
            }
            if(flag==1) break;
        }
        if(!flag) printf("-1\n");
  }
}
