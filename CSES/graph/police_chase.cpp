/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int64_t w;
    int64_t c;
    int64_t f;
};

class ford_fulkerson{
public:
    ford_fulkerson(vector<vector<edge>> &graph): graph(graph){}

    int64_t get_max_flow(int s, int t){
        init();
        int64_t f = 0;
        while(find_and_update(s, t, f));
        return f;
    }

    vector<int> get_st_cut(const int &s){
        bool vis[graph.size()] = {};
        vector<int> S;
        queue<int> q;
        q.push(s);
        S.push_back(s);
        vis[s] = true;

        while(q.size()){
            int u = q.front(); q.pop();

            for(int eI : edge_indexes[u]){
                if(edges[eI].c > edges[eI].f && !vis[edges[eI].to]){
                    q.push(edges[eI].to);
                    vis[edges[eI].to] = true;
                    S.push_back(edges[eI].to);
                }
            }
        }
        return S;
    }
private:
    vector<vector<edge>> graph;
    vector<edge> edges;
    vector<vector<int>> edge_indexes;

    void init(){
        edges.clear();
        edge_indexes.clear(); edge_indexes.resize(graph.size());
        for(int u = 0; u < graph.size(); ++u){
            for(edge &e : graph[u]){
                edges.push_back({u, e.to, e.w, e.c, 0});
                edges.push_back({e.to, u, -e.w, 0, 0});
                edge_indexes[u].push_back(edges.size() - 2);
                edge_indexes[e.to].push_back(edges.size() - 1);
            }
        }
    }

    bool find_and_update(int s, int t, int64_t &flow){
        queue<int> q;

        vector<pair<int, int>> from(graph.size(), make_pair(-1, -1));
        q.push(s);
        from[s] = make_pair(s, -1);
        bool found = false;
        while(q.size() && !found){
            int u = q.front(); q.pop();
            for(int eI : edge_indexes[u]){
                if(edges[eI].c > edges[eI].f && from[edges[eI].to].first == -1){
                    from[edges[eI].to] = make_pair(u, eI);
                    q.push(edges[eI].to);
                    if(edges[eI].to == t) found = true;
                }
            }
        }

        if(!found) return false;

        int64_t u_flow = LLONG_MAX;
        int current = t;
        while(current != s){
            u_flow = min(u_flow, edges[from[current].second].c - edges[from[current].second].f);
            current = from[current].first;
        }

        current = t;
        while(current != s){
            edges[from[current].second].f += u_flow;
            edges[from[current].second^1].f -= u_flow;
            current = from[current].first;
        }
        flow += u_flow;
        return true;
    }
};

const int MAXV = (1 << 15) - 1;

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR\n"; exit(0);}}
    const static bool SCALING = false;

    bool sorted = false;
    short s;
    short t;
    short V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    short level[MAXV];
    short ptr[MAXV];

    struct edge{
        short to, rev;
        T cap, flow, mcap;
        bool operator<(const edge &b)const{
            return mcap > b.mcap;
        }
    };

    vector<edge> adj[MAXV];
    vector<short> adj_current[MAXV];

    void add_edge(int u, int v, T cap, bool is_directed = true){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].push_back({v, adj[v].size(), cap, 0, cap + add});
        adj[v].push_back({u, (short)adj[u].size() - 1, add, 0, cap + add});
    }

    void mysort(){
        if(sorted) return;
        sorted = true;
        for(int i = 0; i < V; ++i){
            sort(adj[i].begin(), adj[i].end());
            for(int j = 0; j < adj[i].size(); ++j){
                adj[adj[i][j].to][adj[i][j].rev].rev = j;
            }
        }
    }

    bool bfs(){
        for(int i = 0; i < V; ++i){
            adj_current[i].clear();
            adj_current[i].reserve(adj[i].size());
        }

        queue<short> q;
        q.push(s);
        fill(level, level + V, -1);
        level[s] = 0;
        while(q.size()){
            short u = q.front(); q.pop();
            if(u == t) return true;
            for(int i = 0; i < adj[u].size(); ++i){
                edge &e = adj[u][i];

                if(e.mcap < lim) break;
                if(level[e.to] == -1 && e.cap - e.flow >= lim){
                    level[e.to] = level[u] + 1;
                    adj_current[u].push_back(i);
                    q.push(e.to);
                } else if(level[e.to] == level[u] + 1 && e.cap - e.flow >= lim){
                    adj_current[u].push_back(i);
                }
            }
        }
        return false;
    }

    T dfs(short u, T flow, vector<int> &S, bool save = false){
        if(save) S.push_back(u);
        if(u == t) return flow;
        for(; ptr[u] < adj_current[u].size(); ++ptr[u]){
            edge &e = adj[u][adj_current[u][ptr[u]]];
            if(T pushed = dfs(e.to, min(flow, e.cap - e.flow), S, save)){
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                if(e.cap - e.flow < lim) ptr[u]++;
                return pushed;
            }
        }
        return 0;
    }

    int64_t get_max_flow(int source, int sink){
        s = source;
        t = sink;
        mysort();
        vector<int> S;
        int64_t flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF, S)) flow += pushed;
            }
        }
        return flow;
    }

    vector<int> get_st_cut(const int &s){
        vector<int> S;
        memset(ptr, 0, sizeof(ptr));
        dfs(s, INF, S, true);
        return S;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    //vector<vector<edge>> graph(n);

    dinic<int> FF(n);
    vector<edge> edges;
    while(m--){
        int a, b; cin >> a >> b;
        a--, b--;
        edges.push_back({a, b});
        //graph[a].push_back({a, b, 0, 1});
        //graph[b].push_back({b, a, 0, 1});
        FF.add_edge(a, b, 1, false);
    }

    //ford_fulkerson FF(graph);

    cout << FF.get_max_flow(0, n - 1) << '\n';
    vector<int> S = FF.get_st_cut(0);
    bool ap[n] = {};
    for(int u : S) ap[u] = true;

    for(edge &e : edges)
        if(ap[e.from] && !ap[e.to]) cout << e.from + 1 << ' ' << e.to + 1 << '\n';
}
