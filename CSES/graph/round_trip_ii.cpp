/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100'001

using namespace std;

char vis[MAXN];
vector<int> graph[MAXN];
int P[MAXN];

void dfs(int node, int p, int &cycle_start, int &cycle_end){
    //cout << "Llega " << node << '\n';
    if(vis[node] == 2) return;
    if(vis[node] == 1){
        cycle_start = node;
        cycle_end = p;
        return;
    }
    vis[node] = 1;
    P[node] = p;
    //cout << "Pending " << node << '\n';

    for(int v : graph[node]){
        dfs(v, node, cycle_start, cycle_end);
        if(cycle_start) break;
    }
    vis[node] = 2;
    //cout << "Visitado " << node << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    int cycle_start = 0, cycle_end = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i] == 2) continue;
        dfs(i, 0, cycle_start, cycle_end);
        if(cycle_start) break;
    }

    if(cycle_start){
        stack<int> cycle;
        while(cycle_end != cycle_start){
            cycle.push(cycle_end);
            cycle_end = P[cycle_end];
        }
        cout << cycle.size() + 2 << '\n' << cycle_start << ' ';
        while(cycle.size()){
            cout << cycle.top() << ' ';
            cycle.pop();
        }
        cout << cycle_start << '\n';
        cout << '\n';
    } else cout << "IMPOSSIBLE\n";
}
