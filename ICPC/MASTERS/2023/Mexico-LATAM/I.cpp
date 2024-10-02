#include <bits/stdc++.h>

using namespace std;

struct edge{
    int from, to;
    int64_t w, c, f;
};

class ford_fulkerson{
public:
    ford_fulkerson(vector<vector<edge>> &graph): graph(graph){}
    int64_t get_max_flow(int s, int t){
        init();
        int64_t f = 0;
        while(find_and_update(s, t, f));
        return f;
    }
private:
    vector<vector<edge>> graph;
    vector<edge> edges;
    vector<vector<int>> edge_indexes;

    void init(){
        edges.clear();
        edge_indexes.clear(); edge_indexes.resize(graph.size());
        for(int u = 0; u < graph.size(); ++u){
            for(edge &e : graph[u]){
                edges.push_back({u, e.to, e.w, e.c, 0});
                edges.push_back({e.to, u, -e.w, 0, 0});
                edge_indexes[u].push_back(edges.size() - 2);
                edge_indexes[e.to].push_back(edges.size() - 1);
            }
        }
    }

    bool find_and_update(int s, int t, int64_t &flow){
        queue<int> q;

        vector<pair<int, int>> from(graph.size(), make_pair(-1, -1));
        q.push(s);
        from[s] = make_pair(s, -1);
        bool found = false;
        while(q.size() && !found){
            int u = q.front(); q.pop();
            for(int eI : edge_indexes[u]){
                if(edges[eI].c > edges[eI].f && from[edges[eI].to].first == -1){
                    from[edges[eI].to] = make_pair(u, eI);
                    q.push(edges[eI].to);
                    if(edges[eI].to == t) found = true;
                }
            }
        }

        if(!found) return false;

        int64_t u_flow = LLONG_MAX;
        int current = t;
        while(current != s){
            u_flow = min(u_flow, edges[from[current].second].c - edges[from[current].second].f);
            current = from[current].first;
        }
        current = t;

        while(current != s){
            edges[from[current].second].f += u_flow;
            edges[from[current].second^1].f -= u_flow;
            current = from[current].first;
        }

        flow += u_flow;
        return true;
    }
};

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

vector<int> bfs(int a, int b, int d, vector<vector<char>> &mat){
    int r = mat.size();
    int c = mat[0].size();

    int dist[r][c];
    fill(&dist[0][0], &dist[0][0] + r * c, -1);
    queue<pair<int, int>> q;
    q.push({a, b});
    dist[a][b] = 0;

    vector<int> res;

    while(q.size()){
        pair<int, int> cur = q.front();
        q.pop();

        if(cur != make_pair(a, b) && mat[cur.first][cur.second] != '.'){
            if(mat[cur.first][cur.second] != 'H') res.push_back(cur.first * c + cur.second);
            continue;
        }

        if(dist[cur.first][cur.second] == d) continue;

        for(int k = 0; k < 4; ++k){
            int ni = cur.first + di[k];
            int nj = cur.second + dj[k];

            if(ni < 0 || ni >= r || nj < 0 || nj >= c || dist[ni][nj] != -1 || mat[ni][nj] == '#') continue;
            dist[ni][nj] = dist[cur.first][cur.second] + 1;
            q.push({ni, nj});
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c, d; cin >> r >> c >> d;
    int n = r * c;

    vector<vector<edge>> graph(2 * n + 2);
    vector<vector<char>> mat(r, vector<char>(c));
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(mat[i][j] != 'H'){
                if(mat[i][j] == 'S') graph[2 * n].push_back({2 * n, i * c + j, 0, 1, 0});
                else if(mat[i][j] == 'P') graph[i * c + j].push_back({i * c + j, 2 * n + 1, 0, 1, 0});
                continue;
            }
            vector<int> reachable = bfs(i, j, d, mat);

            int u = i * c + j;
            graph[u].push_back({u, u + n, 0, 1, 0});

            for(int v : reachable){
                if(mat[v / c][v % c] == 'S') graph[v].push_back({v, u, 0, 1, 0});
                else graph[u + n].push_back({u + n, v, 0, 1, 0});
            }
        }
    }

    ford_fulkerson FF(graph);
    cout << FF.get_max_flow(2 * n, 2 * n + 1) << '\n';
}
