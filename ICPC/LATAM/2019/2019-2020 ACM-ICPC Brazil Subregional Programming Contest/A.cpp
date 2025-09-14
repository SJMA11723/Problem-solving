/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))
#define set_bit(n, i) n |= (1 << (i));

using namespace std;

struct circle{
    int h, k, r;
};

bool intersection(int a, int b, circle arr[]){
    int dx = arr[a].h - arr[b].h;
    int dy = arr[a].k - arr[b].k;
    return dx * dx + dy * dy <= (arr[a].r + arr[b].r) * (arr[a].r + arr[b].r);
}

int dfs(int u, vector<int> graph[], bool vis[], int mask[]){
    if(vis[u]) return 0;
    vis[u] = true;
    int res = mask[u];
    for(int v : graph[u]) res |= dfs(v, graph, vis, mask);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n, k; cin >> m >> n >> k;
    int mask[k] = {}; /// LRDU
    vector<int> graph[k];
    circle arr[k];
    bool ok = true;
    for(int i = 0; i < k; ++i){
        int h, k, r; cin >> h >> k >> r;
        if(h - r <= 0) set_bit(mask[i], 0);
        if(h + r >= m) set_bit(mask[i], 1);
        if(k - r <= 0) set_bit(mask[i], 2);
        if(k + r >= n) set_bit(mask[i], 3);

        arr[i] = {h, k, r};

        for(int j = 0; j < i; ++j){
            if(intersection(i, j, arr)){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    if(!ok){
        cout << "N\n";
        return 0;
    }

    bool vis[k] = {};
    for(int i = 0; i < k; ++i){
        int sides = dfs(i, graph, vis, mask);
        if(is_on(sides, 0) && is_on(sides, 1)) ok = false;
        if(is_on(sides, 2) && is_on(sides, 3)) ok = false;
        if(is_on(sides, 0) && is_on(sides, 2)) ok = false;
        if(is_on(sides, 1) && is_on(sides, 3)) ok = false;
    }

    cout << (ok ? "S\n" : "N\n");
}
