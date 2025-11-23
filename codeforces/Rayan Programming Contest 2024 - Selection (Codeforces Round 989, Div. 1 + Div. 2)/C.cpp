/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};
const string dir = "DURL";

char contra(char c){
    if(c == 'U') return 'D';
    if(c == 'D') return 'U';
    if(c == 'L') return 'R';
    if(c == 'R') return 'L';
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int ans = n * m;
        char mat[n][m], cnt[n][m];
        bool vis[n][m];
        memset(cnt, 4, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];

            if(!i) cnt[i][j]--;
            if(!j) cnt[i][j]--;
            if(i == n - 1) cnt[i][j]--;
            if(j == m - 1) cnt[i][j]--;

            if((!i && mat[i][j] == 'U') || (i == n - 1 && mat[i][j] == 'D') ||
                (!j && mat[i][j] == 'L') || (j == m - 1 && mat[i][j] == 'R') || !cnt[i][j]){
                q.push({i, j});
                vis[i][j] = 1;
                ans--;
            }
        }

        while(q.size()){
            int i, j;
            tie(i, j) = q.front(); q.pop();

            for(int k = 0; k < 4; ++k){
                int ni = i + di[k];
                int nj = j + dj[k];

                if(ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj]) continue;

                cnt[ni][nj]--;
                if(!cnt[ni][nj] || mat[ni][nj] == contra(dir[k])){
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                    ans--;
                }
            }
        }
        cout << ans << '\n';
    }
}