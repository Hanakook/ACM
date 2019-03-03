#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,x;

//巴什博弈 
//只有一堆n个物品，两个人轮流从这堆物品中取物，
//规定每次至少取一个，最多取m个。最后取光者得胜。
void bash(){
	cin>>n>>m;
	if(n%(m+1)){
		cout<<"Win"<<endl;
	}
	else{
		cout<<"Lose"<<endl;
	}
}

//威佐夫博弈
//有两堆各若干个物品，两个人轮流从某一堆或同时从两堆中取同样多的物品，
//规定每次至少取一个，多者不限，最后取光者得胜 。
void Wythoff(){
	double k = (1+sqrt(5.0))/2;
	cin>>n>>m;
	if(n > m){
		swap(n,m);
	}
	int t = m - n;
	if( n == int(1.0 * t * k)){
		cout<<"Lose"<<endl;
	}
	else{
		cout<<"Win"<<endl;
	}
}

//尼姆博弈
//有n堆石子，从任意一堆石子中取出任意数量的石子
//规定至少取一颗，至多取出这一堆剩下的所有石子，最后取光者得胜。

void nim(){
	cin>>n;
	int ans = 0;
	for(int i = 1; i<= n; i++){
		cin>>x;
		ans ^= x;
	}
	if(ans == 0){
		cout<<"Lose"<<endl;
	}
	else{
		cout<<"Win"<<endl;
	}
}

int main(){

	return 0;
}