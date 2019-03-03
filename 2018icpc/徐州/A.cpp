#include <iostream>
#include <cstdio> 
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll use[1000010];
ll a[1000010], b[1000010], c[1000010];
  
int main(){
//	cout << mod  * mod<< endl;
 	use[0] = 1;
	for(int i = 1; i<=1e6; i++){
	 	use[i] = use[i-1] * 2 % mod;
		if(use[i] <= 3)
		 use[i] += mod;
	} 
	 
	int T; 
	scanf("%d", &T);
	while (T--){
		 
		int N, k;
		scanf("%d%d", &N, &k);
		if(N == 1){
			printf("%lld\n", use[k] % mod);
			continue;
		}
		c[2] = use[k];
		a[2] = use[k] * (use[k] - 2) % mod;
//		cout << c[2] << " " << a[2] <<endl; 
		for(int i = 3;i  <= N; i++){
		 	a[i] = (((b[i-1] * (use[k] - 2)) % mod +(c[i-1] * (use[k] - 2) )% mod
 + (a[i-1]  * (use[k] - 3))	 %mod)) % mod;
			 c[i] = (a[i-1] + c[i-1]) % mod;
			b[i] = (b[i-1] + a[i-1]) %mod;	
		} 
		printf("%lld\n", (a[N] + c[N]) % mod);  
	}
	
} 