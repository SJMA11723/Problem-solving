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

const ll MOD = 1e9 + 7;

void dfs(int node, vi graph[], bool vis[], vi &topo_ord){
    if(vis[node]) return;
    vis[node] = true;
    for(int v : graph[node]) dfs(v, graph, vis, topo_ord);
    topo_ord.pb(node);
}

vi compute_topo_ord(int n, vi graph[]){
    bool vis[n] = {};
    vi topo_ord;
    for(int i = 0; i < n; ++i) dfs(i, graph, vis, topo_ord);
    reverse(all(topo_ord));
    return topo_ord;
}

void bfs(int n, int s, vi dag[], bool vis[]){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int v : dag[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    bool type[n], ap_set = 0, ap_unset = 0;
    int cnt_true = 0, s1 = -1, s2 = -1;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        if(s == "set"){
            type[i] = 1;

            cin >> s;
            ap_set = 1;
            if(s == "true"){
                cnt_true++;
                s1 = i;
            }
        } else {
            type[i] = 0;

            cin >> s;
            ap_unset = 1;
            if(s == "true"){
                cnt_true++;
                s2 = i;
            }
        }
    }

    int m; cin >> m;
    vi dag[n];
    int in_deg[n] = {}, in_deg_set[n] = {};
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        dag[a].pb(b);
        if(type[a]) in_deg_set[b]++;
        in_deg[b]++;
    }

    if(!cnt_true){
        if(ap_set){
            cout << "-1\n";
        } else {
            vi ans = compute_topo_ord(n, dag);
            for(int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i + 1 == n];
        }
        return 0;
    }

    vi ans;
    vi topo_ord = compute_topo_ord(n, dag);
    if(cnt_true == 1){
        if(s1 == -1 || in_deg_set[s1]){
            cout << "-1\n";
            return 0;
        }

        for(int u : topo_ord) if(!type[u]) ans.pb(u);
        ans.pb(s1);
        for(int u : topo_ord) if(type[u] && u != s1) ans.pb(u);
    } else {
        if(s1 == -1 || s2 == -1 || in_deg_set[s1]){
            cout << "-1\n";
            return 0;
        }

        bool ap_end[n] = {};
        bfs(n, s2, dag, ap_end);
        for(int i = 0; i < n; ++i){
            if(!type[i] && in_deg_set[i]) ap_end[i] = 1;
        }

        for(int u : topo_ord) if(!type[u] && !ap_end[u]) ans.pb(u);
        ans.pb(s1);
        for(int u : topo_ord) if(type[u] && u != s1) ans.pb(u);
        ans.pb(s2);
        for(int u : topo_ord) if(!type[u] && ap_end[u] && u != s2) ans.pb(u);
    }

    bool ok = true;
    for(int u : ans){
        if(in_deg[u]){
            cout << "-1\n";
            return 0;
        }
        for(int v : dag[u]) in_deg[v]--;
    }

    for(int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i + 1 == n];
}