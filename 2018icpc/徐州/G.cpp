#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
int n,m;
int x[maxn],y[maxn];
set<int> xx;
set<int> yy;
set<int>::iterator it;
ll ans = 0;
void addl(int sx,int sy){
    it = xx.lower_bound(sx);
    if(it == xx.begin())
        ans += sx;
    else {
        it--;
        ans += sx - *it;
    }
    
    it = yy.lower_bound(sy);
    if(it == yy.begin())
        ans += sy;
    else{
        it--;
        ans += sy - *it;
    } 
}
int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i]>>y[i];
    for(int i = n-1; i >= 0; i--){
        addl(x[i],y[i]);
        xx.insert(x[i]);
        yy.insert(y[i]);
    }
    cout<<ans<<endl;
    return 0;
}