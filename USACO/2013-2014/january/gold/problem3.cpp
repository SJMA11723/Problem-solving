/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 500

using namespace std;

int n, m, t;
bool start[MAXN][MAXN];
int mat[MAXN][MAXN];

struct dsu{
    int RA[MAXN * MAXN], P[MAXN * MAXN];
    int starting_points[MAXN * MAXN];
    dsu(int _n){
        for(int i = 0; i < _n; ++i){
            RA[i] = 1;
            P[i] = i;
            starting_points[i] = start[i / n][i % n];
        }
    }

    int root(int x){
        if(x == P[x]) return x;
        return P[x] = root(P[x]);
    }

    int64_t join(int x, int y, int64_t w){
        x = root(x);
        y = root(y);
        if(x == y) return 0;

        int64_t res = 0;
        if(RA[x] >= RA[y]) swap(x, y);
        if(RA[x] + RA[y] >= t){
            if(RA[x] < t)
                res += w * starting_points[x];
            if(RA[y] < t)
                res += w * starting_points[y];
        }
        RA[y] += RA[x];
        P[x] = y;
        starting_points[y] += starting_points[x];
        return res;
    }
};

int dir_i[2] = {0, 1}, dir_j[2] = {1, 0};

struct edge{
    int from, to;
    int64_t w;
    bool operator<(const edge &b)const{
        return w < b.w;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("skilevel.in");
    ofstream cout("skilevel.out");
    cin >> m >> n >> t;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j) cin >> mat[i][j]; /// i * n + j
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j) cin >> start[i][j];

    vector<edge> edges;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int pos1 = i * n + j;
            for(int k = 0; k < 2; ++k){
                int ni = i + dir_i[k];
                int nj = j + dir_j[k];
                if(ni >= m || nj >= n) continue;
                int pos2 = ni * n + nj;
                edges.push_back({pos1, pos2, abs(mat[i][j] - mat[ni][nj])});
            }
        }
    }

    dsu mset(n * m);
    sort(edges.begin(), edges.end());
    int64_t ans = 0;
    for(edge &e : edges){
        ans += mset.join(e.from, e.to, e.w);
    }
    cout << ans << '\n';
}
