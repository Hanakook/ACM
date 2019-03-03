#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdlib>
using namespace std;
const long long maxn=1e3+100;
const long long mod=1000000007;
long long shu,v,g,ca,n,m,k,t,x,y,tot,fd[maxn][7],fx[maxn][7],a[maxn];
char c[10];
long long ma(long long a,long long  b,long long c)
{
    long long k=max(a,b);
    return max(k,c);
}
long long mi(long long a,long long  b,long long c)
{
    long long k=min(a,b);
    return min(k,c);
}
int main()
{
    scanf("%lld",&ca);
    while(ca--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        scanf("%s",c);
        long long  LONG_LONG_MIN=-1546153266166163;
        long long  LONG_LONG_MAX=1546156226166163;
        for(int i=0;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            fd[i][j]=LONG_LONG_MIN;
            fx[i][j]=LONG_LONG_MAX;
        }

        fd[0][0]=fx[0][0]=k;
        for(int i=1;i<=n;++i)
        {
            fd[i][0]=k;
            fx[i][0]=k;
            for(int j=1;j<=min((long long)i,m);++j)
            {
                if(c[j-1]=='+')
                {
                    fd[i][j]=ma(fd[i-1][j],fd[i-1][j-1]+a[i],fx[i-1][j-1]+a[i]);
                    fx[i][j]=mi(fx[i-1][j],fx[i-1][j-1]+a[i],fd[i-1][j-1]+a[i]);
                }
                if(c[j-1]=='-')
                {
                    fd[i][j]=ma(fd[i-1][j],fd[i-1][j-1]-a[i],fx[i-1][j-1]-a[i]);
                    fx[i][j]=mi(fx[i-1][j],fx[i-1][j-1]-a[i],fd[i-1][j-1]-a[i]);
                }
                if(c[j-1]=='*')
                {
                    fd[i][j]=ma(fd[i-1][j],fd[i-1][j-1]*a[i],fx[i-1][j-1]*a[i]);
                    fx[i][j]=mi(fx[i-1][j],fx[i-1][j-1]*a[i],fd[i-1][j-1]*a[i]);
                }
                if(c[j-1]=='/')
                {
                    fd[i][j]=ma(fd[i-1][j],fd[i-1][j-1]/a[i],fx[i-1][j-1]/a[i]);
                    fx[i][j]=mi(fx[i-1][j],fx[i-1][j-1]/a[i],fd[i-1][j-1]/a[i]);
                }
            }
        }
        printf("%lld\n",fd[n][m]);
    }
    return 0;
}