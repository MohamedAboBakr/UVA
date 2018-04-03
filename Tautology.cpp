#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


bool eval(string ss,int p,int q,int r,int s,int t){
     stack<int> stk;
     for(int i=ss.size()-1;i>=0;i--){
          if(ss[i]=='p') stk.push(p);
          else if(ss[i]=='q') stk.push(q);
          else if(ss[i]=='r') stk.push(r);
          else if(ss[i]=='s') stk.push(s);
          else if(ss[i]=='t') stk.push(t);
          else if(ss[i]=='N'){
              int lst=stk.top();stk.pop();
              stk.push(!lst);
          }
          else if(ss[i]=='K'){
              int n1=stk.top();stk.pop();
              int n2=stk.top();stk.pop();
              stk.push(n1&n2);
          }
          else if(ss[i]=='A'){
              int n1=stk.top();stk.pop();
              int n2=stk.top();stk.pop();
              stk.push(n1|n2);
          }
          else if(ss[i]=='E'){
              int n1=stk.top();stk.pop();
              int n2=stk.top();stk.pop();
              stk.push(n1==n2);
          }
          else if(ss[i]=='C'){
              int n1=stk.top();stk.pop();
              int n2=stk.top();stk.pop();
              stk.push(!(n1&!n2));
          }
     }
     int ans=stk.top();
     return (ans==1);
}

bool solve(string ss){
   int p,q,r,s,t;
   for(int i=0;i<32;i++){
      p=(i|(1<<0))==i;q=(i|(1<<1))==i;r=(i|(1<<2))==i;s=(i|(1<<3))==i;t=(i|(1<<4))==i;
      if(!eval(ss,p,q,r,s,t)) return false;
   }
   return true;
}
int main(){
  string s; cin>>s;
  while(s!="0"){
    if(solve(s)) printf("tautology\n");
    else printf("not\n");
    cin>>s;
  }
  return 0;
}
