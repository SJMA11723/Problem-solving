#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define fi first
#define se second

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

// =============== DEBUG ============
const bool deb = 0;
#define DEBUG if(deb)

template<typename A, typename B> ostream & operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}
// ==================================

const int MAXV = (1 << 11) - 1;

template<class T = ll> struct dinic{
    dinic(short V){
        this->V = V;
    }
    const static bool SCALING = 1;
    bool sorted = 0;
    short s, t, V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    short level[MAXV];
    short ptr[MAXV];
    struct edge{
        short to, rev;
        T cap, flow, mcap;
        bool operator<(const edge &b)const{
            return mcap > b.mcap;
        }
    };
    vector<edge> adj[MAXV];
    vi adj_cur[MAXV];

    void add_edge(short u, short v, T cap, bool is_directed = 1){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].pb({v, sz(adj[v]), cap, 0, cap + add});
        adj[v].pb({u, sz(adj[u]) - 1, add, 0, cap + add});
    }

    void mysort(){
        if(sorted) return;
        sorted = 1;
        for(int i = 0; i < V; ++i){
            sort(all(adj[i]));
            for(int j = 0; j < sz(adj[i]); ++j)
                adj[adj[i][j].to][adj[i][j].rev].rev = j;
        }
    }

    bool bfs(){
        for(int i = 0; i < V; ++i){
            adj_cur[i].clear();
            adj_cur[i].reserve(sz(adj[i]));
        }
        queue<short> q;
        q.push(s);
        memset(level, -1, sizeof(level));
        //fill(level, sizeof(level),-1);
        level[s] = 0;
        while(sz(q)){
            short u = q.front(); q.pop();
            if(u == t) return 1;
            for(int i = 0; i < sz(adj[u]); ++i){
                edge &e = adj[u][i];
                if(e.mcap < lim) break;
                if(level[e.to] == -1 && e.cap - e.flow >= lim){
                    level[e.to] = level[u] + 1;
                    adj_cur[u].pb(i);
                    q.push(e.to);
                } else if(level[e.to] == level[u] + 1 && e.cap - e.flow >= lim){
                    adj_cur[u].pb(i);
                }
            }
        }
        return 0;
    }

    T dfs(short u, T flow){
        if(u == t) return flow;
        for(; ptr[u] < sz(adj_cur[u]); ++ptr[u]){
            edge &e = adj[u][adj_cur[u][ptr[u]]];
            if(T pushed = dfs(e.to, min(flow, e.cap - e.flow))){
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                if(e.cap - e.flow < lim) ptr[u]++;
                return pushed;
            }
        }
        return 0;
    }

    ll get_max_flow(short source, short sink){
        s = source, t = sink;
        mysort();
        ll flow = 0;
        lim = SCALING ? (1 << 30) : 1;
        for(; 0 < lim; lim >>= 1){
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
    int n, m; cin >> n >> m;
    dinic<ll> MF(n + 2), MF2(n + 2);
    int S = 0, T = n + 1;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        MF.add_edge(u, v, 1, 0);
        MF2.add_edge(u, v, 1, 0);
    }
    int a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;
    // fuentes
    MF.add_edge(S, a0, 1e8);
    MF.add_edge(S, b0, 1e8);
    
    MF2.add_edge(S, a0, 1e8);
    MF2.add_edge(S, b1, 1e8);

    // sinks
    MF.add_edge(a1, T, 1e8);
    MF.add_edge(b1, T, 1e8);

    MF2.add_edge(a1, T, 1e8);
    MF2.add_edge(b0, T, 1e8);

    cout << min(MF.get_max_flow(S, T), MF2.get_max_flow(S, T)) << '\n';
}