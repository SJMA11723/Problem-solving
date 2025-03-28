/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 6002;

template<class T = int64_t> struct mcmf{
    mcmf(short V, short N){this->V = V, this->N = N; if(V > MAXV){cout << "ERROR"; exit(0);}}

    short s;
    short t;
    short V, N;
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

    /// si la red inicial es un DAG, podemos hacer este caculo con dp en O(v + e)
    void compute_potentials(){
        p.resize(V, INF);
        p[s] = 0;
        for(edge &e : adj[s])
            if(e.cap > 0) p[e.to] = min(p[e.to], p[s] + e.w);
        for(int u = 0; u < N; ++u){
            for(edge &e : adj[u])
                if(e.cap > 0) p[e.to] = min(p[e.to], p[u] + e.w);

            for(edge &e : adj[u + N])
                if(e.cap > 0) p[e.to] = min(p[e.to], p[u + N] + e.w);
        }

        //cout << "Potenciales: ";
        //for(int i = 0; i < V; ++i) cout << p[i] << " \n"[i + 1 == V];
        //cout << endl;
    }

    pair<T, T> dijkstra(const T MAX_FLOW){
        vector<T> d(V, INF);
        vector<int> P(V, -1);
        vector<int> P_e(V, -1);
        vector<bool> vis(V);

        priority_queue<pos> q;
        q.push({s, 0});
        d[s] = 0;

        while(q.size()){
            pos act = q.top();
            q.pop();
            if(vis[act.from]) continue;
            vis[act.from] = true;
            //cout << "MAXF: " << MAX_FLOW << ' ' << " llega " << act.from << endl;

            for(int j = 0; j < adj[act.from].size(); ++j){
                edge &e = adj[act.from][j];

                if(e.cap - e.flow <= 0 || vis[e.to]) continue;

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
        compute_potentials();
        //cout << "Potenciales calculados" << endl;
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
    int n; cin >> n;
    int arr[n];
    mcmf<int> MF(2 * n + 2, n);
    int s = 2 * n, t = 2 * n + 1;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        //arr[i] = 1;
        MF.add_edge(s, i, 1, 0);
        MF.add_edge(i + n, t, 1, 0);
        MF.add_edge(i, i + n, 1, -1);
        for(int j = 0; j < i; ++j){
            if(abs(arr[i] - arr[j]) == 1 || arr[i] % 7 == arr[j] % 7){
                MF.add_edge(j + n, i, 1, 0);
            }
        }
    }
    int paths, ans;
    tie(paths, ans) = MF.get_max_flow(2 * n, 2 * n + 1, 4);
    //paths = n - paths;
    cout << abs(ans) << '\n';
}
