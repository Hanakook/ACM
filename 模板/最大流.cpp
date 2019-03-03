#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>
using namespace std;
const int inf = 0x7fffffff;
const int maxn = 205;
struct node{
	int v, w, next;
}edge[maxn*maxn];

int dis[maxn], pre[maxn], rec[maxn], head[maxn], block[maxn];
int n, m, no;
queue<int> q;//静态邻接表存边
inline void add(int u, int v, int w){
	edge[no].v = v; edge[no].w = w;
	edge[no].next = head[u]; head[u] = no++;
	edge[no].v = u; edge[no].w = 0;
	edge[no].next = head[v]; head[v] = no++;
}
inline void pre_init(){
	no = 0;
	memset(head, -1, sizeof head);
}

void init(int S, int T){	//初始化一定要注意把所涉及的都覆盖到 
	for(int i = 0; i <= n; ++i){ 
		dis[i] = inf,block[i] = 0;//标记阻塞点 
	} 
	while(!q.empty()) q.pop();
	dis[S] = 0; q.push(S);
	while(!q.empty()){//生成层次图 
		int tp = q.front(); q.pop();
		int k = head[tp];
		while(k != -1){
			if(dis[edge[k].v] == inf && edge[k].w){
				dis[edge[k].v] = dis[tp] + 1;
				q.push(edge[k].v);
			}
			k = edge[k].next;
		}
	}
}
int dinic(int S, int T){
	int top = S, ans = 0, flow = inf;
	pre[S] = S; init(S, T);
	while(dis[T] != inf){	//当S无法到达T，不能再增广了 
		int k = head[top];
		while(k != -1){
			if(edge[k].w && dis[edge[k].v] == dis[top]+1 
			&& !block[edge[k].v]) break;
			k = edge[k].next;
		}
		if(k != -1){	//找到下一个节点
			int v = edge[k].v;
			flow = min(flow, edge[k].w);
			pre[v] = top; rec[v] = k;
			top = v;
			if(top == T){
				ans += flow;
				v = -1; k = T;
				while(k != S){
					edge[rec[k]].w -= flow;
					edge[rec[k]^1].w += flow;
					if(!edge[rec[k]].w) v = k;	//寻找距S最近的一个"瓶颈"边 
					k = pre[k];
				}
				flow = inf;	//此处flow必须在外面，大佬的板子可能没注意到，我认为是必须的 
				if(v != -1){//找到"瓶颈"边
					top = pre[v];
					k = top;
					while(k != S){
						flow = min(edge[rec[k]].w, flow);
						k = pre[k];
					}
				}
			}
		}
		else{
			block[top] = 1;	//找不到下一节点成为阻塞点 
			top = pre[top];	//回溯 
			if(block[S]) init(S, T);//如果S被阻塞，重新计算层次图
			//阻塞点的产生也造成了flow的最小值可能是后面的值，虽然进行一次
			//增广并没什么问题，但上述寻找瓶颈边的判断则是必须的了。 
		}
	}
	return ans;
}
int main(){
	//ios::sync_with_stdio(0);
	int u, v, w;
	while(cin >> m >> n){
		pre_init();
		for(int i = 1; i <= m; ++i){
			cin >> u >> v >> w;
			add(u, v, w);
		}
		cout << dinic(1, n) << endl;
	}
	return 0;
}
 
 
/**********************比赛版本***********************/
 
//dicnic

