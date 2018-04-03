#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


map<ll , set< vector<ll> > > mp;
int main(){

  ll nn,mm ; nn=1; mm=2000;
        for(ll a=1;a*4<=2000;a++){
            for(ll b=a;a+b*3<=2000;b++){
                    for(ll c=b;a+b+c*2<=2000;c++){
                         if(a*b*c>1000000){
                              ll d = 1000000*(a+b+c)/(a*b*c-1000000);
                              int f = (1000000*(a+b+c))%(a*b*c-1000000);
                              if(f==0&&(a+b+c+d)>=nn&&(a+b+c+d)<=mm){
                                     vector<ll> v; v.push_back(a);v.push_back(b);v.push_back(c);v.push_back(d);
                                     sort(v.begin(),v.end());
                                     mp[a+b+c+d].insert(v);
                              }

                         }
                    }
            }
        }

   map<ll , set< vector<ll> > >::iterator it1 = mp.begin();
   for(;it1!= mp.end();it1++){
        set< vector<ll> >::iterator it2 =it1->second.begin();
        for(;it2!=it1->second.end();it2++){
            vector<ll> v = *it2;
printf("%0.2f %0.2f %0.2f %0.2f\n",(double)v[0]/100,(double)(v[1])/100,(double)(v[2])/100,(double)(v[3])/100);        }
   }
  return 0;
}
