#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

ll a[100010], b[100010], c[100010];

ll lowbit(ll x){
	return x&(-x);
}

int n;
ll sum(ll x){
	ll s = 0;
	while(x > 0){
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}

void add(int x, ll val){
	while(x <= n){
		c[x] += val;
		x += lowbit(x);
	}
}

ll sum1(ll x){
	ll s = 0;
	while(x > 0){
		s += b[x];
		x -= lowbit(x);
	}
	return s;
}

void add1(int x,ll val){
	while( x <= n){
		b[x] += val;
		x += lowbit(x);
	}
}

int main(){
	int q;
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n; i++){
		scanf("%lld", &a[i]);
		add(i, a[i] * (n - i + 1));	
		add1(i, a[i]);
	}
	for(int i = 1; i <= q; i++){
		int l, r, op;
		scanf("%d", &op);
		if(op == 1){
			scanf("%d%d", &l, &r);
			printf("%lld\n", sum(r) - sum(l-1) - (sum1(r) - sum1(l-1)) * (n - r));
		} else {
			scanf("%d%d", &l, &r);
			add(l, (r - a[l]) * (n - l + 1));
			add1(l, r - a[l]);
			a[l] = r;
		}
	}
	return 0;	
}