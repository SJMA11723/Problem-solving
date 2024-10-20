#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> P, RA;

    dsu(int n){
        RA.resize(n, 1);
        P.resize(n);
        iota(P.begin(), P.end(), 0);
    }

    int root(int x){
        return x == P[x] ? x : P[x] = root(P[x]);
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(RA[y] < RA[x]) swap(x, y);
        RA[y] += RA[x];
        P[x] =  y;
    }
};

struct edge{
    int from, to, i;
};

int detect_bridges(int u, vector<edge> graph[], int t_in[], bool vis[], bool is_bridge[], int &t, int p = -1){
    t_in[u] = t++;
    vis[u] = true;

    //cout << "Llega " << u + 1 << "\n";

    int min_back_edge = INT_MAX;
    int min_child_back_edge = INT_MAX;

    for(edge &e : graph[u]){
        if(vis[e.to]){
            if(e.to != p) min_back_edge = min(min_back_edge, t_in[e.to]);
            continue;
        }

        int min_child_back_edge = detect_bridges(e.to, graph, t_in, vis, is_bridge, t, u);

        if(min_child_back_edge > t_in[u]) is_bridge[e.i] = true;
        min_back_edge = min(min_back_edge, min_child_back_edge);
    }
    return min_back_edge;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c, q; cin >> r >> c >> q;
    while(r && c && q){
        vector<edge> graph[r];
        vector<edge> edges;
        for(int i = 0; i < c; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back({a, b, i});
            graph[b].push_back({b, a, i});
            edges.push_back({a, b, i});
        }

        bool vis[r] = {};
        bool is_bridge[c] = {};
        int t_in[r] = {};
        int t = 1;
        detect_bridges(0, graph, t_in, vis, is_bridge, t);

        dsu mset(r);

        for(edge &e : edges)
            if(is_bridge[e.i]) mset.join(e.from, e.to);

        while(q--){
            int a, b; cin >> a >> b;
            a--, b--;

            cout << (mset.root(a) == mset.root(b) ? "Y\n" : "N\n");
        }
        cout << "-\n";
        cin >> r >> c >> q;
    }
}
