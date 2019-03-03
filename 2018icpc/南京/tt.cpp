#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<map>
using namespace std;
#define ULL unsigned long long
const int maxn=2000000+20;
ULL P = 1313131;
ULL sqr[maxn/2],has[maxn/2],V[maxn];

int Laxt[maxn],Next[maxn],cnt=0;
 
const int MOD = 2000007;

bool _insert(ULL Now)
{
       int u=Now%MOD;
       for(int i=Laxt[u];i;i=Next[i]){
        if(V[i]==Now) return true;
       }
       Next[++cnt]=Laxt[u];
       Laxt[u]=cnt;
       V[cnt]=Now;
       return false;
}
int ans=0;
map<ULL, int> mp;
void _hash(int x,int y){
    ULL Now=has[y]-has[x-1]*sqr[y-x+1];
    if(!_insert(Now)) ++ans,mp[Now]++;
} 
void _malacher()
{
    int R=0,Mid=0,Len;
    char c[maxn];
    scanf("%s",c+1);
    Len=strlen(c+1);
    sqr[0]=1;
    for(int i=1;i<=Len;i++){
        sqr[i]=sqr[i-1]*P;
        has[i]=has[i-1]*P+c[i];
    }  
    int r[maxn];
     for(int i=1;i<=Len;++i) {      
        _hash(i,i);
        if(R>i) r[i]=min(r[2*Mid-i],R-i);
        while(i+r[i]+1<=Len&&c[i+r[i]+1]==c[i-r[i]-1]){
            _hash(i-r[i]-1,i+r[i]+1);
            r[i]++;
        }
        if(i+r[i]>R) {
            R=i+r[i];
            Mid=i;
        }
    }
    
    cnt=0;Mid=0;R=0;
    memset(Laxt,0,sizeof(Laxt));
    memset(r,0,sizeof(r));
    for(int i=2;i<=Len;++i) {
        if(R>i) r[i]=min(r[2*Mid-i],R-i+1);
        while(i+r[i]<=Len&&c[i+r[i]]==c[i-r[i]-1]) {
            _hash(i-r[i]-1,i+r[i]);
            ++r[i];
        }
        if(i+r[i]-1>R) {
            R=i+r[i]-1;
            Mid=i;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    _malacher();
    return 0;
}
