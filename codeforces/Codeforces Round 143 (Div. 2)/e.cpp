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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

#define LOGN 18
#define is_on(s, i) ((s) & (1ll << (i)))
const int MOD = 1e9 + 7;

void detect_cycles(int u, vi graph[], bool vis[], int comp[], int &cur_comp, stack<int> &st, int p = 0){
    vis[u] = 1;
    st.push(u);
    for(int v : graph[u]){
        if(vis[v]){
            if(v != p && !comp[u]){
                comp[u] = comp[v] = cur_comp;
                while(sz(st) && st.top() != v){
                    comp[st.top()] = cur_comp;
                    st.pop();
                } if(sz(st)) st.pop();
                cur_comp++;
            }
            continue;
        }
        detect_cycles(v, graph, vis, comp, cur_comp, st, u);
    }
    if(sz(st) && st.top() == u) st.pop();
}

void detect_trees(int u, vi graph[], int comp[], int &cur_comp){
    comp[u] = cur_comp;
    for(int v : graph[u])
        if(!comp[v]) detect_trees(v, graph, comp, cur_comp);
}

vvi P, tree;
vi depth;

void precalc(int u, int val[], int p = 0, int d = 1){
    depth[u] = d;
    P[0][u] = p;
    val[u] += val[p];
    for(int k = 1; k <= LOGN; ++k)
        P[k][u] = P[k - 1][P[k - 1][u]];
    for(int v : tree[u]) if(v != p)
        precalc(v, val, u, d + 1);
}

int LCA(int a, int b){
    if(depth[b] < depth[a]) swap(a, b);
    int diff = depth[b] - depth[a];
    for(int k = LOGN; 0 <= k; --k)
        if(is_on(diff, k)) b = P[k][b];
    
    if(a == b) return a;

    for(int k = LOGN; 0 <= k; --k){
        if(P[k][a] != P[k][b]){
            a = P[k][a];
            b = P[k][b];
        }
    }
    return P[0][a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vi graph[n + 1];
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int comp[n + 1] = {};
    int nxt_comp = 1;
    bool vis[n + 1] = {};
    stack<int> st;
    detect_cycles(1, graph, vis, comp, nxt_comp, st);
    int max_cycle = nxt_comp - 1;
    for(int i = 1; i <= n; ++i) if(!comp[i]) detect_trees(i, graph, comp, nxt_comp), nxt_comp++;

    tree.resize(nxt_comp);
    for(int u = 1; u <= n; ++u)
        for(int v : graph[u]) if(comp[u] != comp[v])
            tree[comp[u]].pb(comp[v]);

    int val[nxt_comp]; val[0] = 0;
    for(int i = 1; i < nxt_comp; ++i) val[i] = i <= max_cycle;

    depth.resize(nxt_comp);
    P.resize(LOGN + 1, vi(nxt_comp));
    precalc(1, val);

    int ans[nxt_comp] = {};
    ans[0] = 1;
    for(int i = 1; i < nxt_comp; ++i){
        ans[i] = ans[i - 1] + ans[i - 1];
        if(ans[i] >= MOD) ans[i] -= MOD;
    }

    int k; cin >> k;
    while(k--){
        int x, y; cin >> x >> y;
        x = comp[x];
        y = comp[y];
        int lca = LCA(x, y);
        cout << ans[val[x] + val[y] - 2 * val[lca] + (lca <= max_cycle)] << '\n';
    }
}
