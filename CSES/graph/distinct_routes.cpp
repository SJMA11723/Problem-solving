/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = (1 << 15) - 1;

template<class T = int64_t> struct dinic{
    dinic(short V):V(V){if(V > MAXV){cout << "ERROR\n"; exit(0);}}
    const static bool SCALING = false;

    bool sorted = false;
    short s, t, V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    short level[MAXV];
    short ptr[MAXV];

    struct edge{
        short to, rev;
        T cap, flow, mcap;
        bool operator<(const edge &b)const{return mcap > b.mcap;}
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
            int u = q.front(); q.pop();
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

    T get_max_flow(short source, short sink){
        s = source;
        t = sink;
        mysort();
        T flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF)) flow += pushed;
            }
        }
        return flow;
    }

    vector<vector<int>> get_sat_paths(){
        vector<vector<int>> res;

        bfs();

        queue<vector<int>> q;
        q.push({s});
        memset(ptr, 0, sizeof(ptr));
        while(q.size()){
            vector<int> P = q.front(); q.pop();
            int u = P.back();

            //cout << "Llega " << u + 1 << '\n';

            if(u == t){
                res.push_back(P);
                //cout << "CAMINO\n";
                continue;
            }

            for(; ptr[u] < adj[u].size(); ++ptr[u]){
                edge &e = adj[u][ptr[u]];
                //cout << "Intenta " << e.to + 1 << '\n';
                if(e.cap && e.cap == e.flow){
                    P.push_back(e.to);
                    q.push(P);
                    P.pop_back();
                    //cout << "Agrega " << e.to + 1 << '\n';
                    if(u != s){
                        ptr[u]++;
                        break;
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;

    dinic<int> FF(n);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        FF.add_edge(a, b, 1);
    }

    cout << FF.get_max_flow(0, n - 1) << '\n';

    vector<vector<int>> ans = FF.get_sat_paths();

    for(vector<int> &P : ans){
        cout << P.size() << '\n';
        for(int i = 0; i < P.size(); ++i) cout << P[i] + 1 << " \n"[i + 1 == P.size()];
    }
}
