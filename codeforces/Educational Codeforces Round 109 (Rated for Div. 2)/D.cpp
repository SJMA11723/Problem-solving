#/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

const int MAXV = (1 << 13) - 1;
template<class T = ll> struct mcmf{
    mcmf(short V){this->V = V;}
    short s, t, V;
    const T INF = numeric_limits<T>::max();
    vector<T> p;
    struct edge{
        short to;
        int rev;
        T cap, flow, mcap, w;
    };

    vector<edge> adj[MAXV];
    void add_edge(short u, short v, T cap, T w, bool is_directed = 1){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].pb({v, sz(adj[v]), cap, 0, cap + add, w});
        adj[v].pb({u, sz(adj[u]) - 1, add, 0, cap + add, -w});
    }
    struct pos{
        short from;
        T c;
        const bool operator<(const pos &b)const{return c > b.c;}
    };

    pair<T, T> dijkstra(const T MAX_FLOW){
        vector<T> d(V, INF);
        vi P(V, -1), P_e(V, -1);
        priority_queue<pos> q;
        q.push({s, 0});
        d[s] = 0;
        while(sz(q)){
            pos act = q.top(); q.pop();
            if(act.c != d[act.from]) continue;
            for(int j=0; j<sz(adj[act.from]); ++j){
                edge &e = adj[act.from][j];
                if(e.cap - e.flow <= 0) continue;
                //T _w = e.w+p[act.from] - p[e.to];
                T _w = e.w;
                if(d[e.to] <= d[act.from] + _w)
                    continue;
                d[e.to] = d[act.from] + _w;
                q.push(pos{e.to, d[e.to]});
                P[e.to] = act.from;
                P_e[e.to] = j;
            }
        }
        //for(int i = 0; i < V; ++i) if(d[i] < INF)
        //    d[i] += -p[s] + p[i];
        //for(int i = 0; i < V; ++i) if(d[i] < INF)
        //    p[i] = d[i];
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
    pair<T, T> get_max_flow(short source, short sink, const T MAX_FLOW = 2500){
        s = source;
        t = sink;
        T flow = 0, cost = 0;
        while(flow < MAX_FLOW){
            pair<T, T> pushed = dijkstra(MAX_FLOW - flow);
            if(!pushed.fi) break;
            flow += pushed.fi;
            cost += pushed.se;
        }
        return {flow, cost};
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int N = n + 2;
    int S = n, T = n + 1;
    mcmf<int> MF(N);
    bool arr[n];
    for(bool &x : arr) cin >> x;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i]) MF.add_edge(S, i, 1, 0), cnt++;
        else MF.add_edge(i, T, 1, 0);

        if(i + 1 < n) MF.add_edge(i, i + 1, 1e4, 1);
        if(i) MF.add_edge(i, i - 1, 1e4, 1);
    }

    cout << MF.get_max_flow(S, T).se << '\n';
}
