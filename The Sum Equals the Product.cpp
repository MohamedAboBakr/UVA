#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

/*
map<ll , set< vector<ll> > > mp;
int main(){

  double n,m; scanf("%lf%lf",&n,&m);
  ll nn,mm ; nn= n*100; mm=m*100;
        for(ll a=1;a*3<=25600;a++){
            for(ll b=1;a+b*2<=25600;b++){
                 if(a*b>10000){
                      ll c = 10000*(a+b)/(a*b-10000);
                      int f = (10000*(a+b))%(a*b-10000);
                      if(f==0&&(a+b+c)>=nn&&(a+b+c)<=mm){
                             vector<ll> v; v.push_back(a);v.push_back(b);v.push_back(c);
                             sort(v.begin(),v.end());
                             mp[a+b+c].insert(v);
                      }

                 }
            }
        }

   map<ll , set< vector<ll> > >::iterator it1 = mp.begin();
   for(;it1!= mp.end();it1++){
        set< vector<ll> >::iterator it2 =it1->second.begin();
        for(;it2!=it1->second.end();it2++){
            vector<ll> v = *it2;
printf("%0.2f = %0.2f + %0.2f + %0.2f = %0.2f * %0.2f * %0.2f\n", (double)(it1->first)/100, (double)v[0]/100,(double)(v[1])/100,(double)(v[2])/100,(double)(v[0])/100,(double)(v[1])/100,(double)(v[2])/100);        }
   }
  return 0;
}

*/



map<ll , set< vector<ll> > > mp;
int main(){
  double n,m; scanf("%lf%lf",&n,&m);
  ll nn,mm ; nn= n*1000000; mm=m*1000000;
        for(ll a=1;a<=16000;a++){
            for(ll b=1;b*b<=256000000/a;b++){
                 if(a*b>10000){
                      ll c = 10000*(a+b)/(a*b-10000);
                      int f = (10000*(a+b))%(a*b-10000);
                      if(f==0&&(a*b*c)>=nn&&(a*b*c)<=mm){
                             vector<ll> v; v.push_back(a);v.push_back(b);v.push_back(c);
                             sort(v.begin(),v.end());
                             mp[a*b*c].insert(v);
                      }

                 }
            }
        }

 map<ll , set< vector<ll> > >::iterator it1 = mp.begin();
   for(;it1!= mp.end();it1++){
        set< vector<ll> >::iterator it2 =it1->second.begin();
        for(;it2!=it1->second.end();it2++){
            vector<ll> v = *it2;
printf("%0.2f = %0.2f + %0.2f + %0.2f = %0.2f * %0.2f * %0.2f\n", (double)(it1->first)/1000000, (double)v[0]/100,(double)(v[1])/100,(double)(v[2])/100,(double)(v[0])/100,(double)(v[1])/100,(double)(v[2])/100);        }
   }
  return 0;
}




