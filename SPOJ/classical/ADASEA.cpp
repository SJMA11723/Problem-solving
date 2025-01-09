/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        char mat[n][m];
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> mat[i][j];

        int64_t p = 0;
        int64_t q = n * m;
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(mat[i][j] != '#' || vis[i][j]) continue;

            queue<pair<int, int>> q;
            vis[i][j] = true;
            q.push({i, j});
            int len = 0;
            while(q.size()){
                int a, b;
                tie(a, b) = q.front(); q.pop();

                len++;

                for(int k = 0; k < 4; ++k){
                    int ni = a + di[k];
                    int nj = b + dj[k];

                    if(ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj] || mat[ni][nj] != '#') continue;
                    q.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }

            p += 1ll * len * len;
        }

        int64_t g = __gcd(p, q);
        p /= g;
        q /= g;

        cout << p;
        if(p && q != 1) cout << " / " << q;
        cout << '\n';
    }
}
