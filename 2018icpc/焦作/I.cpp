#include <iostream>
using namespace std;

int a, b, c;
int main(){
    while(cin>>a>>b>>c){
        int ans = a * b * c;
        if(ans & 1)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;
    }
    return 0;
}