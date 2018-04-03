#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map< int, vector < vector<int> > > call_system;

int gett(int tm, int to){
   for(int i=0; i< call_system[to].size(); i++){
       if(tm>= call_system[to][i][0] && tm<=call_system[to][i][1]) {
       	  if(call_system[to][i][2] == to) return 9999;
       	  return call_system[to][i][2];
       }
   }
   return to;
}


int is_in(int n, vector<int> vec){
    for(int i=0; i<vec.size();i++){
       if(vec[i]==n) return 1;
    }
    return 0;
}

int solve(int tm, int to){
      vector<int> vec;
      int ans = gett(tm,to);
      if(ans==to) return to;
      vec.push_back(to);
      while(true){
          int anss = gett(tm,ans);
          if(anss==ans) return ans;
          if(is_in(anss,vec)) return 9999;
          vec.push_back(anss);
          ans = anss;
      }
      return -1;
}

int main(){
	
	printf("CALL FORWARDING OUTPUT\n");
	int t; scanf("%d",&t);
	int tst=1;
	while(t--){
		printf("SYSTEM %d\n",tst);
    int from,strt,dur,to; 
    int call_tm,call_to;
    scanf("%d",&from);
    while(from != 0){
       scanf("%d%d%d",&strt, &dur, &to);
       vector<int> vec;
       vec.push_back(strt);vec.push_back(strt+dur);vec.push_back(to);
       call_system[from].push_back(vec);
       scanf("%d",&from);
    }
    
    scanf("%d",&call_tm);
    while(call_tm != 9000){
       scanf("%d",&call_to);
       int ans = solve(call_tm,call_to);
       printf("AT %04d CALL TO %04d RINGS %04d\n",call_tm, call_to, ans);
       scanf("%d",&call_tm);
    }
    call_system.clear();
    tst++;
	}
	printf("END OF OUTPUT\n");
 	return 0;
}