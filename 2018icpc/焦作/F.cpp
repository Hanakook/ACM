#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define maxn 422
#define maxm 84444
using namespace std;

int to[maxm],cap[maxm],cost[maxm],next[maxm],first[maxn],edge;
int d[maxn],num[maxn],from[maxn],tag[maxn],TAG=222;
int Q[maxm],bot,top;
int a[maxm],u[maxn],v[maxn],w[maxn];
int n,m,N,K,T,s,t,ans,M;

void _init()
{
    s=0,t=n+1,ans=0,edge=-1;
    for (int i=s; i<=t; i++) first[i]=-1;
}

void addedge(int U,int V,int W,int C)
{
    edge++;
    to[edge]=V,cap[edge]=W,cost[edge]=C,next[edge]=first[U],first[U]=edge;
    edge++;
    to[edge]=U,cap[edge]=0,cost[edge]=-C,next[edge]=first[V],first[V]=edge;
}

bool bfs()
{
    Q[bot=top=1]=s,tag[s]=++TAG,d[s]=0,num[s]=K,from[s]=-1;
    while (bot<=top){
        int cur=Q[bot++];
        for (int i=first[cur]; i!=-1; i=next[i])
            if (cap[i]>0 && (tag[to[i]]!=TAG || d[cur]+cost[i]<d[to[i]])){
                tag[to[i]]=TAG;
                num[to[i]]=min(num[cur],cap[i]);
                d[to[i]]=d[cur]+cost[i];
                from[to[i]]=i;
                Q[++top]=to[i];
            }
    }
    if (tag[t]!=TAG || d[t]>=0) return false;
    ans+=num[t]*d[t];
    for (int i=t; from[i]!=-1; i=to[from[i]^1])
        cap[from[i]]-=num[t],cap[from[i]^1]+=num[t];
    return true;
}

int main()
{
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&N,&K,&M);
        for (int i=0; i<M; i++){
            scanf("%d%d%d",&u[i],&v[i],&w[i]);            
            a[i]=u[i],a[i+N]=v[i];
        }
        sort(a,a+N+N);
        n=unique(a,a+N+N)-a;
        for (int i=0; i<N; i++){
            u[i]=lower_bound(a,a+n,u[i])-a+1;
            v[i]=lower_bound(a,a+n,v[i])-a+1;
        }
        _init();
        for (int i=0; i<=n; i++) addedge(i,i+1,K,0);
        for (int i=0; i<N; i++) addedge(u[i],v[i],1,-w[i]);
        while (bfs()) ;
        printf("%d\n",-ans);
    }
    return 0;
}