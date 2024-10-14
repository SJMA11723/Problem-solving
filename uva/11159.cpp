/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = (1 << 15) - 1;

template<class T = int64_t> struct dinic{
    dinic(short V){
        this->V = V;
        if(V > MAXV){
            cout << "ERROR\n";
            exit(1);
        }
    }
    const static bool SCALING = false;

    bool sorted = true;
    short s, t, V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    short level[MAXV], ptr[MAXV];

    struct edge{
        short to, rev;
        T cap, flow, mcap;
        const bool operator<(const edge &b)const{return mcap > b.mcap;}
    };

    vector<edge> adj[MAXV];
    vector<int> adj_current[MAXV];
    void add_edge(short u, short v, T cap, bool is_directed = true){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].push_back({v, (short)adj[v].size(), cap, 0, cap + add});
        adj[v].push_back({u, (short)(adj[u].size() - 1), add, 0, cap + add});
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

    int64_t get_max_flow(int source, int sink){
        s = source;
        t = sink;
        int64_t flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF)) flow += pushed;
            }
        }
        return flow;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int n, m;
        cin >> n;
        vector<int> A(n);
        for(int &x : A) cin >> x;

        cin >> m;
        vector<int> B(m);
        for(int &x : B) cin >> x;

        dinic<int> MF(n + m + 2);
        for(int i = 1; i <= n; ++i){
            MF.add_edge(0, i, 1);
            for(int j = 1; j <= m; ++j){
                if(!B[j - 1] || (A[i - 1] && B[j - 1] % A[i - 1] == 0))
                    MF.add_edge(i, j + n, 1);
            }
        }

        for(int i = 1; i <= m; ++i) MF.add_edge(i + n, n + m + 1, 1);

        cout << "Case " << tt << ": " << MF.get_max_flow(0, n + m + 1) << '\n';
    }
}
