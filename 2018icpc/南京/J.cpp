#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cstring>
using namespace std;
#define ll long long
const int maxn=2e7+10;
ll table[maxn],prime[maxn],vis[maxn];
void init(){
	memset(vis,0,sizeof(vis));
    table[1] = 1;
    int cnt = 0;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            table[i]=2;
        }
        for(int j=0; j < cnt && i*prime[j]<maxn;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]){
                table[ i*prime[j] ] = table[i] * table[ prime[j] ];
            }
            else{
                if( i % (prime[j]*prime[j]) == 0) 
					table[ i*prime[j] ] = 0;
                else 
					table[ i*prime[j] ] = table[i] - table[i/prime[j]];
                break;
            }
        }
    }
    for(int i = 2; i < maxn; i++) 
		table[i] = table[i] + table[i-1];
}
int main(){
	init();
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",table[n]);
    }
    return 0;
}

