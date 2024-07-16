/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int di[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dj[8] = {1, -1, 0, 1, -1, 0, 1, -1};

bool bfs(int kx, int ky, int cx, int cy, int qx, int qy, int n){
    bool vis[n + 1][n + 1];
    memset(vis, 0, sizeof(vis));

    queue<pair<int, int>> q;
    q.push({kx, ky});
    vis[kx][ky] = true;

    while(q.size()){
        int i, j;
        tie(i, j) = q.front();
        q.pop();

        for(int k = 0; k < 8; ++k){
            int ni = i + di[k];
            int nj = j + dj[k];

            if(ni < 1 || nj < 1 || ni > n || nj > n || vis[ni][nj]
               || ni == qx || nj == qy || ni + nj == qx + qy || ni - nj == qx - qy) continue;

            vis[ni][nj] = true;
            q.push({ni, nj});
        }
    }

    return vis[cx][cy];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int qx, qy; cin >> qx >> qy;
    int kx, ky; cin >> kx >> ky;
    int cx, cy; cin >> cx >> cy;
    cout << (bfs(kx, ky, cx, cy, qx, qy, n) ? "YES\n" : "NO\n");
}
