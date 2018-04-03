#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
  ll n,a,b,c;
  scanf("%lld",&n);
  while(n--){
     scanf("%lld%lld%lld",&a,&b,&c);
     int f=0;
     for(ll x=-100;x<=100;x++){
        if(x>b) break;
        for(ll y=x+1;y<=100;y++){
            if(x*y>b) break;
            for(ll z=y+1;z<=100;z++){
                if((x*y*z)>b) break;
                if((x+y+z==a)&&(x*y*z==b)&&(x*x+y*y+z*z==c)){
                     f=1;
                     printf("%lld %lld %lld\n",x,y,z);
                }
            }
        }
     }
     if(!f)printf("No solution.\n");
  }
 return 0;
}
