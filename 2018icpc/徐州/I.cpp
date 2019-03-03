#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;

int main(){
	int T;
	scanf("%d", &T);
	while(T --){
		int n;
		char seed;
		cin>>n>>seed;
		cin>>s;
		int ans = 2 * n;
		//只需要判断第一个是不是为0还是个位数
		for(int i = 0; i < n ;i++){
			int tmp = abs(seed-s[i]);
			if(tmp == 0){
				ans -= 2;
			}
			else if(tmp < 10){
				ans -= 1;
				break;
			}
			else{
				break;
			}
		}
		if(ans == 0)
			ans = 1;
		cout<<ans<<endl;
	}
	return 0;
}