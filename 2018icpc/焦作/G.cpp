#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 100015;
const ll mod = 1000000000+7;

ll qpow( ll a,ll n,ll mod ){
    ll res = 1;
    while( n>=1 ){
        if( n&1 ){
            res = res*a%mod;
        }
        a = a*a%mod;
        n >>= 1;
    }
    return res%mod;
}

ll GetNum( char str[],ll mod ){
    ll res = 0;
    int len = strlen( str );
    for( int i=0;i<len;i++ ){
        res = (res*10+str[i]-'0')%mod;
    }
    return res;
}

int main(){
    char str[ maxn];
    int T;
    cin>>T;
    while( T--){
    	scanf("%s",str);
        ll n = GetNum( str,mod-1 );
        printf("%lld\n",qpow( 2,(n-1+mod)%mod,mod ));
    }
    return 0;
}