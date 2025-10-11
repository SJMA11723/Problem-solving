/**
* Author: Mäthgic Crüe
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef double ld;
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

#define UL(u) (u)
#define U(u) (u + 1)
#define UR(u) (u + 2)
#define L(u) (u + 3)
#define R(u) (u + 4)
#define DL(u) (u + 5)
#define D(u) (u + 6)
#define DR(u) (u + 7)


const ll MOD = 1e9 + 7;
const ld PI = acos(-1);

struct edge{
    int to;
    ld w;

    edge(){
        to = w = -1;
    }

    const bool operator<(const edge &b)const{
        return w > b.w;
    }
};

struct pos{
    int from;
    ld c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

ld dijkstra(int a, int b, int n, edge graph[][2]){
    ld dist[n];
    bool vis[n] = {};
    fill(dist, dist + n, 1e8);
    priority_queue<pos> q;
    q.push({a, 0});
    dist[a] = 0;
 
    while(sz(q)){
        pos act = q.top();
        q.pop();
        int u = act.from;
        if(vis[u]) continue;
        vis[u] = true;
        for(edge &e : graph[u]){
            if(dist[e.to] <= dist[u] + e.w) continue;
            dist[e.to] = dist[u] + e.w;
            q.push({e.to, dist[e.to]});
        }
    }
 
    return dist[b];
}

void add_edge(int u, int v, ld w, edge graph[][2], bool dir = false){
    int i = 0;
    if(graph[u][i].to != -1) i++;

    graph[u][i].to = v;
    graph[u][i].w = w;
    if(!dir){
        i = 0;
        if(graph[v][i].to != -1) i++;
        graph[v][i].to = u;
        graph[v][i].w = w;
    }
}

int id(int i, int j, int w){
    return i * w + j;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w; cin >> h >> w;
    
    int N = 8 * h * w;
    edge graph[N][2];

    char mat[h][w];
    int u = 0;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            int u = id(i, j, w) * 8;
            char c; cin >> c;
            mat[i][j] = c;

            // cuadrado externo
            add_edge(UL(u), U(u), 5, graph, 1);
            add_edge(UL(u), L(u), 5, graph, 1);

            add_edge(U(u), UR(u), 5, graph, 1);
            add_edge(UR(u), R(u), 5, graph, 1);

            add_edge(DL(u), D(u), 5, graph, 1);
            add_edge(L(u), DL(u), 5, graph, 1);

            add_edge(D(u), DR(u), 5, graph, 1);
            add_edge(R(u), DR(u), 5, graph, 1);

            /// conexto arcos de circunferencia
            if(c == 'O'){
                //add_edge(L(u), U(u), PI * 2.5, graph, 1);
                add_edge(L(u), D(u), PI * 2.5, graph, 1);
                add_edge(U(u), R(u), PI * 2.5, graph, 1);
                //add_edge(D(u), R(u), PI * 2.5, graph, 1);
            }


            /// conecto arriba sq externo
            if(i){
                int v = id(i - 1, j, w) * 8;
                add_edge(DL(v), UL(u), 0, graph, 1);
                add_edge(D(v), U(u), 0, graph, 1);
                add_edge(DR(v), UR(u), 0, graph, 1);
            }
            /// conexto izquierda sq externo
            if(j){
                int v = id(i, j - 1, w) * 8;
                add_edge(UR(v), UL(u), 0, graph, 1);
                add_edge(R(v), L(u), 0, graph, 1);
                add_edge(DR(v), DL(u), 0, graph, 1);
            }
        }
    }

    cout << fixed << setprecision(7) << dijkstra(0, N - 1, N, graph) << '\n';
    //cout << fixed << setprecision(7) << dfs(0, N - 1, graph) << '\n';
}
