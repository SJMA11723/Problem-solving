#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define sz(x) (x).size()
#define all(x) (x).first(), (x).end()
#define pb push_back
#define DEBUG if(deb)

const int MOD = 1e9 + 7;

const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

struct pos{
    int a, b;
    int c, d;
    int dist;
};


bool valid_cell(int i, int j, const vector<vector<char>> &M){
    int n = M.size();
    int m = M[0].size();
    if(i < 0 || j < 0 || i >= n || j >= m || M[i][j] == 'X') return false;
    return true;
}

int bfs(int a, int b, int c, int d, int x, int y, const vector<vector<char>> &A, const vector<vector<char>> &B){
    int n = A.size();
    int m = A[0].size();
    vector<vector<vector<vector<bool>>>> vis(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m))));

    queue<pos> q;
    q.push(pos{a, b, c, d, 0});
    vis[a][b][c][d] = 1;
    while(q.size()){
        pos cur = q.front(); q.pop();

        if(cur.c == x && cur.d == y){
            return cur.dist;
        }
        //cout << cur. a << ' ' << cur.b << ' ' << cur.c << ' ' << cur.d << ' ' << cur.dist << '\n';

        for(int k = 0; k < 4; ++k){
            int na = cur.a + di[k];
            int nb = cur.b + dj[k];
            int nc = cur.c + di[k];
            int nd = cur.d + dj[k];

            if(!valid_cell(na, nb, A)) continue;
            if(!valid_cell(nc, nd, B)){
                nc -= di[k];
                nd -= dj[k];
            }
            if(vis[na][nb][nc][nd]) continue;
            
            vis[na][nb][nc][nd] = 1;
            q.push(pos{na, nb, nc, nd, cur.dist + 1});
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<char>> A(n, vector<char>(m)), B = A;
        int a, b, c, d, x, y;
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> A[i][j];
            if(A[i][j] == 'S'){
                a = i;
                b = j;
            }
        }

        for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> B[i][j];
            if(B[i][j] == 'S'){
                c = i;
                d = j;
            } else if(B[i][j] == 'D'){
                x = i;
                y = j;
            }
        }

        cout << bfs(a, b, c, d, x, y, A, B) << '\n';
    }
}