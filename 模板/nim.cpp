#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans;
	cin>>ans;
	for(int i = 1; i < n ;i++){
		int x;
		cin>>x;
		ans ^= x;
	}
	if(ans ){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}


	return 0;
}