#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int maxn = 2e5+7;

vector <int> E[maxn];

int dfn[maxn],low[maxn],tot,n,ans = maxn;
stack<int> S;

int vis[maxn];
void tarjan(int x){
    low[x] = dfn[x] = ++tot;
    S.push(x);vis[x] = 1;
    for(int i = 0; i < E[x].size(); i++ ){
        int v = E[x][i];
        if(!dfn[i]){
            tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(vis[i]){
            low[x] = min(low[x],dfn[v]);
        }
    }

    if(low[x] == dfn[x]){
        int cnt = 0;
        while(1){
            int now = S.top();
            S.pop();
            vis[x] = 0;
            cnt++;
            if(now == x){
                break;
            }
        }
    }
}


int main(){
    cin>>n;
    for(int i = 1; i <= n ; i++){
        int x;
        cin>>x;
        E[i].push_back(x);
    }

    for(int i = 1; i <= n ;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }

    cout<<ans<<endl;

    return 0;
}
