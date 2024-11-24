#include <bits/stdc++.h>

using namespace std;

struct pos{
    int i, j, same, dir;
};

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int bfs(int a, int b, int c, int d, vector<vector<char>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(4, INT_MAX))));

    queue<pos> q;
    q.push({a, b, 0, 0});
    dist[a][b][0][0] = 0;

    while(q.size()){
        int i, j, same, dir;
        i = q.front().i;
        j = q.front().j;
        same = q.front().same;
        dir = q.front().dir;
        q.pop();

        for(int k = 0; k < 4; ++k){
            int ni = i + di[k];
            int nj = j + dj[k];
            int nsame = same;
            if(dir == k) nsame++;
            else nsame = 1;

            if(mat[ni][nj] == '#' || nsame > 3 || dist[ni][nj][k][nsame] != INT_MAX) continue;

            dist[ni][nj][k][nsame] = dist[i][j][dir][same] + 1;
            q.push({ni, nj, nsame, k});
        }
    }

    int mini = INT_MAX;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            mini = min(mini, dist[c][d][i][j]);

    return (mini == INT_MAX ? -1 : mini);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    int a, b, c, d;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
            if(mat[i][j] == 'S') tie(a, b) = make_pair(i, j);
            else if(mat[i][j] == 'T') tie(c, d) = make_pair(i, j);
        }
    }

    cout << bfs(a, b, c, d, mat) << '\n';
}
