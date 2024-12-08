/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 32767; /// 2^15 - 1

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR"; exit(0);}}
    const static bool SCALING = false;

    bool sorted = true;
    short s;
    short t;
    short V;
    int lim = 1; /// Para escalado
    const T INF = numeric_limits<T>::max();
    short level[MAXV]; /// distancia desde s
    short ptr[MAXV]; /// arista por la que va explorando

    struct edge{
        short to, rev;
        T cap, flow, mcap;
        bool operator<(const edge &b)const{return mcap > b.mcap;}
    };

    vector<edge> adj[MAXV];
    vector<short> adj_current[MAXV]; /// aristas del grafo de nivel

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

    bool bfs(){ /// Crea grafo de nivel
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

    T dfs(short u, T flow, vector<int> &S, bool save = false){ /// Encuentra camino, bloquea aristas
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

    T get_max_flow(short source, short sink){
        s = source;
        t = sink;
        mysort();
        vector<int> S;
        T flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF, S)) flow += pushed; /// Bloquear flujo
            }
        }
        return flow;
    }

    vector<pair<int, int>> get_sat_edges(){
        vector<pair<int, int>> res;
        for(int u = 0; u < V; ++u){
            if(u == s || u == t) continue;
            for(edge &e : adj[u]){
                if(e.to == t || !e.cap || e.cap > e.flow) continue;
                res.push_back({u, e.to});
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
    bool mat[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c; cin >> c;
            mat[i][j] = c - '0';
        }
    }

    dinic<int> MF(2 * m + 2);
    for(int i = 0; i < m; ++i){
        MF.add_edge(2 * m, i + m, 1);
        MF.add_edge(i, 2 * m + 1, 1);
        for(int j = i + 1; j < m; ++j){
            char state = 0;
            bool ok = true;
            for(int k = 0; k < n; ++k){
                if(mat[k][i] == mat[k][j]) continue;
                if(state){
                    if((state == 1 && mat[k][i] <= mat[k][j]) || (state == -1 && mat[k][i] > mat[k][j])){
                        ok = false;
                        break;
                    }
                } else if(mat[k][i] >= mat[k][j]) state = 1;
                else state = -1;
            }

            if(!ok) continue;

            if(state == -1) MF.add_edge(j + m, i, 1);
            else MF.add_edge(i + m, j, 1);
        }
    }

    cout << m - MF.get_max_flow(2 * m, 2 * m + 1) << '\n';
    vector<pair<int, int>> sat_edges = MF.get_sat_edges();
    int nxt[m];
    fill(nxt, nxt + m, -1);
    bool no_first[m] = {};
    for(auto &[u, v] : sat_edges){
        if(v >= m) v -= m;
        if(u >= m) u -= m;
        nxt[u] = v;
        no_first[v] = 1;
    }

    vector<vector<int>> groups;
    int access_group[m], level_access[m];
    for(int i = 0; i < m; ++i){
        if(no_first[i]) continue;
        int u = i;
        groups.push_back({});
        while(u != -1){
            groups.back().push_back(u);
            access_group[u] = groups.size();
            level_access[u] = groups.back().size() + 1;
            u = nxt[u];
        }
    }

    for(int i = 0; i < m; ++i) cout << access_group[i] << " \n"[i + 1 == m];
    for(int i = 0; i < m; ++i) cout << level_access[i] << " \n"[i + 1 == m];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < groups.size(); ++j){
            int level = 1;
            for(int k = 0; k < groups[j].size(); ++k){
                int doc = groups[j][k];
                if(mat[i][doc]) level = k + 2;
            }
            cout << level << " \n"[j + 1 == groups.size()];
        }
    }
}
