#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define rank rankk
#define ll long long

const int MAXN=100005;
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m){
    str[n++]=0;
    int i, j, p, *x = t1, *y = t2;

    for(i = 0;i < m;i++)c[i] = 0;
    for(i = 0;i < n;i++)c[x[i] = str[i]]++;
    for(i = 1;i < m;i++)c[i] += c[i-1];
    for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
    for(j = 1;j <= n; j <<= 1)
    {
        p = 0;

        for(i = n-j; i < n; i++)y[p++] = i;
        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;

        for(i = 0; i < m; i++)c[i] = 0;
        for(i = 0; i < n; i++)c[x[y[i]]]++;
        for(i = 1; i < m;i++)c[i] += c[i-1];
        for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
        swap(x,y);

        p = 1; x[sa[0]] = 0;
        for(i = 1;i < n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p >= n)break;
        m = p;
    }
    int k = 0; n--;
    for(i = 0;i <= n;i++)rank[sa[i]] = i;
    for(i = 0;i < n;i++)
    {
        if(k)k--;
        j = sa[rank[i]-1]; while(str[i+k] == str[j+k])k++; height[rank[i]] = k;
    }
}
int rank[MAXN],height[MAXN];
int RMQ[MAXN];
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
    mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i=1;i<=n;i++)best[0][i]=i;
    for(int i=1;i<=mm[n];i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
    {
        int a=best[i-1][j];
        int b=best[i-1][j+(1<<(i-1))];
        if(RMQ[a]<RMQ[b])best[i][j]=a; else best[i][j]=b;
    }
}
int askRMQ(int a,int b)
{
    int t; t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b)
{
    a=rank[a];b=rank[b];
    if(a>b)swap(a,b);
    return height[askRMQ(a+1,b)];
}
int t,k,len;
char sts[MAXN];
int st[MAXN],sa[MAXN];
multiset<int>s;
ll cal(int x)
{
    ll an=0;
    if(x==1)
    {
        an=1LL*len*(len+1LL)/2LL;
        for(int i=1;i<=len;i++)an-=height[i];
    }
    else
    {
        s.clear();
        for(int i=1;i<=x-1;i++)s.insert(height[i]);
        for(int i=x;i<=len;i++)
        {
            int pre=*s.begin();s.erase(s.find(height[i-x+1]));s.insert(height[i]);
            //printf("%d %d!\n",pre,*s.begin());
            an+=max(0,*s.begin()-pre);
        }
    }
    return an;
}
int main(){
    scanf("%d",&t);
    while(~scanf("%s",sts)){
      int l,r;
        scanf("%d%d",&l,&r);
        len=strlen(sts);
        memset(height,0,sizeof(height));
        for(int i=0;i<len;i++)
          st[i]=sts[i]-'A'+1;
        da(st,sa,rank,height,len,27);
       /* for(int i=1;i<=len;i++)
            printf("%d\n",height[i]);*/
        printf("%lld\n",cal(l)-cal(r+1));
        
    }
    return 0;
}