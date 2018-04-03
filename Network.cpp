#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;
map<int,set<pi> > buffer;
map<int,int> buffsz;
vector<ppi> packets;
vector<int> szs;
int mn,sz;


int main()
{
    int n,m,a,tst=1;scanf("%d%d",&n,&m);
    while(n){
        int perms[n];
        buffsz.clear();
        buffer.clear();
        packets.clear();
        szs.clear();
        for(int i=0;i<n;i++) {
                scanf("%d",&a);
                szs.push_back(a);
                perms[i]=i+1;
        }

        for(int i=0;i<m;i++){
            int msg,strt,endd;
            scanf("%d%d%d",&msg,&strt,&endd);
            packets.push_back(ppi(msg,pi(strt,endd)));
        }
        mn=64000000;
        do{
            sz=0;
            int curr=0,csz=0;
            int wanted[6]={1,1,1,1,1,1};
            int tknsz[6]={0};
            buffer.clear();
            buffsz.clear();
            for(int i=0;i<m;i++){
                  ppi packet = packets[i];
                  int msg=packet.first,strt,endd;
                  pi ln = packet.second; strt=ln.first; endd=ln.second;
                  if(msg!=perms[curr]){
                     //if(wanted[msg]==strt)wanted[msg]=endd+1;
                     sz+=endd-strt+1; csz=max(csz,sz);
                     buffer[msg].insert(ln);
                     buffsz[msg]+=endd-strt+1;
                  }else{
                      if(wanted[msg]!=strt){
                         sz+=endd-strt+1; csz=max(csz,sz);
                         buffer[msg].insert(ln);
                         buffsz[msg]+=endd-strt+1;
                      }else {
                          wanted[msg]=endd+1;
                          set<pi>::iterator it=buffer[msg].begin();
                          vector<pi>vec;
                          while(it!=buffer[msg].end()&&it->first==wanted[msg]){
                                vec.push_back(*it);
                                wanted[msg]=it->second+1;
                                buffsz[msg]-=it->second-it->first+1;
                                sz-= (it->second-it->first+1);
                                it++;
                          }
                          for(int j=0;j<vec.size();j++){
                               buffer[msg].erase(vec[j]);
                          }
                      }
                      tknsz[msg]+=endd-strt+1;
                      if(tknsz[msg]==szs[msg-1]){
                           sz-=buffsz[msg]; buffsz[msg]=0;
                           buffer[msg].clear();
                           curr++;
                           while(curr<n){
                                if(buffsz[perms[curr]]>0){
                                    tknsz[perms[curr]]= buffsz[perms[curr]];
                                    set<pi>::iterator it=buffer[perms[curr]].begin();
                                    vector<pi>vec;
                                    while(it!=buffer[perms[curr]].end()&&it->first==wanted[perms[curr]]){
                                        vec.push_back(*it);
                                        wanted[perms[curr]]=it->second+1;
                                        buffsz[perms[curr]]-=it->second-it->first+1;
                                        sz-= (it->second-it->first+1);
                                        it++;
                                    }
                                    for(int j=0;j<vec.size();j++){
                                        buffer[perms[curr]].erase(vec[j]);
                                    }
                                    if(tknsz[perms[curr]]==szs[perms[curr]-1]) curr++;
                                    else break;
                                }else{
                                    break;
                                }
                           }
                      }
                  }
            }

           mn = min(mn,csz);
        }while(next_permutation(perms,perms+n));
        printf("Case %d: %d\n\n",tst++,mn);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
