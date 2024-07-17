/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct pos{
    int i, j, len;
    int64_t sum;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int64_t k, mat[n][m];
    cin >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> mat[i][j];

    const int MAX_LENGTH = n + m - 2;

    map<int64_t, int> cnt[n][m];
    queue<pos> q;
    q.push({0, 0, 0, mat[0][0]});
    while(q.size()){
        pos cur = q.front();
        q.pop();
        if(cur.len == MAX_LENGTH / 2){
            cnt[cur.i][cur.j][cur.sum]++;
            continue;
        }
        if(cur.i + 1 < n) q.push({cur.i + 1, cur.j, cur.len + 1, cur.sum ^ mat[cur.i + 1][cur.j]});
        if(cur.j + 1 < m) q.push({cur.i, cur.j + 1, cur.len + 1, cur.sum ^ mat[cur.i][cur.j + 1]});
    }


    int64_t ans = 0;
    q.push({n - 1, m - 1, 0, mat[n - 1][m - 1]});
    while(q.size()){
        pos cur = q.front();
        q.pop();
        if(cur.len == MAX_LENGTH - MAX_LENGTH / 2){
            ans += cnt[cur.i][cur.j][k ^ cur.sum ^ mat[cur.i][cur.j]];
            continue;
        }
        if(cur.i - 1 >= 0) q.push({cur.i - 1, cur.j, cur.len + 1, cur.sum ^ mat[cur.i - 1][cur.j]});
        if(cur.j - 1 >= 0) q.push({cur.i, cur.j - 1, cur.len + 1, cur.sum ^ mat[cur.i][cur.j - 1]});
    }

    cout << ans << '\n';
}
