#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<cstring>
using namespace std;
#define ll long long
const int maxn = 1005;
const int mod = 1e7+7;

int jie(int n){
	int sum = 1;
	for(int i = 1; i <= n ;i++){
		sum = (sum * i);
	}
	return sum;
}

int main()
{
	scanf("%lld", &t);
	while(t --)
	{
		scanf("%lld", &n);
		printf("%lld\n", n ? n - 1 : 0);
	}
	return 0;
}
