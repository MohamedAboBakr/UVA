#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
typedef pair<string,pi> ppi;

map<int ,int >mp;

int st[84010];
string name[84010];

void _add(int p,int l,int r,int i,int j,string nm){
   if(i>r || j<l) return;
   if(i<=l && j>=r){
        st[p]++;
        name[p]=nm;
        return;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
      if(st[p]!=0){
   st[lft]+=st[p];
   st[rgt]+=st[p];
   name[lft]=name[p];
   name[rgt]=name[p];
   st[p]=0;}
   _add(lft,l,mid,i,j,nm);
   _add(rgt,mid+1,r,i,j,nm);
}

string _find(int p,int l,int r,int index){
   if(st[p]>1) return "UNDETERMINED";
   if(l==r){
       if(st[p]==1) return name[p];
       return "UNDETERMINED";
   }
    int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
      if(st[p]!=0){
   st[lft]+=st[p];
   st[rgt]+=st[p];
   name[lft]=name[p];
   name[rgt]=name[p];
   st[p]=0;}
   if(index<=mid) return _find(lft,l,mid,index);
   return  _find(rgt,mid+1,r,index);
}


int main(){

    int t;scanf("%d",&t);
    while(t--){
          memset(st,0,sizeof(st));
          fill(name,name+84010,NULL);
          mp.clear();
          set<int> sett;
         int n,q,l,r;
         scanf("%d",&n);
         vector<ppi>vec;
         string s;
         for(int i=0;i<n;i++){
              cin >> s>> l>> r;
              vec.push_back(ppi(s,pi(l,r)));
              sett.insert(l); sett.insert(r);
         }
         scanf("%d",&q);int  qq=q;
         vector<int> qrs;
         while(q--){
            int p; scanf("%d",&p);
             sett.insert(p);
             qrs.push_back(p);
         }
         set<int>::iterator it=sett.begin();
         int c=0;
         for(;it!=sett.end();it++){
              mp[*it]=c++;
         }

         for(int i=0;i<n;i++){
             _add(1,0,sett.size()-1,mp[vec[i].second.first],mp[vec[i].second.second],vec[i].first);
         }
         for(int i=0;i<qq;i++){
             string ans = _find(1,0,sett.size()-1,mp[qrs[i]]);
             cout<<ans<<"\n";
         }
         if(t!=0) printf("\n");
    }
    return 0;
}
