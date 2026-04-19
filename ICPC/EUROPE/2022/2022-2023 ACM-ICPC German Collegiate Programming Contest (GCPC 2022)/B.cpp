#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

const int MAXV = (1 << 10) - 1;

template<class T = ll> struct dinic{
    dinic(int V){
        this->V = V;
    }

    const static bool SCALING = 0;
    bool sorted = 1;
    int s, t, V;
    int lim = 1;
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
    vi adj_cur[MAXV];

    void add_edge(int u, int v, T cap, bool is_directed = 1){
        if(v == u) return;

        T add = (is_directed ? 0 : cap);
        adj[u].pb({v, (int)adj[v].size(), cap, 0, cap + add});
        adj[v].pb({u, (int)adj[u].size() - 1, add, 0, cap + add});
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
        while(sz(q)){{{
            int u = q.front(); q.pop();

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
        }}}

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
        s = source; t = sink;
        ll flow = 0;
        lim = SCALING ? (1 << 30) : 1;

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

#define MAXN 20000000

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> es_primo(MAXN + 1, 1);
    for(int i = 2; i <= MAXN; ++i){
        if(!es_primo[i]) continue;
        for(ll j = 1ll * i * i; j <= MAXN; j += i)
            es_primo[j] = false;
    }

    int n; cin >> n;
    vi arr(n);
    for(int &x : arr) cin >> x;
    sort(all(arr));
    reverse(all(arr));
    while(arr.back() == 1 && sz(arr) > 1 && arr[sz(arr) - 2] == 1) arr.pop_back();
    n = sz(arr);

    dinic MF(n + 2);
    int s = n, t = n + 1;
    for(int i = 0; i < n; ++i){
        if(arr[i] & 1){
            MF.add_edge(i, t, 1);
        } else {
            MF.add_edge(s, i, 1);
        }
    }

    for(int i = 0; i < n; ++i){
        if(arr[i] & 1) continue;

        for(int j = 0; j < n; ++j){
            if(!(arr[j] & 1)) continue;

            if(es_primo[arr[i] + arr[j]]){
                MF.add_edge(i, j, 1);
            }
        }
    }

    cout << n - MF.get_max_flow(s, t) << '\n';
}