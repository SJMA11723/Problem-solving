#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define OUT(x) ((x) + nk)

typedef long long ll;

const int MAXV = (1 << 15) - 1;

template<class T = ll> struct dinic{
    dinic(int V){
        this->V = V;
    }
    const static bool SCALING = false;
    bool sorted = true;
    int s, t, V;
    ll lim = 1;
    const T INF = numeric_limits<T>::max();
    int level[MAXV];
    int ptr[MAXV];
    
    struct edge{
        int to, rev;
        T cap, flow, mcap;
        bool operator<(const edge &b)const{
            return mcap > b.mcap;
        }
    };

    vector<edge> adj[MAXV];
    vector<int> adj_cur[MAXV];

    void add_edge(int u, int v, T cap, bool is_directed = 1){
        if(u == v) return;

        T add = (is_directed ? 0 : cap);

        adj[u].push_back({v, adj[v].size(), cap, 0, cap + add});
        adj[v].push_back({u, (int)adj[u].size() - 1, add, 0, cap + add});
    }

    void mysort(){
        if(sorted) return;
        sorted = 1;

        for(int i = 0; i < V; ++i){
            sort(all(adj[i]));
            for(int j = 0; j < sz(adj[i]); ++j){
                adj[ adj[i][j].to ][ adj[i][j].rev ].rev = j;
            }
        }
    }

    bool bfs(){
        for(int i = 0; i < V; ++i){
            adj_cur[i].clear();
            adj_cur[i].reserve(sz(adj[i]));
        }

        queue<int> q;
        q.push(s);
        fill(level, level + V, -1);
        level[s] = 0;
        while(sz(q)){
            int u = q.front(); q.pop();
            if(u == t) return 1;
            for(int i = 0; i < sz(adj[u]); ++i){
                edge &e = adj[u][i];
                if(e.mcap < lim) break;
                
                if(level[e.to] == -1 && e.cap - e.flow >= lim){
                    level[e.to] = level[u] + 1;
                    adj_cur[u].push_back(i);
                    q.push(e.to);
                } else if(level[e.to] ==level[u] + 1 && e.cap - e.flow >= lim){
                    adj_cur[u].push_back(i);
                }
            }
        }
        return 0;
    }

    T dfs(int u, T flow){
        if(u == t) return flow;
        for(; ptr[u] < sz(adj_cur[u]); ++ptr[u]){
            edge &e = adj[u][ adj_cur[u][ptr[u]] ];

            if(T pushed = dfs(e.to, min(flow, e.cap - e.flow))){
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                if(e.cap - e.flow < lim) ptr[u]++;
                return pushed;
            }
        }
        return 0;
    }

    ll get_max_flow(int source, int sink){
        s = source, t = sink;
        mysort();
        ll flow = 0;
        lim = SCALING ? (1ll << 31) : 1;
        for(; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF)){
                    flow += pushed;
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
    int n, k, m;
    cin >> n >> k >> m;
    int N = 2 * n * k + 1 + 2;
    int nk = n * k;
    int S = 2 * n * k;
    int s = S + 1;
    int t = s + 1;
    dinic MF(N);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            int x; cin >> x;
            int u = i * k + j;
            MF.add_edge(u, OUT(u), x);
        }
    }

    for(int i = 0; i < m; ++i){
        int f, u, v; cin >> f >> u >> v;
        f--, u--, v--;
        u = f * k + u;
        v = (f + 1) * k + v;

        MF.add_edge(OUT(u), v, 2e9);
    }
    MF.add_edge(S, s, 2e9);
    for(int i = 0; i < k; ++i){
        MF.add_edge(s, i, 2e9);
    }

    int ans[n] = {};
    for(int i = n - 1; 0 <= i; --i){
        for(int j = 0; j < k; ++j){
            MF.add_edge(OUT(i * k + j), t, 2e9);
        }

        ans[i] = MF.get_max_flow(S, t);
        if(i + 1 < n) ans[i] += ans[i + 1];
    }

    for(int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i + 1 == n];
}