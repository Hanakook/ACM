#include <cstdio>
#include <map>
#include <iostream>
#include <map>
using namespace std;
#define ll long long
const int N = 5e6;

ll n,m;

int mu[N+10],pri[N+10],top;
bool mark[N+10];
map<ll,ll>V;

int cnt;
ll p[N];
ll val[N];
int bit[N];


/*杜教筛*/
void init(){
    mu[1]=1;
    for(int i = 2; i <= N; i++){
        if(!mark[i]){
            pri[++top] = i;
            mu[i] = -1;
        }
        for(int j = 1; j <= top && i * pri[j] <= N; j++){
            mark[ i * pri[j] ] = true;
            if(i % pri[j] == 0) 
                break;
            mu[ i * pri[j] ] = -mu[i];
        }
    }
    for(int i = 2; i <= N; i++) 
        mu[i] += mu[i-1];
}
ll calc(ll x){
    if(x <= N) 
        return mu[x];
    if(V[x]) 
        return V[x];
    ll ans = 1;
    for(ll i = 2,r; i <= x; i = r+1){
        r = x/(x/i);
        ans -= calc(x/i) * (r-i+1);
    }

    V[x] = ans;
    return ans;
}

ll phi(ll x){ 
    return ( (bit[x] & 1) ? -1 : 1 );
}

ll solve(ll m, ll n) {
    if (bit[n] == 0) 
        return calc(m);
    if (m == 0) 
        return 0;
    if (m == 1) 
        phi(n);
    ll ans = 0;
    for (ll i = n; ; i = (i-1) & n){
        ans += phi(i) * solve( m/val[i] , i);
        if (!i) 
            break;
    }
    return ans * phi(n);
}


int main(){
    init();
    cin>>m>>n;
    ll x = n;
    cnt = 0;
    int flag = 0;
    for( ll i = 2 ; i * i <= x ;i++){
        if(x%i == 0){
            //判断有偶数个因子
            int t = (x/i) % i;
            if(t == 0){
                flag = 1;
                break;
            }
            //不是的话加入
            p[cnt++] = i;
            while(x % i == 0){
                x /= i;
            }
        }
    }
    if(flag){
        cout<<0<<endl;
        return 0;
    }
    if(x > 1)
        p[cnt++] = x;
    for(int i = 0; i < (1<<cnt); i++){
        bit[i] = 0;
        val[i] = 1;
        for(int j = 0; j < cnt; j++){
            if(i & (1<<j) ){
                bit[i]++;
                val[i] *= p[j];
            }
        }
    }
    cout<<solve(m,(1<<cnt)-1)<<endl;
    return 0;
}