#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
typedef pair<string,pi> ppi;

int main()
{
    int t;scanf("%d",&t);
    while(t--){
         int n,q,l,r;
         scanf("%d",&n);
         vector<ppi>vec;
         string s;
         for(int i=0;i<n;i++){
              cin >> s>> l>> r;
              vec.push_back(ppi(s,pi(l,r)));
         }
         scanf("%d",&q);
         while(q--){
            string ans="UNDETERMINED";
            int p,c=0; scanf("%d",&p);
            for(int i=0;i<n;i++){
                 if(p>=vec[i].second.first&&p<=vec[i].second.second){
                     c++;
                     ans = vec[i].first;
                 }
            }
            if(c==1) cout<<ans<<"\n";
            else cout <<"UNDETERMINED\n";
         }
         if(t!=0) printf("\n");
    }
    return 0;
}
