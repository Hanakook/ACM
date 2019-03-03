#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdlib>
using namespace std;
const long long maxn=1e5+100;
const long long mod=1000000007;
long long shu,v,g,ca,n,m,k,t,x,y,tot,f[maxn],a[maxn];
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        memset(f,-1,sizeof(f));
        shu=0;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld%lld",&v,&g);
            tot=1;
            for(int j=1;j<=g;++j)
            {
                shu++;
                a[shu]=v*tot%mod;
                tot=tot*2;
            }
        }
        f[0]=0;
        for(int i=1;i<=shu;++i)
        for(int j=10000;j>=a[i];--j)
        {
            if(j-a[i]==0)
            {
                if(f[j]==-1)
                    f[j]=0;
                f[j]=(f[j]+1)%mod;
                continue;
            }
            if(f[j-a[i]]!=-1)
            {
                if(f[j]==-1)
                    f[j]=0;
                f[j]=(f[j]+f[j-a[i]])%mod;
            }
        }

        for(int i=1;i<=k;++i)
        {
            scanf("%lld",&x);
            if(f[x]!=-1)
                printf("%lld\n",f[x]);
            else
                printf("0\n");
        }
    }
    return 0;
}