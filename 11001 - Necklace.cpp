#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll>pi;
typedef pair<string,pi> ppi;

double epsilon=1.0E-12;
bool essentiallyEqual(double a, double b)
{
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyGreaterThan(double a, double b)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyLessThan(double a, double b)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}


int main()
{
   int vt,v0;
   scanf("%d%d",&vt,&v0);
   while(vt){
       double v1,v2,d,mx=0.0;
       int nm=0,i=1,f=0;
       v1=vt*1.0;v2=1.0*v0;
       while(definitelyGreaterThan(v1,v2)){
           d = 0.3*sqrt(v1-v2);
           if(definitelyGreaterThan(d*(i*1.0),mx)){
              mx=d*(i*1.0);
              nm=i;
           }else if(essentiallyEqual(d*(i*1.0),mx)){
              nm=0;
           }
           i++;
           v1 = (1.0*vt)/(1.0*i);
           //cout << i << " " << v1 << "\n";
       }
       printf("%d\n",nm);
       scanf("%d%d",&vt,&v0);
   }
   return 0;
}