#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = maxn*maxn;
struct node{int w; int v, next;} edge[maxm];
int pre[maxn], rec[maxn], head[maxn], block[maxn];
int dis[maxn];
int n, m, no;
int S, T;
queue<int> q;
inline void init(){
	no = 0;
	memset(head, -1, sizeof head);
}
inline void add(int u, int v, int w){
	edge[no].v = v; edge[no].w = w;
	edge[no].next = head[u]; head[u] = no++;
	edge[no].v = u; edge[no].w = 0;
	edge[no].next = head[v]; head[v] = no++;
}
void reset(int S, int T){
	memset(dis, 0x3f, sizeof dis);
	memset(block, 0, sizeof block);
	q.push(S); dis[S] = 0;
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int k = head[top]; k != -1; k = edge[k].next)
		if(dis[edge[k].v] == inf && edge[k].w)
			dis[edge[k].v] = dis[top]+1, q.push(edge[k].v);
	}
}
int dinic(int S, int T){
	int ans = 0, flow = inf;
	int top = S;
	reset(S, T); pre[S] = S;
	while(dis[T] != inf){
		int k, tmp;
		for(k = head[top]; k != -1; k = edge[k].next){
			if(edge[k].w && dis[edge[k].v]==dis[top]+1 && 
			!block[edge[k].v]) break;
		}
		if(k != -1){
			tmp = edge[k].v;
			flow = min(flow, edge[k].w);
			pre[tmp] = top, rec[tmp] = k;
			top = tmp;
			if(top == T){
				ans += flow; tmp = -1;
				for(; top != S; top = pre[top]){
					edge[rec[top]].w -= flow;
					edge[rec[top]^1].w += flow;
					if(!edge[rec[top]].w) tmp = top;
				}
				flow = inf;
				if(tmp != -1){
					top = pre[tmp];
					for(; top != S; top = pre[top])
					flow = min(flow, edge[rec[top]].w);
					top = pre[tmp];
				}
			}
		}
		else{
			block[top] = 1;
			top = pre[top];
			if(block[S]) reset(S, T);
		}
	}
	return ans;
}
void mapping(){
	int u, v, w;
	for(int i = 1; i <= m; ++i){
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
}
int main(){
	while(~scanf("%d %d", &m, &n)){
		S = 1, T = n;
		init();
		mapping();
		printf("%d\n", dinic(S, T));
	}
	return 0;
}


//sap
#include <algorithm>  
#include <iostream>  
#include <string.h>  
#include <cstdio>  
#include <queue>  
using namespace std;  
const int inf = 0x7fffffff;  
const int maxn = 205;  
const int maxm = maxn*maxn; //一定要好好计算边的数量   
struct node  
{  
    int v, w, next;  
}edge[maxm];  
int dis[maxn], pre[maxn], rec[maxn], head[maxn], gap[maxn], now[maxn];  
int n, m, no, up;  //up指逆层次图可能还有增广路时dis的上界 
queue<int> q;  
//静态邻接表存边   
inline void add(int u, int v, int w)  
{  
    edge[no].v = v; edge[no].w = w;  
    edge[no].next = head[u]; head[u] = no++;  
    edge[no].v = u; edge[no].w = 0;  
    edge[no].next = head[v]; head[v] = no++;  
}  
inline void pre_init()  
{  
    no = 0;  up = n;
    memset(head, -1, sizeof head);  
}  
void init(int S, int T)  
{
    for(int i = 0; i <= up; ++i)   
    {
    	now[i] = head[i];   //now用作当前弧的优化   
    	//注意这里now数组要把所有用到的标号都存过来  
    	gap[i] = 0, dis[i] = inf;
    	//初始化一定要注意把所涉及的都覆盖到   
	}
    while(!q.empty()) q.pop();  
    dis[T] = 0; q.push(T);  
    while(!q.empty())   //生成逆层次图   
    {  
        int tp = q.front(); q.pop();  
        ++gap[dis[tp]];  
        int k = head[tp];  
        while(k != -1)  
        {  
            if(dis[edge[k].v] == inf && edge[k^1].w)  
            {  
                dis[edge[k].v] = dis[tp]+1;  
                q.push(edge[k].v);  
            }  
            k = edge[k].next;  
        }  
    }  
}  
int SAP(int S, int T)  
{  
    int ans = 0, flow = inf, top = S;  
    pre[S] = S; init(S, T);  
    while(dis[S] < up)    //当S到T的距离大于等于点的个数时肯定就不能再增广了   
    {                   //切记此处与节点数比较，因为通过方向变会造成距离可能达到节点数  
        if(top == T)  
        {  
            ans += flow;  
            while(top != S) //修改残留网络，并置top为S   
            {  
                edge[rec[top]].w -= flow;  
                edge[rec[top]^1].w += flow;  
                top = pre[top];  
            }  
            flow = inf;  
        }  
        int k = now[top];  
        while(k != -1)  
        {  
            int v = edge[k].v;  
            if(edge[k].w && dis[top] == dis[v]+1)  
            {  
                flow = min(flow, edge[k].w);  
                pre[v] = top; rec[v] = k;  
                now[top] = k;//当前弧的优化   
                top = v;  
                break;  
            }  
            k = edge[k].next;  
        }  
        if(k == -1)  
        {  
            int mind = n;  
            if(--gap[dis[top]] == 0) break;//出现断层，间隙优化   
            int k = now[top] = head[top];//改变当前点的距离标号，也要清除之前的当前弧优化的影响   
            while(k != -1)  
            {  
                if(edge[k].w && mind>dis[edge[k].v]) mind = dis[edge[k].v];  
                k = edge[k].next;  
            }  
            ++gap[dis[top] = mind+1];  
            top = pre[top];//回溯到上一个点   
        }  
    }  
    return ans;  
}
int main()  
{
    ios::sync_with_stdio(0);
	int u, v, w;
	while(cin >> m >> n)
	{
		pre_init();
		for(int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w;
			add(u, v, w);
		}
		cout << SAP(1, n) << endl;
	}
    return 0;  
}
 
 
/**********************比赛版本***********************/
 
#include <algorithm>  
#include <iostream>  
#include <string.h>  
#include <cstdio>  
#include <queue>  
using namespace std;  
const int inf = 0x3f3f3f3f;  
const int maxn = 205;  
const int maxm = maxn*maxn;
struct node{int w; int v, next;} edge[maxm];  
int pre[maxn], rec[maxn], head[maxn], gap[maxn], now[maxn];  
int dis[maxn];
int n, m, no, up;  
int S, T; 
queue<int> q;
inline void add(int u, int v, int w)  {  
    edge[no].v = v; edge[no].w = w;  
    edge[no].next = head[u]; head[u] = no++;  
    edge[no].v = u; edge[no].w = 0;  
    edge[no].next = head[v]; head[v] = no++;  
}  
inline void pre_init(){  
    no = 0;
    memset(head, -1, sizeof head);  
}  
void init(int S, int T){  
    memset(gap, 0, sizeof gap);  
    memset(dis, 0x3f, sizeof dis);  
    for(int i = 0; i <= up; ++i)   
    now[i] = head[i];
    while(!q.empty()) q.pop();  
    dis[T] = 0; q.push(T);  
    while(!q.empty()){  
        int tp = q.front(); q.pop();  
        ++gap[dis[tp]];  
        int k = head[tp];  
        while(k != -1){  
            if(dis[edge[k].v] == inf && edge[k^1].w){  
                dis[edge[k].v] = dis[tp]+1;  
                q.push(edge[k].v);  
            }  
            k = edge[k].next;  
        }  
    }  
}  

int SAP(int S, int T)  {
    int ans = 0, flow = inf;
	int top = S;  
    pre[S] = S; init(S, T);  
    while(dis[S] < up){
        if(top == T){  
            ans += flow;  
            while(top != S){  
                edge[rec[top]].w -= flow;  
                edge[rec[top]^1].w += flow;  
                top = pre[top];  
            }  
            flow = inf;  
        }  
        int k = now[top];  
        while(k != -1){  
            int v = edge[k].v;  
            if(edge[k].w && dis[top] == dis[v]+1){  
                flow = min(flow, edge[k].w);  
                pre[v] = top; rec[v] = k;  
                now[top] = k; top = v;  
                break;  
            }  
            k = edge[k].next;  
        }  
        if(k == -1){  
            int mind = up;  
            if(--gap[dis[top]] == 0) break;
            int k = now[top] = head[top];
            while(k != -1){  
                if(edge[k].w && mind>dis[edge[k].v]) mind = dis[edge[k].v];  
                k = edge[k].next;  
            }  
            ++gap[dis[top] = mind+1];  
            top = pre[top];  
        }  
    }  
    return ans;  
}  

void mapping(){
	int u, v, w;
	for(int i = 1; i <= m; ++i){  
        scanf("%d %d %d", &u, &v, &w); 
        add(u, v, w);  
    }
}
int main()  {
    while(~scanf("%d %d", &m, &n)){
    	cin>>S>>T; 
		up = n;
        pre_init();  
        mapping();
        printf("%d\n", SAP(S, T)); 
    }  
    return 0;  
}

