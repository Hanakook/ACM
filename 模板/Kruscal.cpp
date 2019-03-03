#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<fstream>
using namespace std;
 
const int MAXN=505;//最大点数
const int MAXM=250005;//最大边数
int f[MAXN];
 
struct Edge{
    int u,v,w;
}edge[MAXM];
 
int cnt;
 

bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
 
int find(int x){
    if(f[x] == -1)
        return x;
    else
        return f[x] = find(f[x]);
}

int Kruskal(int n){
    memset(F,-1,sizeof(F));
    sort(edge,edge+cnt,cmp);
    int cnt1 = 0;//计算加入的边数
    int ans = 0;
    for(int i = 0; i < cnt;i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if(t1 != t2){
            ans += w;
            f[t1] = t2;
            cnt1++;
        }
        if(cnt1 == n-1)
            break;
    }
    if(cnt1 < n-1)
        return -1;//不连通
    else
        return ans;
}
 
int main(){
    int c,n,m;
    cin>>c>>m>>n;
    cnt=0;
    for(int i = 1; i <= m ;i++){
    	int x,y,z;
    	cin>>x>>y>>z;
    	edge[cnt].u = x;
    	edge[cnt].v = y;
    	edge[cnt++].w = z;
	}
	int ans = Kruskal(n);
   
    if(ans > c || ans == -1){
    	cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
	
    return 0;
}
/*
20 10 5
1 2 6
1 3 3
1 4 4
1 5 5
2 3 7
2 4 7
2 5 8
3 4 6
3 5 9
4 5 2
*/
