/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = (1 << 15) - 1;

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR"; exit(0);}}

    short s;
    short t;
    short V;
    const T INF = numeric_limits<T>::max();
    vector<T> p;

    struct edge{
        short to, rev;
        T cap, flow, mcap, w;
        bool operator<(const edge &b)const{return mcap > b.mcap;}
    };

    vector<edge> adj[MAXV];

    void add_edge(short u, short v, T cap, T w, bool is_directed = true){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].push_back({v, adj[v].size(), cap, 0, cap + add, w});
        adj[v].push_back({u, (short)adj[u].size() - 1, add, 0, cap + add, -w});
    }

    struct pos{
        short from;
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

    pair<T, T> dijkstra(const T MAX_FLOW){
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

        T flow = MAX_FLOW;
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

    pair<T, T> get_max_flow(short source, short sink, const T MAX_FLOW = 1e8){
        s = source;
        t = sink;
        p = bellman_ford();
        T flow = 0, cost = 0;
        while(flow < MAX_FLOW){
            pair<T, T> pushed = dijkstra(MAX_FLOW - flow);
            if(!pushed.first) break;
            flow += pushed.first;
            cost += pushed.second;
        }
        return {flow, cost};
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n;
    dinic<int> MF(2 * (n + 1));
    for(int i = 0; i < n; ++i){
        MF.add_edge(2 * n, i, 1, 0);
        MF.add_edge(i + n, 2 * n + 1, 1, 0);
        for(int j = 0; j < n; ++j){
            int c; cin >> c;
            MF.add_edge(i, j + n, 1, c);
        }
    }

    pair<int, int> ans = MF.get_max_flow(2 * n, 2 * n + 1);
    cout << ans.second << '\n';
    for(int i = 0; i < n; ++i){
        for(auto &e : MF.adj[i])
        if(e.cap == e.flow && e.cap > 0){
            cout << i + 1 << ' ' << e.to + 1 - n << '\n';
            break;
        }
    }
}
