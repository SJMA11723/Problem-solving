/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = (1 << 15) - 1;

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR\n"; exit(1);}}
    const static bool SCALING = false;

    bool sorted = false;
    short s, t, V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    short level[MAXV], ptr[MAXV];

    struct edge{
        int to, rev;
        T cap, flow, mcap;
        bool is_rev;
        bool operator<(const edge &b){return mcap > b.mcap;}
    };

    vector<edge> adj[MAXV];
    vector<short> adj_current[MAXV];
    void add_edge(int u, int v, T cap, bool is_directed = true){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].push_back({v, adj[v].size(), cap, 0, cap + add, 0});
        adj[v].push_back({u, (short)adj[u].size() - 1, add, 0, cap + add, 1});
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
            for(int i = 0; i < (int)adj[u].size(); ++i){
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

    T dfs(short u, T flow){
        if(u == t) return flow;
        for(; ptr[u] < adj_current[u].size(); ++ptr[u]){
            edge &e = adj[u][adj_current[u][ptr[u]]];
            if(T pushed = dfs(e.to, min(flow, e.cap - e.flow))){
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                if(e.cap - e.flow < lim) ptr[u]++;
                return pushed;
            }
        }
        return 0;
    }

    int64_t get_max_flow(short source, short sink){
        s = source;
        t = sink;
        mysort();
        int64_t flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF)) flow += pushed;
            }
        }
        return flow;
    }

    vector<pair<int, int>> get_sat_edges(){
        vector<pair<int, int>> res;
        for(int i = 0; i < V; ++i){
            for(edge &e : adj[i]){
                if(e.is_rev || i == s || i == t || e.to == s || e.to == t || e.cap > e.flow) continue;
                res.push_back({e.to, i});
            }
        }
        return res;
    }
};

struct point{
    int x, y;

    point operator-(const point &b){
        return point{x - b.x, y - b.y};
    }
};

long double _norm(const point &p){
    return sqrt(p.x * p.x + p.y * p.y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;

        dinic<int> MF(n + m + 1);
        point bob[n];
        for(int i = 0; i < n; ++i){
            point &p = bob[i];
            cin >> p.x >> p.y;
            if(i + 1 < n) MF.add_edge(i + 1 + m, n + m, 1);
        }

        point ralph[m];
        for(int i = 0; i < m; ++i){
            point &p = ralph[i];
            cin >> p.x >> p.y;

            MF.add_edge(0, i + 1, 1);

            for(int j = 1; j < n; ++j)
                if(_norm(ralph[i] - bob[j - 1]) + _norm(ralph[i] - bob[j]) <= 2 * _norm(bob[j] - bob[j - 1]))
                    MF.add_edge(i + 1, j + m, 1);
        }

        cout << MF.get_max_flow(0, n + m) + n <<'\n';
        vector<pair<int, int>> edges = MF.get_sat_edges();
        sort(edges.begin(), edges.end());

        int last = -1;
        for(pair<int, int> &e : edges){
            int from, to;
            tie(from, to) = e;
            from--, to--;
            from -= m;
            while(++last < from) cout << bob[last].x << ' ' << bob[last].y << ' ';
            cout << bob[from].x << ' ' << bob[from].y << ' ';
            cout << ralph[to].x << ' ' << ralph[to].y << " \n"[last == n];
        }
        while(++last < n) cout << bob[last].x << ' ' << bob[last].y << " \n"[last + 1 == n];
        if(t) cout << '\n';
    }
}
