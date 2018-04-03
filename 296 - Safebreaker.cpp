#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll>pi;
typedef pair<string,pi> ppi;

set<string> codes;

void _generate(){
   codes.clear();
   char a,b,c,d;
   for(int i=0;i<10;i++){
       a=(char)('0'+i);
       for(int j=0;j<10;j++){
          b=(char)('0'+j);
          for(int k=0;k<10;k++){
             c=(char)('0'+k);
             for(int p=0;p<10;p++){
                d=(char)('0'+p);
                string s = ""; s+=a; s+=b;s+=c;s+=d;
                codes.insert(s);
             }
          }
       }
   }
}

bool check1(int guess , string currCode , int x){
   int counter=0,div=1000;
   for(int i=0;i<4;i++){
      if(currCode[i]-'0'==(guess/div)%10) counter++;
      div/=10;
   }
   return counter==x;
}

void filter1(int guess,int x){
   vector<string> toErase;

   set<string>::iterator it=codes.begin();
   for(;it!=codes.end();it++){
        if(!check1(guess,*it,x)) toErase.push_back(*it);
   }
   for(int i=0;i<toErase.size();i++){
       codes.erase(toErase[i]);
   }
}

bool check2(int guess,string currCode, int y){
   int digits[10]={0};
   int div=1000,counter=0;
   for(int i=0;i<4;i++) digits[currCode[i]-'0']++;
   for(int i=0;i<4;i++){
      if(digits[(guess/div)%10]>0){
         counter++;
         digits[(guess/div)%10]--;
      }
      div/=10;
   }
   return counter==y;
}

void filter2(int guess,int y){
   vector<string> toErase;
   set<string>::iterator it=codes.begin();
   for(;it!=codes.end();it++){
        if(!check2(guess,*it,y)) toErase.push_back(*it);
   }
   for(int i=0;i<toErase.size();i++){
       codes.erase(toErase[i]);
   }
}

int main(){

   int t;scanf("%d",&t);
   while(t--){
       _generate();
       int n;
       scanf("%d",&n);
       int guess,x,y;
       while(n--){
          scanf("%d %d/%d",&guess,&x,&y);
          filter1(guess,x);
          filter2(guess,x+y);
       }
       set<string>::iterator it=codes.begin();
       if(codes.size()==0)printf("impossible\n");
       else if(codes.size()==1)cout<<*it<<"\n";
       else printf("indeterminate\n");
   }
   return 0;
}
