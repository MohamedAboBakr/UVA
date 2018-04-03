#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int n,m;
vector<string> dic;
string rule;

void solve(int index, string ans){
   if(index == rule.size()){
   	  cout << ans << "\n";
   	  return;
   }

   if(rule[index]=='#'){
       for(int i=0;i<dic.size();i++){
          solve(index+1, ans+dic[i]);
       }
   }
   else{
   	  for(int i=0;i<10;i++){
          string ss(1, '0'+i);
          solve(index+1, ans+ss);
   	  }
   }
}

int main(){
  string s;
  while( scanf("%d",&n) ==1){
  	printf("--\n");
    for(int i=0;i<n;i++){
       cin >> s;
       dic.push_back(s);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
      cin >> rule;
      solve(0,"");
    }
    dic.clear();
}
	return 0;
}