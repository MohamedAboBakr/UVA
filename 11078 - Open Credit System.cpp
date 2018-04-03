#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll>pi;
typedef pair<string,pi> ppi;

int main(){
   int t;scanf("%d",&t);
   while(t--){
       int n;
       scanf("%d",&n);
       vector<int>vec;
       int mn=200000,mx=-200000,mxx=-200000,a;
       for(int i=0;i<n;i++){
          scanf("%d",&a); vec.push_back(a);
       }
       for(int i=n-2;i>=0;i--){
           int diff = vec[i]-vec[i+1];
           mn = min(diff,diff+mn);
           mx = max(diff,diff+mx);
           mxx = max(mx,mxx);
       }
       printf("%d\n",mxx);
   }
   return 0;
}
