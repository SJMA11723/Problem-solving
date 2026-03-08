/**
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

#define is_on(S, i) ((S) & (1ll << (i)))

const ll MOD = 1e9 + 7;

const int MAXV = (1 << 19) - 1;
template <class T = ll> struct dinic{
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
        if(u == v) return;
        T add = is_directed ? 0 : cap;
        adj[u].pb({v, sz(adj[v]), cap, 0, cap + add});
        adj[v].pb({u, sz(adj[u]) - 1, add, 0, cap + add});
    }

    bool bfs(){
        for(int i = 0; i < V; ++i){
            adj_cur[i].clear();
            adj_cur[i].reserve(sz(adj[i]));
        }

        queue<int> q;
        q.push(s);
        memset(level, -1, sizeof(level));
        level[s] = 0;
        while(sz(q)){
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
        }
        return 0;
    }

    T dfs(int u, T flow){
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

    ll get_max_flow(int source, int sink){
        s = source, t = sink;
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

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

vll compress;
int mhash(ll x){
    return lower_bound(all(compress), x) - compress.begin();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    map<string, int> str2num;
    int nxt_num = 1;

    
    vi algos[N];
    for(int i = 0; i < N; ++i){
        int A; cin >> A;
        for(int j = 0; j < A; ++j){
            string s; cin >> s;
            if(!str2num.count(s)) str2num[s] = nxt_num++;
            algos[i].pb(str2num[s]);
        }
    }
    
    

    ll rand_hash[nxt_num];
    for(ll &x : rand_hash) x = distr(gen);

    for(int i = 0; i < N; ++i){
        int lim = 1 << sz(algos[i]);
        for(int mask = 0; mask < lim; ++mask){
            ll xor_sum = 0;
            for(int j = 0; j < sz(algos[i]); ++j){
                if(is_on(mask, j))
                    xor_sum ^= rand_hash[ algos[i][j] ];
            }
            compress.pb(xor_sum);
        }
    }

    {
        sort(all(compress));
        compress.resize(unique(all(compress)) - compress.begin());
    }
    
    

    int len_comp = sz(compress);
    int V = 2 * len_comp + 2;
    auto IN = [len_comp](int u){return u + len_comp;};
    auto OUT = [](int u){return u;};

    dinic<int> MF(V);
    int s = V - 2;
    int t = V - 1;
    {
        set<pii> edges;
        for(int i = 0; i < N; ++i){
            int lim = 1 << sz(algos[i]);
            for(int mask = 0; mask < lim; ++mask){
                ll xor_sum = 0;
                for(int j = 0; j < sz(algos[i]); ++j){
                    if(is_on(mask, j))
                        xor_sum ^= rand_hash[ algos[i][j] ];
                }
                int u = mhash(xor_sum);

                edges.insert({s, OUT(u)});
                edges.insert({IN(u), t});

                for(int j = 0; j < sz(algos[i]); ++j){
                    if(!is_on(mask, j)){
                        int v = mhash(xor_sum ^ rand_hash[ algos[i][j] ]);
                        edges.insert({OUT(u), IN(v)});
                    }
                }
            }
        }

        for(auto [u, v] : edges) MF.add_edge(u, v, 1);
    }

    cout << len_comp - MF.get_max_flow(s, t) << '\n';
}