#include<bits/stdc++.h>

using namespace std;

const int MAXV = (1 << 15) - 1;

template<class T = int64_t> struct dinic{
    dinic(short V){
        this->V = V;
        if(V > MAXV){
            cout << "ERROR\n";
            exit(0);
        }
    }
    const static bool SCALING = true;

    bool sorted = false;
    short s, t, V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    short level[MAXV], ptr[MAXV];

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
        adj[v].push_back({u, (int)adj[u].size() - 1, add, 0, cap + add});
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

            if(T pushed = dfs(e.to, min(flow, e.cap - e.flow)) ){
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
        int64_t flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF)){
                    flow += pushed;
                    if(pushed >= 1e8) return -1;
                }
            }
        }

        return flow;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    dinic MF(n + 1);
    for(int i = 0; i < n; ++i){
        string c; cin >> c;
        if(c == "*"){
            int x; cin >> x; x--;
            if(x) MF.add_edge(i, x, 1e8);
            else MF.add_edge(i, n, 1e8);
        } else {
            int cnt = stoi(c);
            while(cnt--){
                int x; cin >> x; x--;
                if(x) MF.add_edge(i, x, 1);
                else MF.add_edge(i, n, 1);
            }
        }
    }

    int64_t F = MF.get_max_flow(0, n);
    if(F == -1) cout << "*\n";
    else cout << F + 1 << '\n';
}



