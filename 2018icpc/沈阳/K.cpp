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
int T;
int sp[21] = {1,2,3,5,7,
11,13,17,23,31,37,53,71,73, 
113,131,137,173,
311,317,1000};

int change(string s){
	int num = 0;
	for( int i = 0 ;i < s.size(); i++){
		num = num * 10 + s[i] - '0';
	}
	return num;
}

 
int main(){
	cin>>T;
	int t = 1;
	 while(T--){
	 	string s;
	 	cin>>s;
	 	int len = s.size();
	 	if(len >= 4){
	 		printf("Case #%d: 317\n",t++);
	 	}
	 	else{
	 		int num = change(s);
	 		
	 		for(int i = 0 ; i <= 20;i++){
	 			if(num == sp[i]){
	 				printf("Case #%d: %d\n",t++,sp[i]);
	 				break;
	 			}
	 			else if(num < sp[i]){
	 				printf("Case #%d: %d\n",t++,sp[i-1]);
	 				break;
	 			}
	 		}
	 	}
	}
	return 0;
}
	 	