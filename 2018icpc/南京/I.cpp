#include <bits/stdc++.h>
inline long long read(){long long x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;

const long long INF = 1e14;
const int N = 1e6 + 7;

unsigned long long P = 10000019ULL;
unsigned long long sqr[N],has[N];

//BKDRHash�����ŵ��ַ���hash�㷨��hashһ��ʼ�ǵ���0��
const int seed = 13131; // 31 131 1313 13131 131313 etc..
const int maxn = 2000000+10;
char str[maxn];
unsigned long long sumHash[maxn]; //ǰ׺hashֵ
const int MOD = 2000007;
struct StringHash
{
    int first[MOD+2],num;
    unsigned long long EdgeNum[maxn]; // ������i���߷ŵ�����(����sumHash�Ǹ�����)
    int next[maxn],close[maxn]; //close[i]��ʾ���i��������Ȩֵ��ͬ�Ŀ�ʼ�����λ��
    //�ͱ���baba������ö�ٳ�����2����ʼ��ʱ��ba��close[1] = 1;����"ba"��ʼ���λ���Ǵ�1��ʼ
    //Ȼ��ö�ٵ���һ��ba��ʱ��close[1]��Ҫ���3�ˣ���ʼλ�ô�3��ʼ��
    void init ()
    {
        num = 0; memset (first,0,sizeof first);
        return ;
    }
    int insert (unsigned long long val,int id) //id�������ı�close[]��
    {
        int u = val % MOD;
        for (int i = first[u]; i ; i = next[i]) //���ڱ߲�������ֹ������ֹ�Ҫ��val�жϣ�val����Ψһ�ģ��߻���ѹ����(%MOD)����
        {
            if (val == EdgeNum[i]) //���ֹ���
            {
                int t = close[i]; close[i] = id;//�������λ��
                return t;
            }
        }
        ++num; //û���ֹ��Ļ����ͼ���ͼ��
        EdgeNum[num] = val; // ������Ǿ�ȷ��
        close[num] = id;
        next[num] = first[u];
        first[u] = num;
        return 0;//û���ֹ�
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
