#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> P, RA;
    int cnt_comp;
    dsu(int n){
        P.resize(n);
        RA.resize(n, 1);
        iota(P.begin(), P.end(), 0);
        cnt_comp = n;
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y){
            return;
        }

        if(RA[y] < RA[x]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        cnt_comp--;
    }
};

int dfs(int u, vector<int> graph[], bool vis[], int depth[], bool articulation_point[], int p = -1, int d = 0){
    vis[u] = true;
    depth[u] = d;
    int min_back_depth = INT_MAX;
    int min_back_depth_child = INT_MAX;

    int cnt_child = 0;
    for(int v : graph[u]){
        if(vis[v]){
            if(v != p) min_back_depth = min(min_back_depth, depth[v]);
            continue;
        }

        cnt_child++;
        min_back_depth_child = min(min_back_depth_child, dfs(v, graph, vis, depth, articulation_point, u, d + 1));
        min_back_depth = min(min_back_depth, min_back_depth_child);
    }

    if(!u) articulation_point[u] = cnt_child > 1;
    else if(min_back_depth_child >= depth[u] && cnt_child > 0) articulation_point[u] = true;

    return min_back_depth;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int deg[n] = {};
    vector<int> graph[n];
    dsu mset(n);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        deg[a]++, deg[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
        mset.join(a, b);
    }

    if(mset.cnt_comp > 2){
        cout << "no\n";
        return 0;
    } else if(mset.cnt_comp == 2){
        int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
        for(int i = 0; i < n; ++i){
            if(deg[i] == 0) cnt_0++;
            else if(deg[i] == 1) cnt_1++;
            else if(deg[i] == 2) cnt_2++;
        }

        cout << ((cnt_0 == 1 && cnt_1 == 2 && cnt_2 == n - 3) ? "yes\n" : "no\n");

        return 0;
    }

    bool articulation_point[n] = {};
    int depth[n] = {};
    bool vis[n] = {};
    dfs(0, graph, vis, depth, articulation_point);

    int cnt[n] = {};
    for(int i = 0; i < n; ++i) cnt[deg[i]]++;

    bool ok = false;
    for(int i = 0; i < n; ++i){
        if(articulation_point[i]) continue;

        cnt[deg[i]]--;
        for(int v : graph[i]){
            cnt[deg[v]]--;
            deg[v]--;
            cnt[deg[v]]++;
        }

        if(cnt[0] == 0 && cnt[1] == 2 && cnt[2] == n - 3) ok = true;

        cnt[deg[i]]++;
        for(int v : graph[i]){
            cnt[deg[v]]--;
            deg[v]++;
            cnt[deg[v]]++;
        }
    }
    cout << (ok ? "yes\n" : "no\n");
}
