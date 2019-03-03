#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define ll long long

ll b,p,mod;

ll qpow( ll a,ll b){
    ll res = 1;
    while( b ){
        if( b&1 ){
            res = res*a%mod;
        }
        a = a*a%mod;
        b >>= 1;
    }
    return res%mod;
}

int main(){
	cin>>b>>p>>mod;
	ll ans = qpow(b,p);
	printf("%lld^%lld mod %lld=%lld\n",b,p,mod,ans);
	return 0;
}