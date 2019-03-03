#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#define ll long long
#define ull unsigned long long
using namespace std;

const ll INF = 1e14;
const int N = 2000000+10;
const ll mod=1e9+7;
ull P = 10000019ULL;
ull sqr[N],has[N];

//BKDRHash
const int seed = 13131; 
const int maxn = 2000000+10;
char str[maxn];
const int MOD = 2000007;
struct StringHash{
    int first[MOD+2],num;
    ull EdgeNum[maxn];
    int next[maxn],close[maxn]; 
    void init (){
        num = 0; memset (first,0,sizeof first);
        return ;
    }
    
    int insert (unsigned long long val,int id){
        int u = val % MOD;
        for (int i = first[u]; i ; i = next[i]) {
            if (val == EdgeNum[i]){
                int t = close[i]; 
				close[i] = id;
                return t;
            }
        }
        ++num; //没出现过的话，就加入图吧
        EdgeNum[num] = val; // 这个才是精确的
        close[num] = id;
        next[num] = first[u];
        first[u] = num;
        return 0;//没出现过
    }
}H;

char a[N];
ull ans = 0;
ull po[N],sm[N];
ull trans(int i,int j){
	ll tmp=sm[j]-(sm[i-1]*po[j-i+1])%mod;;
	return (tmp+mod)%mod;
}

void gao(int i,int j) {
    ull now = has[j] - has[i-1] * sqr[j-i+1];
    if(!H.insert(now,1)){
    	ans=(ans+trans(i,j))%mod;
	} 
}
int r[N];
int main() {
    scanf("%s",a+1);
    po[0]=1;
    int len = strlen(a+1);
    for(int i=1;i<=len;i++){
    	sm[i]=(sm[i-1]*10+a[i]-'0')%mod; 
    	po[i]=(po[i-1]*10)%mod;
	}
    sqr[0] = 1;
	for(int i = 1; i <= len; ++i) 
		sqr[i] = sqr[i-1] * P;
    for(int i = 1; i <= len; ++i) 
		has[i] = has[i-1] * P + a[i];
    int x = 0, p = 0;
    for(int i = 1; i <= n; ++i) {
        int j = 0;
        gao(i,i);
        if(p > i) 
			j = min(r[2*x-i],p-i);
        while(i + j + 1 <= n&& a[i+j+1] == a[i-j-1]){
            gao(i-j-1,i+j+1);
            j++;
        }
        r[i] = j;
        if(i+j > p){
            p = i + j;
            x = i;
        }
    }
    H.init();
    x = 0,p = 0;
    for(int i = 2; i <= len; ++i){
        int j = 0;
        if(p > i) j = min(r[2*x-i],p-i+1);
        while(i+j <= len && a[i+j] == a[i-j-1]) {
            gao(i-j-1,i+j);
            ++j;
        }
        r[i] = j;
        if(i+j-1 > p) {
            p = i+j-1;
            x = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}

