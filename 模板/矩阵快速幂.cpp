
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const int maxn = 3;
const ll mod = 1e9+7;

ll n,p;

//矩阵结构体 
struct Matrix{
    ll a[maxn][maxn];
    void init(){    //初始化为单位矩阵 
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= maxn;i++){
            a[i][i] = 1;
        }
    }
};

//矩阵乘法 
Matrix mul(Matrix a, Matrix b){
    Matrix ans;
    for(int i = 1;i <= 2;++i){
        for(int j = 1;j <= 2;++j){
            ans.a[i][j] = 0;
            for(int k = 1;k <= 2;++k){
                ans.a[i][j] = ans.a[i][j] % mod + a.a[i][k] * b.a[k][j] % mod;
            }
        }
    } 
    return ans;
}

//矩阵快速幂 
Matrix qpow(Matrix a,ll b){
    Matrix ans;
    ans.init();
    while(b){
        if(b & 1)
            ans = mul(ans,a);
        a = mul(a,a);
        b >>= 1;
    }
    return ans;
}

void print(Matrix a){
    for(int i = 1; i <= n;++i){
        for(int j = 1;j <= n;++j){
            cout << a.a[i][j]%mod<< " ";
        }
        cout << endl;
    }
}

int main(){
    Matrix base;
    Matrix ans;
    ans.a[1][1] = 1;
    ans.a[1][2] = 0;
    base.a[1][1] = 1;
    base.a[1][2] = 1;
    base.a[2][1] = 1;
    base.a[2][2] = 0;
    cin>>n;
    ans = mul(ans,qpow(base,n-1));
    cout<<ans.a[1][1]<<endl;
    return 0;
}