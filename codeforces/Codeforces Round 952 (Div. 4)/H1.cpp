/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void assign_comp(int i, int j, const vector<vector<char>> &mat, int &idx_comp, vector<vector<int>> &comp, vector<vector<char>> &vis, int sz_comp[]){
    int n = mat.size();
    int m = mat[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    int res = 0;

    while(q.size()){
        tie(i, j) = q.front();
        q.pop();

        res++;
        comp[i][j] = idx_comp;

        for(int k = 0; k < 4; ++k){
            int ni = i + di[k];
            int nj = j + dj[k];

            if(ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj] || mat[ni][nj] == '.') continue;

            vis[ni][nj] = true;
            q.push({ni, nj});
        }
    }

    sz_comp[idx_comp++] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) cin >> mat[i][j];

        vector<vector<char>> vis(n, vector<char>(m));
        vector<vector<int>> comp(n, vector<int>(m));
        int idx_comp = 1, sz_comp[n * m + 1] = {};
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(!vis[i][j] && mat[i][j] == '#') assign_comp(i, j, mat, idx_comp, comp, vis, sz_comp);

        /// connect row
        int ans = 0;
        for(int i = 0; i < n; ++i){
            set<int> components;
            int sz_connect = 0;

            for(int j = 0; j < m; ++j){
                if(mat[i][j] == '#') components.insert(comp[i][j]);
                else sz_connect++;

                for(int k = 0; k < 2; ++k){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni < 0 || nj < 0 || ni >= n || nj >= m || mat[ni][nj] == '.') continue;
                    components.insert(comp[ni][nj]);
                }
            }

            for(int x : components) sz_connect += sz_comp[x];
            ans = max(ans, sz_connect);
        }

        /// connect column
        for(int j = 0; j < m; ++j){
            set<int> components;
            int sz_connect = 0;

            for(int i = 0; i < n; ++i){
                if(mat[i][j] == '#') components.insert(comp[i][j]);
                else sz_connect++;

                for(int k = 2; k < 4; ++k){
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(ni < 0 || nj < 0 || ni >= n || nj >= m || mat[ni][nj] == '.') continue;
                    components.insert(comp[ni][nj]);
                }
            }

            for(int x : components) sz_connect += sz_comp[x];
            ans = max(ans, sz_connect);
        }

        cout << ans << '\n';
    }
}
