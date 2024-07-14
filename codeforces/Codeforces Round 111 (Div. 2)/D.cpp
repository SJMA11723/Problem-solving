/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> RA, P;
    dsu(int n){
        RA.resize(n + 1);
        P.resize(n + 1);
        for(int i = 0; i < n; ++i){
            RA[i] = 1;
            P[i] = i;
        }
    }

    int root(int x){
        return (x == P[x] ? x : P[x] = root(P[x]));
    }

    void join(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(RA[x] > RA[y]) swap(x, y);
        RA[y] += RA[x];
        P[x] = y;
        return;
    }
};

struct edge{
    int from, to;
    int w, idx;

    bool operator<(const edge &b)const{
        return w < b.w;
    }
};

int detect_bridges(int u, vector<edge> graph[], bool vis[], char ans[], int t_in[], int t = 1, int p = -1){
    if(vis[u]) return t_in[u];

    vis[u] = true;
    t_in[u] = t;

    bool bridge = false;
    int min_back_edge = INT_MAX;
    for(edge &e : graph[u]){
        /// ignoro si es la arista de la que vengo o si me voy hacia abajo en un nodo ya visitado
        if(e.idx == p || (vis[e.to] && t_in[e.to] > t_in[u])) continue;

        int min_child_back_edge = detect_bridges(e.to, graph, vis, ans, t_in, t + 1, e.idx);

        /// back edge menos produnda llega abajo de u, entonces es puente
        if(min_child_back_edge > t_in[u]) ans[e.idx] = 2;

        min_back_edge = min(min_back_edge, min_child_back_edge);
    }

    return min_back_edge;
}

void kruskal(int n, vector<edge> &edges, char ans[]){
    sort(edges.begin(), edges.end());
    edges.push_back({-1, -1, INT_MAX, 0});

    dsu mset(n);
    int prev_w = -1;
    vector<edge> same_w;
    vector<edge> comp_graph[n];
    bool reset[n];
    bool vis[n];
    int t_in[n];

    for(edge &e : edges){
        if(e.w == prev_w){
            same_w.push_back(e);
            continue;
        }

        memset(reset, 0, sizeof(reset));
        set<int> nodes;
        for(edge &cur_e : same_w){ /// crea el grafo de componentes con las aristas del mismo peso
            ans[cur_e.idx] = 1;
            if(mset.root(cur_e.from) == mset.root(cur_e.to)){ /// si crea un ciclo entonces no aparece en algun MST
                ans[cur_e.idx] = 0;
                continue;
            }

            int from = mset.root(cur_e.from);
            int to = mset.root(cur_e.to);
            nodes.insert(from);
            nodes.insert(to);
            t_in[from] = INT_MAX;
            t_in[to] = INT_MAX;

            if(!reset[from]){
                comp_graph[from].clear();
                reset[from] = true;
            }
            if(!reset[to]){
                comp_graph[to].clear();
                reset[to] = true;
            }

            comp_graph[from].push_back({from, to, cur_e.w, cur_e.idx});
            comp_graph[to].push_back({to, from, cur_e.w, cur_e.idx});
        }

        memset(vis, 0, sizeof(vis));
        /// los puentes del grafo de componentes conexas aparecen en todos los MST, por que?
        for(int u : nodes) detect_bridges(u, comp_graph, vis, ans, t_in);

        for(edge &cur_e : same_w) mset.join(cur_e.from, cur_e.to);

        same_w.clear();
        prev_w = e.w;
        same_w.push_back(e);
    }
    edges.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w, i});
    }

    char ans[m];
    kruskal(n, edges, ans);

    for(int i = 0; i < m; ++i){
        if(!ans[i]) cout << "none\n";
        else if(ans[i] == 1) cout << "at least one\n";
        else cout << "any\n";
    }
}
