#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll> pi;
map<ll,set< pi > > diff;

int main(){

  int n; scanf("%d",&n);
  while(n){
    ll a;
    diff.clear();
    vector<ll>v;
    for(int i=0;i<n;i++){
        scanf("%lld",&a);
        v.push_back(a);
    }

    for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             diff[v[i]-v[j]].insert(pi(v[i],v[j]));
             diff[v[j]-v[i]].insert(pi(v[j],v[i]));
         }
    }

    ll mx = -536870918;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
             if(diff.find(v[i]+v[j])!=diff.end()){
                    set<pi>::reverse_iterator it=diff[v[i]+v[j]].rbegin();
                    for(;it!=diff[v[i]+v[j]].rend();it++){
                        if(v[i]!=it->first&&v[j]!=it->first&&v[i]!=it->second&&v[j]!=it->second){
                            mx = max(mx,it->first);
                            break;
                        }
                    }

             }
        }
    }
    if(mx == -536870918) printf("no solution\n");
    else printf("%lld\n",mx);
    scanf("%d",&n);
  }
  return 0;
}
