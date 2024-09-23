#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, w;

    bool operator<(const edge &b)const{
        return w < b.w;
    }
};

struct pos{
    int from;
    int64_t c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

int64_t dijkstra(int s, int n, vector<edge> graph[], const int64_t MAX_W){
    vector<char> vis(n);
    vector<int64_t> dist(n, LLONG_MAX);
    priority_queue<pos> pq;
    pq.push({s, 0});
    dist[s] = 0;

    while(pq.size()){
        pos cur = pq.top();
        pq.pop();
        if(vis[cur.from]) continue;
        vis[cur.from] = true;

        for(edge &e : graph[cur.from]){
            if(e.w > MAX_W) continue;
            if(dist[e.to] < dist[cur.from] + e.w) continue;
            dist[e.to] = dist[cur.from] + e.w;
            pq.push({e.to, dist[e.to]});
        }
    }

    return *max_element(dist.begin(), dist.end());
}

int di[4] = {0, 0, 1, -1};
int dj[4] = {-1, 1, 0, 0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int R, C, D, x, y;
    cin >> R >> C >> D >> x >> y;

    int mat[R][C];
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            cin >> mat[i][j];
        }
    }

    vector<edge> graph[R * C];
    int64_t maxdelta = 0;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            for(int k = 0; k < 4; ++k){
                int ni = i + di[k];
                int nj = j + dj[k];

                if(ni < 0 || nj < 0 || ni >= R || nj >= C) continue;

                int u = i * C + j;
                int v = ni * C + nj;
                graph[u].push_back({u, v, abs(mat[i][j] - mat[ni][nj])});
                graph[v].push_back({v, u, abs(mat[i][j] - mat[ni][nj])});

                maxdelta = max(maxdelta,  (int64_t)abs(mat[i][j] - mat[ni][nj]));

            }
        }
    }

    x--, y--;

    int64_t dist = dijkstra(x * C + y, R * C, graph, maxdelta + 1);

    if(dist > D){
        cout << "No puedo, jefe: " << dist << ' ';
        int64_t l = 0, r = maxdelta;
        while(l < r){
            int64_t mid = l + (r - l) / 2;
            int64_t res = dijkstra(x * C + y, R * C, graph, mid);
            if(res > dist) l = mid + 1;
            else r = mid;
        }
        cout << l << '\n';
    } else {
        int64_t l = 0, r = maxdelta;
        while(l < r){
            int64_t mid = l + (r - l) / 2;
            int64_t res = dijkstra(x * C + y, R * C, graph, mid);
            if(res > D) l = mid + 1;
            else r = mid;
        }
        cout << l << '\n';
    }
}
