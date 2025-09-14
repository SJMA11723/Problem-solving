#include <bits/stdc++.h>

using namespace std;

/// UDRL
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, 1, -1};
const char dir_c[4] = {'U', 'D', 'R', 'L'};

struct pos{
    int i, j, dir;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    char mat[n][m];
    int a, b, c, d;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
            if(mat[i][j] == 'C'){
                a = i;
                b = j;
            } else if(mat[i][j] == 'E'){
                c = i;
                d = j;
            }
        }
    }

    /**
        0: U
        1: D
        2: R
        3: L
        4: center
    */
    bool vis[n][m][5];
    memset(vis, 0, sizeof(vis));
    int dist[n][m][5];
    pair<pos, int> prv[n][m][5];
    queue<pos> q;
    q.push({a, b, 4});
    vis[a][b][4] = true;
    dist[a][b][4] = 0;

    while(q.size()){
        pos cur = q.front();
        q.pop();

        /// UDRL
        for(int k = 0; k < 4; ++k){
            int ni = cur.i + di[k];
            int nj = cur.j + dj[k];
            int ndir;
            if(cur.dir <= 1){
                if(k <= 1) ndir = 4; /// UD
                else ndir = cur.dir;
            } else if(cur.dir <= 3){
                if(k <= 1) ndir = cur.dir;
                else ndir = 4;
            } else ndir = k;

            if(cur.dir == k){
                if(k == 0) ni--;
                else if(k == 1) ni++;
                else if(k == 2) nj++;
                else nj--;
            }

            if(ni < 0 || nj < 0 || ni >= n || nj >= m || mat[ni][nj] == '#' || vis[ni][nj][ndir]) continue;

            if(ndir == 0 && (ni - 1 < 0 || mat[ni - 1][nj] == '#')) continue;
            if(ndir == 1 && (ni + 1 >= n || mat[ni + 1][nj] == '#')) continue;

            if(ndir == 3 && (nj - 1 < 0 || mat[ni][nj - 1] == '#')) continue;
            if(ndir == 2 && (nj + 1 >= m || mat[ni][nj + 1] == '#')) continue;

            vis[ni][nj][ndir] = true;
            dist[ni][nj][ndir] = dist[cur.i][cur.j][cur.dir] + 1;
            prv[ni][nj][ndir] = {cur, k};
            q.push(pos{ni, nj, ndir});
        }
    }

    if(!vis[c][d][4]){
        cout << "-1\n";
        return 0;
    }

    string ans;
    pos cur{c, d, 4};

    while(!(cur.i == a && cur.j == b && cur.dir == 4)){
        ans += dir_c[prv[cur.i][cur.j][cur.dir].second];
        cur = prv[cur.i][cur.j][cur.dir].first;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    cout << ans << '\n';
}
