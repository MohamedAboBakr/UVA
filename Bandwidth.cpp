#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map<int, vector <vector<int> > > perms;
map<char,vector<char > > graph;

void _generate(int index ,int n , int arr[8] , vector<int> stk){
       if(index==n){
           vector<int> v;
           for(int i=0;i<n;i++){
              v.push_back(stk[i]);
           }
           perms[n].push_back(v);
           return;
       }
       for(int i=0;i<n;i++){
           if(arr[i]==0){
              arr[i]=1;
              stk.push_back(i);
              _generate(index+1,n,arr,stk);
              arr[i]=0;
              stk.erase(stk.begin()+stk.size()-1);
           }
       }
}

int bandwidth(vector<char> nodes){
      map<char,int> mpp;
      for(int i=0;i<nodes.size();i++){
          mpp[nodes[i]]=i;
      }
      int mx=0;
      map<char,vector<char > >::iterator it = graph.begin();
      for(;it!=graph.end();it++){
            for(int i=0;i<it->second.size();i++){
                 mx=max(mx,abs(mpp[it->first]-mpp[it->second[i]]));
            }
      }
      return mx;
}

pair< vector<char> , int> solve(int n,vector<char> nodes){
         int mn=10;
         vector<char> ans;
         for(int i=0;i<perms[n].size();i++){
             vector<char> v;
             for(int j=0;j<n;j++){
                  v.push_back(nodes[perms[n][i][j]]);
             }
             int bw = bandwidth(v);
             if(bw<mn){
                 mn=bw;
                 ans=v;
             }
         }
         return pair< vector<char> , int>(ans,mn);
}

int main(){

   for(int i=1;i<=8;i++){
       int arr[8]={0}; vector<int>v;
       _generate(0,i,arr,v);
   }

   string s; cin>>s;
   while(s!="#"){
      graph.clear();
      set<char> nodes;
      char node;
      for(int i=0;i<s.size();i++){
           node=s[i];i+=2;
           nodes.insert(node);
           while(i<s.size()&&s[i]!=';'){
              nodes.insert(s[i]);
              graph[node].push_back(s[i]);
              i++;
           }
      }
      vector<char> nodess;
      set<char>::iterator it=nodes.begin();
      for(;it!=nodes.end();it++){
         nodess.push_back(*it);
      }
      pair< vector <char> , int > ans = solve(nodess.size(),nodess);
      printf("%c",ans.first[0]);
      for(int i=1;i<ans.first.size();i++){
          printf(" %c",ans.first[i]);
      }
      printf(" -> %d\n",ans.second);
      cin >> s;
   }
   return 0;
}
