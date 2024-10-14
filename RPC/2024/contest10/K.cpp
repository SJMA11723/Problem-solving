#include <bits/stdc++.h>

using namespace std;

const int MAXV = (1 << 16) - 1;

template<class T = int64_t> struct dinic{
    dinic(short V){
        this->V = V;
        if(V > MAXV){
            cout << "ERROR\n";
            exit(1);
        }
    }
    const static bool SCALING = false;

    bool sorted = false;
    int s, t, V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    int level[MAXV], ptr[MAXV];

    struct edge{
        short to, rev;
        T cap, flow, mcap, w;
        bool operator<(const edge &b)const{return mcap > b.mcap;}
    };

    vector<edge> adj[MAXV];

    void add_edge(int u, int v, T cap, T w, bool is_directed = true){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].push_back({v, (int)adj[v].size(), cap, 0, cap + add, w});
        adj[v].push_back({u, (int)adj[u].size() - 1, add, 0, cap + add, -w});
    }

    struct pos{
        int from, c;
        const bool operator<(const pos &b)const{
            return c > b.c;
        }
    };

    T dijkstra(int u, int &MAXT){
        vector<int> d(V, INT_MAX);
        vector<int> P(V, -1);
        vector<int> P_e(V, -1);
        vector<char> vis(V);

        priority_queue<pos> q;
        q.push({s, 0});
        d[s] = 0;

        while(q.size()){
            pos act = q.top();
            q.pop();
            if(vis[act.from]) continue;
            vis[act.from] = true;

            for(int j = 0; j < adj[act.from].size(); ++j){
                edge &e = adj[act.from][j];

                if(e.cap == e.flow) continue;

                if(d[e.to] <= d[act.from] + e.w) continue;

                d[e.to] = d[act.from] + e.w;
                q.push(pos{e.to, d[e.to]});
                P[e.to] = act.from;
                P_e[e.to] = j;
            }
        }

//        for(int i = 0; i < V - 1; ++i){
//            for(int u = 0; u < V; ++u){
//                if(d[u] == INT_MAX) continue;
//
//                for(int j = 0; j < adj[u].size(); ++j){
//                    edge &e = adj[u][j];
//
//                    if(e.cap == e.flow) continue;
//
//                    if(d[e.to] > d[u] + e.w){
//                        d[e.to] = d[u] + e.w;
//                        P[e.to] = u;
//                        P_e[e.to] = j;
//                    }
//                }
//            }
//        }

        if(d[t] > MAXT){
            return 0;
        }

        //cout << MAXT << ' ' << d[t] << '\n';

        MAXT -= d[t];

        T flow = INF;
        int cur_node = t;
        while(cur_node != s){
            flow = min(flow, adj[ P[cur_node] ][ P_e[cur_node] ].cap - adj[ P[cur_node] ][ P_e[cur_node] ].flow);
            cur_node = P[cur_node];
        }

        cur_node = t;
        while(cur_node != s){
            adj[ P[cur_node] ][ P_e[cur_node] ].flow += flow;
            adj[cur_node][adj[ P[cur_node] ][ P_e[cur_node] ].rev ].flow -= flow;
            cur_node = P[cur_node];
        }

        return flow;
    }

    int64_t get_max_flow(int source, int sink, int MAXT){
        s = source;
        t = sink;
        //mysort();
        int64_t flow = 0;
        //for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            //while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dijkstra(s, MAXT)) flow += pushed;
            //    break;
            //}
        //}
        //cout << MAXT << '\n';
        return flow;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, t; cin >> n >> p >> t;
    dinic<int> MF(n + p + 2);
    for(int i = 1; i <= n; ++i){
        MF.add_edge(0, i, 1, 0);
        for(int j = 1; j <= p; ++j){
            int time; cin >> time;
            if(time) MF.add_edge(i, j + n, 1, time);
        }
    }

    for(int i = 1; i <= p; ++i) MF.add_edge(i + n, n + p + 1, 1, 0);

    cout << MF.get_max_flow(0, n + p + 1, t) << '\n';
}
