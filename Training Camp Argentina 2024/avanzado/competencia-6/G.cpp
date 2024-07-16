/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int64_t c; // capacity
    int64_t f; // flow
    int to, w;
};

struct pos {
    int from, c;
    const bool operator<(const pos &b)const{
        return c > b.c;
    }
};

class ford_fulkerson {
public:
    ford_fulkerson (vector<vector<edge>> &graph) : graph(graph){}
    int64_t get_max_flow(int s, int t, int &min_cost, int n){
        init();
        int64_t f = 0;
        while(find_and_update(s, t, f)){}

        min_cost = 0;
        for(int i = 1; i <= n; ++i){
            int e_idx = edge_indexes[i][0];
            min_cost += edges[e_idx].f * i;
            //cout << i << ' ' << edges[e_idx].f << '\n';
        }

        return f;
    }
private:
    vector<vector<edge>> graph; // graph (to, capacity)
    vector<edge> edges; // List of edges (including the inverse ones)
    vector<vector<int>> edge_indexes; // indexes of edges going out from each vertex
    void init(){
        edges.clear();
        edge_indexes.clear(); edge_indexes.resize(graph.size());
        for(int i = 0; i < graph.size(); i++){
            for(edge &e : graph[i]){
                edges.push_back({e.c, 0, e.to, e.w});
                edges.push_back({0, 0, i, -e.w});
                edge_indexes[i].push_back(edges.size() - 2);
                edge_indexes[e.to].push_back(edges.size() - 1);
            }
        }
}
    bool find_and_update(int s, int t, int64_t &flow){
        // Encontrar camino desat con BFS
        priority_queue<pos> q;
        // Desde donde llego y con que arista
        vector<pair<int, int>> from(graph.size(), make_pair(-1, -1));

        /// camino de aumento con distancia minima
        vector<int> dist(graph.size(), INT_MAX);
        vector<char> vis(graph.size());

        q.push({s, 0});
        from[s] = make_pair(s, -1);
        dist[s] = 0;

        bool found = false;
        while(q.size() && (!found)){
            int u = q.top().from; q.pop();

            if(u == t) found = true;
            if(vis[u]) continue;
            vis[u] = true;

            for(int i = 0; i < edge_indexes[u].size(); i++){
                int eI = edge_indexes[u][i];
                if((edges[eI].c > edges[eI].f) && (from[edges[eI].to].first == -1) && (dist[edges[eI].to] >= dist[u] + edges[eI].w)){
                    from[edges[eI].to] = make_pair(u, eI);
                    dist[edges[eI].to] = dist[u] + edges[eI].w;
                    q.push({edges[eI].to, dist[edges[eI].to]});
                }
            }
        }
        if(!found) return false;
        // Encontrar cap. minima del camino de aumento
        int64_t u_flow = LLONG_MAX;
        int current = t;
        while(current != s) {
            u_flow = min(u_flow, edges[from[current].second].c - edges[from[current].second].f);
            current = from[current].first;
        }
        current = t;
        // Actualizar flujo
        while(current != s){
            edges[from[current].second].f += u_flow;
            edges[from[current].second^1].f -= u_flow; // Arista inversa
            current = from[current].first;
        }
        flow += u_flow ;
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string text; cin >> text;
    int n; cin >> n;

    vector<vector<edge>> graph(1 + ('z' - 'a' + 1) + n + 1);
    int s = 0, t = graph.size() - 1;
    for(int i = 1; i <= n; ++i){
        string s; cin >> s;
        int c; cin >> c;
        graph[i].push_back({c, 0, t, 0});

        int cub[300] = {};
        for(char c : s) cub[c]++;

        for(char c = 'a'; c <= 'z'; ++c)
            if(cub[c]) graph[n + c - 'a' + 1].push_back({cub[c], 0, i, i});
    }

    int cub[300] = {};
    for(char c : text) cub[c]++;

    for(char c = 'a'; c <= 'z'; ++c)
        if(cub[c]) graph[0].push_back({cub[c], 0, n + c - 'a' + 1, 0});


    int ans = 0;
    ford_fulkerson FF(graph);
    int flow = FF.get_max_flow(s, t, ans, n);
    //cout << flow << '\n';
    cout << (text.size() == flow ? ans  : -1) << '\n';
}
