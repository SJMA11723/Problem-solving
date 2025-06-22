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

const int MAXV = (1 << 17) - 1;

template<class T = ll> struct dinic{
    dinic(int V){
        this->V = V;
        level.resize(V);
        ptr.resize(V);
        adj.resize(V);
        adj_cur.resize(V);
    }
    const static bool SCALING = 0;

    int s, t, V;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    vi level, ptr;
    struct edge{
        int to, rev;
        T cap, flow, mcap;
        bool operator<(const edge &b)const{
            return mcap > b.mcap;
        }
    };
    vector<vector<edge>> adj;
    vector<vi> adj_cur;

    void add_edge(int u, int v, T cap, bool is_directed = 1){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
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
        fill(all(level), -1);
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
        lim = SCALING ? (1<<30) : 1;
        for(; 0 < lim; lim >>= 1){
            while(bfs()){
                fill(all(ptr), 0);
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
    while(t--){
        int n; cin >> n;
        int N = 2 * n + 2;
        dinic<int> MF(N);
        int S = 2 * n, T = 2 * n + 1;
        int arr[n];
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            arr[i] = --x;
            MF.add_edge(i, x + n, 1);
            MF.add_edge(S, i, 1);
            MF.add_edge(i + n, T, 1);
        }

        cout << MF.get_max_flow(S, T) << '\n';
        int ans[n];
        memset(ans, -1, sizeof(ans));
        set<int> pending;
        for(int i = 0; i < n; ++i) pending.insert(i);
        
        int inv[n];
        for(int i = 0; i < n; ++i){
            for(auto &e : MF.adj[i]){
                if(e.flow == 1){
                    ans[i] = e.to - n;
                    inv[ans[i]] = i;
                    pending.erase(ans[i]);
                    break;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            if(ans[i] != -1) continue;
            if(i != *pending.begin()){
                ans[i] = *pending.begin();
                pending.erase(pending.begin());
            } else if(i != *pending.rbegin()){
                ans[i] = *pending.rbegin();
                pending.erase(ans[i]);
            } else {
                int nxt = inv[ arr[i] ];
                ans[i] = arr[i];
                ans[nxt] = i;
                break;
            }
        }

        for(int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i + 1 == n];
    }
}