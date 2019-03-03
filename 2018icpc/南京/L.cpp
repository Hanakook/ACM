#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define M 101000
#define N 1001000
#define pa pair<int,int>
ll n,m,k,s=1,t;
ll cnt,lj[M],fro[N],to[N],v[N];
inline void add(ll a,ll b,ll c){fro[++cnt]=lj[a];to[cnt]=b;v[cnt]=c;lj[a]=cnt;}
ll dis[M][22];
bool vs[M][22];
priority_queue<pa,vector<pa>,greater<pa> >q;
void dijkstra()
{
    memset(dis,0x3f,sizeof(dis));
    dis[s][0]=0;
    q.push(make_pair(0,s));
    ll u,et,x;
    while(!q.empty())
    {
        u=q.top().second;q.pop();
        x=u/(n+1);u=u%(n+1);
        if(vs[u][x]) continue;
        vs[u][x]=1;
        for(ll i=lj[u];i;i=fro[i])
        {
            et=to[i];
            if(dis[et][x]>dis[u][x]+v[i])
            {
                dis[et][x]=dis[u][x]+v[i];
                q.push(make_pair(dis[et][x],et+x*(n+1)));
            }
            if(x==k) continue;
            if(dis[et][x+1]>dis[u][x])
            {
                dis[et][x+1]=dis[u][x];
                q.push(make_pair(dis[et][x+1],et+(x+1)*(n+1)));
            }
        }
    }
}
ll T;
ll a,b,c;
int main()
{
	scanf("%lld", &T);
	while(T--)
	{
		memset(fro,0,sizeof(fro));
		memset(lj,0,sizeof(lj));
		memset(to,0,sizeof(to));
		memset(v,0,sizeof(v));
		memset(vs,0,sizeof(vs));
		
		scanf("%lld%lld%lld", &n, &m, &k);
	    t=n;
	    for(ll i=1;i<=m;i++){
			scanf("%lld%lld%lld", &a, &b, &c);
	        add(a,b,c);
	    }
	    dijkstra();
	    printf("%lld\n",dis[n][k]);
	}
    return 0;
}

