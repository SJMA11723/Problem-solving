/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>


using namespace std;

void dfs(int node, vector<int> graph[], bool vis[], vector<int> &topo_ord){
    if(vis[node]) return;
    vis[node] = true;

    for(int v : graph[node]) dfs(v, graph, vis, topo_ord);
    topo_ord.push_back(node);
}

void assign_scc(int node, vector<int> graph[], bool vis[], int scc[], const int id){
    if(vis[node]) return;
    vis[node] = true;
    scc[node] = id;

    for(int v : graph[node]) assign_scc(v, graph, vis, scc, id);
}

int kosajaru(int n, vector<int> graph[], vector<int> inv_graph[], int scc[], vector<int> &topo_ord){
    bool vis[n] = {};
    for(int i = 0; i < n; ++i) dfs(i, graph, vis, topo_ord);
    reverse(topo_ord.begin(), topo_ord.end());
    memset(vis, 0, sizeof(vis));
    int id = 0;
    for(int u : topo_ord) if(!vis[u]) assign_scc(u, inv_graph, vis, scc, id++);
    return id;
}

void build_scc_graph(int &n, vector<int> graph[], vector<int> inv_graph[], int a[], vector<vector<int>> &scc_graph, vector<int> &A){
    int scc[n];
    vector<int> topo_ord, idx_topo_ord;
    int n_scc = kosajaru(n, graph, inv_graph, scc, topo_ord);
    idx_topo_ord.resize(topo_ord.size());
    for(int i = 0; i < topo_ord.size(); ++i) idx_topo_ord[ topo_ord[i] ] = i;

    scc_graph.resize(n_scc);
    A.resize(n_scc);

    for(int u = 0; u < n; ++u){
        for(int v : graph[u])
            if(scc[u] != scc[v])
                scc_graph[scc[u]].push_back(scc[v]);
        A[ scc[u] ] += a[u];
    }

    for(int u = 0; u < n_scc; ++u){
        sort(scc_graph[u].begin(), scc_graph[u].end());
        auto it = unique(scc_graph[u].begin(), scc_graph[u].end());
        scc_graph[u].resize(it - scc_graph[u].begin());
    }

    n = n_scc;
}

const int MAXV = 32767; /// 2^15 - 1

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR"; exit(0);}}
    const static bool SCALING = false;

    bool sorted = false;
    short s;
    short t;
    short V;
    int lim = 1; /// Para escalado
    const T INF = numeric_limits<T>::max();
    short level[MAXV]; /// distancia desde s
    short ptr[MAXV]; /// arista por la que va explorando
    vector<T> p;

    struct edge{
        short to, rev;
        T cap, flow, mcap, w;
        bool operator<(const edge &b)const{return mcap > b.mcap;}
    };

    vector<edge> adj[MAXV];

    void add_edge(int u, int v, T cap, T w, bool is_directed = true){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].push_back({v, adj[v].size(), cap, 0, cap + add, w});
        adj[v].push_back({u, (short)adj[u].size() - 1, add, 0, cap + add, -w});
    }

    struct pos{
        int from;
        T c;
        const bool operator<(const pos &b)const{
            return c > b.c;
        }
    };

    vector<T> bellman_ford(){
        vector<T> d(V);
        for(int i = 0; i < V - 1; ++i){
            for(int u = 0; u < V; ++u){
                for(edge &e : adj[u]){
                    if(d[e.to] > d[u] + e.w && e.cap > 0){
                        d[e.to] = d[u] + e.w;
                    }
                }
            }
        }
        return d;
    }

    pair<T, T> dijkstra(){
        vector<T> d(V, INF);
        vector<int> P(V, -1);
        vector<int> P_e(V, -1);

        priority_queue<pos> q;
        q.push({s, 0});
        d[s] = 0;

        while(q.size()){
            pos act = q.top();
            q.pop();
            if(act.c != d[act.from]) continue;

            for(int j = 0; j < adj[act.from].size(); ++j){
                edge &e = adj[act.from][j];

                if(e.cap - e.flow <= 0) continue;

                T _w = e.w + p[act.from] - p[e.to];
                if(d[e.to] <= d[act.from] + _w) continue;

                d[e.to] = d[act.from] + _w;
                q.push(pos{e.to, d[e.to]});
                P[e.to] = act.from;
                P_e[e.to] = j;
            }
        }

        for(int i = 0; i < V; ++i) if(d[i] < INF) d[i] += -p[s] + p[i];
        for(int i = 0; i < V; ++i) if(d[i] < INF) p[i] = d[i];

        if(P[t] == -1) return {0, 0};

        T flow = INF;
        int cur_node = t;
        while(cur_node != s){
            flow = min(flow, adj[ P[cur_node] ][ P_e[cur_node] ].cap - adj[ P[cur_node] ][ P_e[cur_node] ].flow);
            cur_node = P[cur_node];
        }

        T new_cost = 0;
        cur_node = t;
        while(cur_node != s){
            adj[ P[cur_node] ][ P_e[cur_node] ].flow += flow;
            new_cost += adj[ P[cur_node] ][ P_e[cur_node] ].w * flow;
            adj[cur_node][adj[ P[cur_node] ][ P_e[cur_node] ].rev ].flow -= flow;
            cur_node = P[cur_node];
        }

        return {flow, new_cost};
    }

    pair<T, T> get_max_flow(short source, short sink){
        s = source;
        t = sink;
        p = bellman_ford();
        T flow = 0, cost = 0;
        while(true){
            pair<T, T> pushed = dijkstra();
            if(!pushed.first) break;
            flow += pushed.first; /// Bloquear flujo
            cost += pushed.second;
        }
        return {flow, cost};
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> graph[n], inv_graph[n];
        int a[n];
        for(int &x : a) cin >> x;
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            inv_graph[b].push_back(a);
        }

        vector<vector<int>> scc_graph;
        vector<int> A;
        build_scc_graph(n, graph, inv_graph, a, scc_graph, A);
        /// se reasigna n a #scc

        dinic MF(3 * n + 4);

        const int INF = 1e8;
        /// u -> u_in
        /// u + n -> u_out
        /// u + 2n -> u_cnt
        /// 3n -> s
        /// 3n + 1 -> t
        /// 3n + 2 -> s'
        /// 3n + 3 -> t'
        MF.add_edge(3 * n + 1, 3 * n, INF, 0); /// t -> s
        for(int u = 0; u < n; ++u){
            MF.add_edge(u, u + n, INF - 1, 0); /// u_in -> u_out
            MF.add_edge(u + n, 3 * n + 1, INF, 0); /// u_out -> t
            MF.add_edge(u + 2 * n, u, 1, 1); /// u_cnt -> u_in
            MF.add_edge(u + 2 * n, u + n, A[u], 0); /// u_cnt -> u_out
            MF.add_edge(3 * n, u + 2 * n, A[u], 0); /// s -> u_cnt
            MF.add_edge(3 * n + 2, u + n, 1, 0); /// s' -> u_out
            MF.add_edge(u, 3 * n + 3, 1, 0); /// u_in -> t'

            for(int v : scc_graph[u]) MF.add_edge(u + n, v, INF, 0);
        }

        int f, c;
        tie(f, c) = MF.get_max_flow(3 * n + 2, 3 * n + 3);

        if(f < n) cout << "-1\n";
        else cout << c << '\n';
    }
}
