#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int n,m;
int mx=0;
vector<int> taps;
vector<int> ans;

void solve(int index, vector<int> taken, int score){
     
     if(score > mx){
     	 mx= score;
     	 ans.clear();
     	 for(int j=0;j<taken.size();j++){
         ans.push_back(taken[j]);
     	 }
     }

     for(int i=index; i<m ; i++){
        if(taps[i]+score <= n){
        	 taken.push_back(taps[i]);
        	 solve(i+1,taken,score+taps[i]);
        	 taken.erase(taken.begin()+taken.size()-1);
        }
     }
}

int main(){
	
	while(scanf("%d",&n)==1){
       scanf("%d",&m);
       int t;
       for(int i=0;i<m;i++){
           scanf("%d",&t);
           taps.push_back(t);  
       }
    vector<int> taken;
    solve(0,taken,0);
    for(int i=0;i<ans.size();i++){
        printf("%d ",ans[i]);
    }
    printf("sum:%d\n",mx);
    taps.clear();
    ans.clear();
    mx=0;
	}
	return 0;
}