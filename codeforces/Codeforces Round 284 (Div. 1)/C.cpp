/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 32767;

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR"; exit(0);}}
    const static bool SCALING = true;

    bool sorted = false;
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
        adj[u].push_back({v, (short)adj[v].size(), cap, 0, cap + (is_directed ? 0 : cap)});
        adj[v].push_back({u, (short)adj[u].size() - 1, is_directed ? 0 : cap, 0, cap + (is_directed ? 0 : cap)});
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

    T dfs(short u, T flow){ /// Encuentra camino, bloquea aristas
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
        //mysort();
        int64_t flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                fill(ptr, ptr + V, 0);
                while(T pushed = dfs(s, INF)) flow += pushed; /// Bloquear flujo
            }
        }
        return flow;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int arr[n], act_node = 1;
    vector<pair<int, int>> nodes[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        int tmp = arr[i];
        for(int p = 2; p * p <= tmp && tmp > 1; ++p){
            while(tmp % p == 0){
                tmp /= p;
                nodes[i].push_back({p, act_node++});
            }
        }
        if(tmp > 1) nodes[i].push_back({tmp, act_node++});
    }

    //cout << "Tam: " << act_node + 1 << '\n';
    dinic<int> MF(act_node + 1);
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        if(a % 2) swap(a, b);

        for(auto [p1, u] : nodes[a]){
            for(auto [p2, v] : nodes[b]){
                if(p1 == p2){
                    MF.add_edge(u, v, 1);
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(auto [p, u] : nodes[i])
            if(i % 2) MF.add_edge(u, act_node, 1);
            else MF.add_edge(0, u, 1);
    }

    /*for(int i = 0; i < graph.size(); ++i){
        cout << i << ": ";
        for(auto [v, c] : graph[i]) cout << '{' << v << ", " << c << "} ";
        cout << '\n';
    }*/

    cout << MF.get_max_flow(0, act_node) << '\n';
}
