#include  <bits/stdc++.h>
#define MAXK 700

using namespace std;

int mat[30][30];
int dir_i[4] = {-1, -2, -2, -1}, dir_j[4] = {2, 1, -1, -2};
bool adj[MAXK][MAXK];
int deg[MAXK];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= k; ++i){
        int r, c; cin >> r >> c;
        r--, c--;
        mat[r][c] = i;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!mat[i][j]) continue;

            for(int p = 0; p < 4; ++p){
                int ni = i + dir_i[p];
                int nj = j + dir_j[p];

                if(ni < 0 || ni >= n || nj < 0 || nj >= n || !mat[ni][nj]) continue;

                deg[ mat[i][j] ]++;
                deg[ mat[ni][nj] ]++;
                adj[mat[i][j]][mat[ni][nj]] = adj[mat[ni][nj]][mat[i][j]] = 1;
            }
        }
    }

    set<pair<int, int>> mset;
    for(int i = 1; i <= k; ++i){
        mset.insert({deg[i], i});
    }

    int ans = 0;
    while(mset.size()){
        pair<int, int> act = *(mset.rbegin());
        mset.erase(act);

        int u = act.second;

        if(!deg[u]) continue;

        ans++;
        for(int v = 1; v <= k; ++v){
            if(!adj[u][v]) continue;

            deg[u]--;
            mset.erase({deg[v], v});
            deg[v]--;
            mset.insert({deg[v], v});
            adj[u][v] = adj[v][u] = 0;
        }
    }
    cout << ans << '\n';
}
