#include <bits/stdc++.h>
inline long long read(){long long x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;

const long long INF = 1e14;
const int N = 1e6 + 7;

unsigned long long P = 10000019ULL;
unsigned long long sqr[N],has[N];

//BKDRHash，最优的字符串hash算法。hash一开始是等于0的
const int seed = 13131; // 31 131 1313 13131 131313 etc..
const int maxn = 2000000+10;
char str[maxn];
unsigned long long sumHash[maxn]; //前缀hash值
const int MOD = 2000007;
struct StringHash
{
    int first[MOD+2],num;
    unsigned long long EdgeNum[maxn]; // 表明第i条边放的数字(就是sumHash那个数字)
    int next[maxn],close[maxn]; //close[i]表示与第i条边所放权值相同的开始的最大位置
    //就比如baba，现在枚举长度是2，开始的时候ba，close[1] = 1;表明"ba"开始最大位置是从1开始
    //然后枚举到下一个ba的时候，close[1]就要变成3了，开始位置从3开始了
    void init ()
    {
        num = 0; memset (first,0,sizeof first);
        return ;
    }
    int insert (unsigned long long val,int id) //id是用来改变close[]的
    {
        int u = val % MOD;
        for (int i = first[u]; i ; i = next[i]) //存在边不代表出现过，出现过要用val判断，val才是唯一的，边还是压缩后(%MOD)的呢
        {
            if (val == EdgeNum[i]) //出现过了
            {
                int t = close[i]; close[i] = id;//更新最大位置
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
int ans = 0;
map<unsigned long long, int> mp;
void gao(int i,int j) {
    unsigned long long now = has[j] - has[i-1] * sqr[j-i+1];
    if(!H.insert(now,1)) ++ans,mp[now]++;
}
int r[N];
int main() {
    scanf("%s",a+1);
    int n = strlen(a+1);
    sqr[0] = 1;for(int i = 1; i <= n; ++i) sqr[i] = sqr[i-1] * P;
    for(int i = 1; i <= n; ++i) has[i] = has[i-1] * P + a[i];
    int x = 0, p = 0;
    for(int i = 1; i <= n; ++i) {
        int j = 0;
        gao(i,i);
        if(p > i) j = min(r[2*x-i],p-i);
        while(i + j + 1 <= n&& a[i+j+1] == a[i-j-1])
        {
            gao(i-j-1,i+j+1);
            j++;
        }
        r[i] = j;
        if(i+j > p) {
            p = i + j;
            x = i;
        }
    }
    H.init();
    x = 0,p = 0;
    for(int i = 2; i <= n; ++i) {
        int j = 0;
        if(p > i) j = min(r[2*x-i],p-i+1);
        while(i+j<=n && a[i+j] == a[i-j-1]) {
            gao(i-j-1,i+j);
            ++j;
        }
        r[i] = j;
        if(i+j-1 > p) {
            p = i+j-1;
            x = i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
