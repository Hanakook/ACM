#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int N =1e8+5;
const int mod = 1e9+7;

int a[N];
void init(){
	a[0] = 0;
	a[1] = 2;
	for(int i = 2; i < N ;i++){
		a[i] = (3*a[i-1]-a[i-2])/2 + i + 1;
	}

}


int main(){
	int n,m;
	cin>>n>>m;
	init();
	for(int i = 0; i <= n ;i++){
		cout<<a[i]<<" ";
	}


	return 0;
}