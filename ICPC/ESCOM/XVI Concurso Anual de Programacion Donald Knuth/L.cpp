#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

vector<char> vis(MAXN), color(MAXN);
vector<int> graph[MAXN];

bool dfs(int u){
    int k; cin >> k;
    while(k--){
        int v; cin >> v; v--;
        if(!vis[u]) graph[u].push_back(v);
    }
    vis[u] = true;

    bool res = true;

    for(int v : graph[u]){
        if(vis[v]){
            if(color[u] == color[v]){
                res = false;
                break;
            }
            continue;
        }
        cout << "M " << v + 1 << endl;
        color[v] = !color[u];
        res &= dfs(v);

        if(!res) break;

        cout << "M " << u + 1 << endl;

        cin >> k;
        while(k--){
            int v; cin >> v;
        }
    }

    return res;
}

int main(){
    color[0] = 0;
    if(dfs(0)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
