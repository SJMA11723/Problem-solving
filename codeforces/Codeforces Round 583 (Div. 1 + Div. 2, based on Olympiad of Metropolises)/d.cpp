/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ull MOD = (1ll << 61) - 1;
// tal vez con dos modulos (o tres) salga usando 64 bits

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    char mat[n][m];
    __int128_t paths[n][m];
    bool vis[n][m];
    memset(paths, 0, sizeof(paths));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        cin >> mat[i][j];
        if(mat[i][j] == '#'){
            paths[i][j] = 0;
            continue;
        } else if(!i && !j){
            paths[i][j] = 1;
            vis[i][j] = 1;
            continue;
        }

        if(i){
            paths[i][j] += paths[i - 1][j];
            if(vis[i - 1][j]) vis[i][j] = 1;
        }
        if(j){
            paths[i][j] += paths[i][j - 1];
            if(vis[i][j - 1]) vis[i][j] = 1;
        }
    }

    if(!vis[n - 1][m - 1]){
        cout << "0\n";
        return 0;
    }

    __int128_t paths2[n][m];
    memset(paths2, 0, sizeof(paths2));
    for(int i = n - 1; 0 <= i; --i)
    for(int j = m - 1; 0 <= j; --j){
        if(mat[i][j] == '#'){
            paths2[i][j] = 0;
            continue;
        } else if(i + 1 == n && j + 1 == m){
            paths2[i][j] = 1;
            continue;
        }
        
        if(i + 1 < n) paths2[i][j] += paths2[i + 1][j];
        if(j + 1 < m) paths2[i][j] += paths2[i][j + 1];
    }

    int cnt = 0, ans = 2;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) if(paths[i][j] * paths2[i][j] == paths[n - 1][m - 1]) cnt++;
    if(cnt > 2) ans = 1;
    cout << ans << '\n';
}
