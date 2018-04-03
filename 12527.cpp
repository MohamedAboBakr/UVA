#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int n,m,k;

int check(int a){
   if(a%7==0) return 1;
   while(a){
      if(a%10 == 7) return 1;
      a /= 10;
   }
   return 0;
}

int solve(){
  int i=1,p=1,ud=1,cl=0;
  while(i<=5000000){
    if(p==m && check(i)){
       cl++;
       if(cl == k) return i;
    }
    if(p == 1) ud =1;
    if(p == n) ud =-1;
    p += ud;
    i++;
  }
  return -1;
}
int main(){

  scanf("%d%d%d",&n,&m,&k);
  while(n!=0){
    int ans = solve();
    printf("%d\n",ans);
    scanf("%d%d%d",&n,&m,&k);
  }
  return 0;
}
