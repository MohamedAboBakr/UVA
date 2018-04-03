#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
typedef pair<int,pi> ppi;

vector<ppi> vec;

int check(int arr[],int n){
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]=i;
    }
    for(int i=0;i<vec.size();i++){
        int ind1,ind2;
        ind1=mp[vec[i].first];
        ind2=mp[vec[i].second.first];
        if(vec[i].second.second>0 && abs(ind1-ind2)<= vec[i].second.second){}
        else if(vec[i].second.second<0 && abs(ind1-ind2)>= -1*vec[i].second.second){}
        else return 0;
    }
    return 1;
}

int main()
{
    int n,m,a,b,c; scanf("%d%d",&n,&m);
    while(n){
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=i;
        }
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            vec.push_back(ppi(a,pi(b,c)));
        }
        int ans=0;
        do{
            ans+= check(arr,n);
        }while(next_permutation(arr,arr+n));
        printf("%d\n",ans);
        scanf("%d%d",&n,&m);
        if(n==0) break;
        vec.clear();
    }
    return 0;
}
