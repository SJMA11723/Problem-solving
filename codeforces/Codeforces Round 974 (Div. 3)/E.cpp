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

struct edge{
    int from, to;
    ll w;
};

struct pos{
    int from;
    ll c;
    bool horse;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

vector<vll> dijkstra(int s, int n, vector<edge> graph[], bool ride[]){
    vector<vll> dist(n, vll(2));
    for(int i = 0; i < n; ++i) dist[i][0] = dist[i][1] = LLONG_MAX;
    bool vis[n][2];
    for(int i = 0; i < n; ++i) vis[i][0] = vis[i][1] = 0;

    priority_queue<pos> q;
    q.push({s, 0, 0});
    dist[s][0] = 0;
    if(ride[s]){
        q.push({s, 0, 1});
        dist[s][1] = 0;
    }

    while(q.size()){
        pos cur = q.top(); q.pop();
        if(vis[cur.from][cur.horse]) continue;
        vis[cur.from][cur.horse] = true;

        for(edge &e : graph[cur.from]){
            if(cur.horse){
                if(dist[e.to][1] <= dist[e.from][1] + e.w / 2) continue;

                dist[e.to][1] = dist[e.from][1] + e.w / 2;
                q.push(pos{e.to, dist[e.to][1], 1});
            } else {
                // sigo sin caballo
                if(dist[e.to][0] > dist[e.from][0] + e.w){
                    dist[e.to][0] = dist[e.from][0] + e.w;
                    q.push(pos{e.to, dist[e.to][0], 0});
                }

                // uso caballo
                if(ride[cur.from]){
                    if(dist[e.to][1] > dist[e.from][0] + e.w / 2){
                        dist[e.to][1] = dist[e.from][0] + e.w / 2;
                        q.push(pos{e.to, dist[e.to][1], 1});
                    }
                }
            }
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, h; cin >> n >> m >> h;
        bool ride[n] = {};
        for(int i = 0; i < h; ++i){
            int x; cin >> x; x--;
            ride[x] = 1;
        }

        vector<edge> graph[n];
        for(int i = 0; i < m; ++i){
            int a, b, w; cin >> a >> b >> w;
            a--, b--;
            graph[a].pb({a, b, w});
            graph[b].pb({b, a, w});
        }

        vector<vll> dist1 = dijkstra(0, n, graph, ride);
        vector<vll> distn = dijkstra(n - 1, n, graph, ride);

        ll ans = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            ll t1 = min(dist1[i][0], dist1[i][1]);
            ll t2 = min(distn[i][0], distn[i][1]);
            if(t1 == LLONG_MAX || t2 == LLONG_MAX) continue;
            ans = min(ans, max(t1, t2));
        }
        if(ans == LLONG_MAX) ans = -1;

        cout << ans << '\n';
    }
}