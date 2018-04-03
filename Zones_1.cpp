#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int tw[20],c[50],sct[50];
int mx=0,ans;

int cnt(int a){  // count the number of 1's bits in binary representation of a number
    int n=0;
    while(a){
        n++;
        a-=(a&-a);  // a&-a get the rightmost 1 bit in a
    }
    return n;
}

vector<int> perms(int n,int m){  // get all permutations to choose m items from n
        vector<int> perm;
        for(int i=1;i<(1<<n);i++){
             if(cnt(i)==m) perm.push_back(i);
        }
        return perm;
}

void solve(int perm,int con,int n){
   int sum=0;
   for(int i=0;i<n;i++){
     if(perm&(1<<i)) sum+=tw[i];
   }
   for(int i=0;i<con;i++){
     int intersect=perm&c[i];
     if(intersect>1) sum-=(cnt(intersect)-1)*sct[i];
   }
   if(sum>mx){
     mx=sum;
     ans=perm;
   }
}

void print(int n){
    for(int i=0;i<n;i++){
        if(ans&(1<<i))printf(" %d",i+1);
    }
    printf("\n");
}

int main(){
  int n,m,con,num,a,tst=1; scanf("%d%d",&n,&m);
  while(n){
    mx=0;
    memset(c,0,sizeof(c));
    vector<int>perm=perms(n,m);
    for(int i=0;i<n;i++){
        scanf("%d",&tw[i]);
    }
    scanf("%d",&con);
    for(int i=0;i<con;i++){
        scanf("%d",&num);
        for(int j=0;j<num;j++){
             scanf("%d",&a);
             c[i]|=(1<<(a-1));
        }
        scanf("%d",&sct[i]);
    }
    for(int i=0;i<perm.size();i++){
         solve(perm[i],con,n);
    }
     printf("Case Number  %d\n",tst++);
     printf("Number of Customers: %d\n",mx);
     printf("Locations recommended:");
     print(n);
     printf("\n");
     scanf("%d%d",&n,&m);
  }
  return 0;
}
