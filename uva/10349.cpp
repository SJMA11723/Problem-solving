/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 32767; /// 2^15 - 1

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR"; exit(0);}}
    const static bool SCALING = true;

    bool sorted = false;
    short s;
    short t;
    short V;
    int lim = 1; /// Para escalado
    const T INF = numeric_limits<T>::max();
    short level[MAXV]; /// distancia desde s
    short ptr[MAXV]; /// arista por la que va explorando

    struct edge{
        short to, rev;
        T cap, flow, mcap;
        bool operator<(const edge &b)const{return mcap > b.mcap;}
    };

    vector<edge> adj[MAXV];
    vector<short> adj_current[MAXV]; /// aristas del grafo de nivel

    void add_edge(int u, int v, T cap, bool is_directed = true){
        if(u == v) return;
        T add = (is_directed ? 0 : cap);
        adj[u].push_back({v, adj[v].size(), cap, 0, cap + add});
        adj[v].push_back({u, (short)adj[u].size() - 1, add, 0, cap + add});
    }

    void mysort(){
        if(sorted) return;
        sorted = true;
        for(int i = 0; i < V; ++i){
            sort(adj[i].begin(), adj[i].end());
            for(int j = 0; j < adj[i].size(); ++j){
                adj[adj[i][j].to][adj[i][j].rev].rev = j;
            }
        }
    }

    bool bfs(){ /// Crea grafo de nivel
        for(int i = 0; i < V; ++i){
            adj_current[i].clear();
            adj_current[i].reserve(adj[i].size());
        }

        queue<short> q;
        q.push(s);
        fill(level, level + V, -1);
        level[s] = 0;
        while(q.size()){
            short u = q.front(); q.pop();
            if(u == t) return true;
            for(int i = 0; i < (int)adj[u].size(); ++i){
                edge &e = adj[u][i];

                if(e.mcap < lim) break;
                if(level[e.to] == -1 && e.cap - e.flow >= lim){
                    level[e.to] = level[u] + 1;
                    adj_current[u].push_back(i);
                    q.push(e.to);
                } else if(level[e.to] == level[u] + 1 && e.cap - e.flow >= lim){
                    adj_current[u].push_back(i);
                }
            }
        }

        return false;
    }

    T dfs(short u, T flow, vector<int> &S, bool save = false){ /// Encuentra camino, bloquea aristas
        if(save) S.push_back(u);
        if(u == t) return flow;
        for(; ptr[u] < adj_current[u].size(); ++ptr[u]){
            edge &e = adj[u][adj_current[u][ptr[u]]];
            if(T pushed = dfs(e.to, min(flow, e.cap - e.flow), S, save)){
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                if(e.cap - e.flow < lim) ptr[u]++;
                return pushed;
            }
        }
        return 0;
    }

    T get_max_flow(short source, short sink){
        s = source;
        t = sink;
        mysort();
        vector<int> S;
        T flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF, S)) flow += pushed; /// Bloquear flujo
            }
        }
        return flow;
    }
};

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        dinic<int> MF(h * w + 2);
        char mat[h][w];
        int ans = 0;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                cin >> mat[i][j];
                if(mat[i][j] == 'o') continue;
                ans++;

                for(int k = 0; k < 4; ++k){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni < 0 || nj < 0 || ni >= h || nj >= w || mat[ni][nj] == 'o') continue;

                    if((i + j) % 2) MF.add_edge(i * w + j, ni * w + nj, 1);
                    else MF.add_edge(ni * w + nj, i * w + j, 1);
                }

                if((i + j) % 2) MF.add_edge(h * w, i * w + j, 1);
                else MF.add_edge(i * w + j, h * w + 1, 1);
            }
        }
        ans -= MF.get_max_flow(h * w, h * w + 1);

        cout << ans << '\n';
    }
}
