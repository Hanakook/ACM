#include<iostream>
#include<cstdio>
#include<cstring>
const int maxn=1001;
using namespace std;

int c,n,m;
int map[maxn][maxn];
int dis[maxn];
bool vis[maxn];

int prim(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis)); 
    int ans=0;
    dis[1]=0;
    while(1){
        int k=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dis[j]<dis[k])
                k=j; 
        } 
        if(!k) break;
        vis[k]=1; 
        ans+=dis[k];
        for(int j=1;j<=n;j++){
            if(dis[j]>map[k][j]){
                dis[j]=map[k][j];
            }

        }
    }
    return ans;
}
int main(){

	while(cin>>c>>m>>n){
	    int x,y,z;
	    memset(map,0x3f,sizeof(map));  
	    for(int i = 0; i < m; i++){
	    	cin>>x>>y>>z;
	        map[x][y]=map[y][x]=min(map[x][y],z);
	    }
	    int ans = prim();
	  //  cout<<ans<<endl;
	    if(ans > c || ans == 0){
	    	cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
		}
	}
    return 0;
}


/*
void print(int x){
    if(x==-1) return ;
    print(path[x]);
    printf("%d->",x);
}*/
