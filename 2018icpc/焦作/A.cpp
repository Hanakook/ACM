#include<iostream>
#include<string>
#include <algorithm>  

using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		transform(s.begin(), s.end(), s.begin(), ::toupper);  
		if(s == "JESSIE"){
			cout<<"Good guy!"<<endl;
		}
		else{
			cout<<"Dare you say that again?"<<endl;
		}

	}
	return 0;
}