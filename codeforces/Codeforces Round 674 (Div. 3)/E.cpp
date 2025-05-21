/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MAXV = 32767; /// 2^15 - 1

template<class T = int64_t> struct dinic{
    dinic(short V){this->V = V; if(V > MAXV){cout << "ERROR"; exit(0);}}
    const static bool SCALING = false;

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
    vector<int> adj_current[MAXV]; /// aristas del grafo de nivel

    void add_edge(short u, short v, T cap, bool is_directed = true){
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

    T dfs(short u, T flow){
        if(u == t) return flow;
        for(; ptr[u] < adj_current[u].size(); ++ptr[u]){
            edge &e = adj[u][adj_current[u][ptr[u]]];
            if(T pushed = dfs(e.to, min(flow, e.cap - e.flow))){
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
        T flow = 0;
        for(lim = SCALING ? (1 << 30) : 1; 0 < lim; lim >>= 1){
            while(bfs()){
                memset(ptr, 0, sizeof(ptr));
                while(T pushed = dfs(s, INF)) flow += pushed;
            }
        }
        return flow;
    }

    void reset(){
        for(int i = 0; i < V; ++i) adj[i].clear(), adj_current[i].clear();
        sorted = false;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    int N = 3;
    dinic MF(2 * N + 2);
    int s = 2 * N, t = 2 * N + 1;
    int rock = 0, scissors = 1, paper = 2;
    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;

    for(int i = 0; i < 2; ++i){
        swap(a, d);
        swap(b, e);
        swap(c, f);
        MF.add_edge(s, rock, a);
        MF.add_edge(s, scissors, b);
        MF.add_edge(s, paper, c);
        MF.add_edge(rock, scissors + N, 1e9);
        if(!i) MF.add_edge(rock, rock + N, 1e9);
        MF.add_edge(scissors, paper + N, 1e9);
        if(!i) MF.add_edge(scissors, scissors + N, 1e9);
        MF.add_edge(paper, rock + N, 1e9);
        if(!i) MF.add_edge(paper, paper + N, 1e9);
        MF.add_edge(rock + N, t, d);
        MF.add_edge(scissors + N, t, e);
        MF.add_edge(paper + N, t, f);

        if(i) cout << MF.get_max_flow(s, t) << '\n';
        else cout << n - MF.get_max_flow(s, t) << ' ';

        MF.reset();
    }
}
