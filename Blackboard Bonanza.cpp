#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int maxx(string s1,string s2){
     int ln1=s1.size(),ln2=s2.size();
     int mx1=0,mx2=0;
     for(int i=0;i<ln2;i++){
         int sm=0;
         for(int j=0;j<min(ln1,ln2-i);j++){
               if(s1[j]==s2[i+j]) sm++;
         }
         mx1=max(mx1,sm);
     }

     for(int i=0;i<ln1;i++){
         int sm=0;
         for(int j=0;j<min(ln2,ln1-i);j++){
               if(s2[j]==s1[i+j]) sm++;
         }
         mx2=max(mx2,sm);
     }
     return max(mx1,mx2);
}


int main(){
  int t,n;scanf("%d",&t);
  while(t--){
     scanf("%d",&n);
     vector<string> v;
     for(int i=0;i<n;i++){
        string s; cin>>s;
        v.push_back(s);
     }
     int ans=0;
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             ans = max(ans,maxx(v[i],v[j]));
         }
     }
     printf("%d\n",ans);
  }
  return 0;
}
