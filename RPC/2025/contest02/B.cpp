#include <bits/stdc++.h>

using namespace std;

struct adj{
    int U, R, D, L;
};

struct pos{
    int u, k, dir, lt;
};

char D(int x){
    if(x == 0) return 'U';
    if(x == 1) return 'D';
    if(x == 2) return 'L';
    return 'R';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    adj arr[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].U;
        cin >> arr[i].R;
        cin >> arr[i].D;
        cin >> arr[i].L;
    }

    if(n == 1){
        cout << "0\n";
        return 0;
    }

    /// UDLR
    int dist[n + 1][k + 1][4][3];
    memset(dist, 0, sizeof(dist));
    queue<pos> q;
    q.push({1, 0, 0, 0}); dist[1][0][0][0] = 1;
    q.push({1, 0, 1, 0}); dist[1][0][1][0] = 1;
    q.push({1, 0, 2, 0}); dist[1][0][2][0] = 1;
    q.push({1, 0, 3, 0}); dist[1][0][3][0] = 1;

    int ans = INT_MAX;
    while(q.size()){
        pos cur = q.front();
        q.pop();

        cout << "cur: " << cur.u << ' ' << cur.k << ' ' << D(cur.dir) << ' ' << cur.lt << ' ' << dist[cur.u][cur.k][cur.dir][cur.lt] << '\n';

        if(cur.u == n){
            ans = min(ans, dist[cur.u][cur.k][cur.dir][cur.lt]);
        }

        /// U
        if(arr[cur.u].U && cur.dir != 1){
            int v = arr[cur.u].U;
            int nk = cur.k;
            int nlt = cur.lt;

            if(cur.dir != 0){
                if(cur.dir == 2 && cur.lt != 2){ /// <-L
                    nk++;
                    nlt = 2;
                } else if(cur.dir == 3 && cur.lt != 1){ /// R->
                    nk++;
                    nlt = 1;
                }
            } else nlt = 0;

            if(nk <= k && !dist[v][nk][0][nlt]){
                q.push({v, nk, 0, nlt});
                dist[v][nk][0][nlt] = dist[cur.u][cur.k][cur.dir][cur.lt] + 1;
                cout << "Agrega U " << v << '\n';
            }
        }

        /// D
        if(arr[cur.u].D && cur.dir != 0){
            int v = arr[cur.u].D;
            int nk = cur.k;
            int nlt = cur.lt;

            if(cur.dir != 1){
                if(cur.dir == 2 && cur.lt != 1){ /// <-L
                    nk++;
                    nlt = 1;
                } else if(cur.dir == 3 && cur.lt != 2){ /// R->
                    nk++;
                    nlt = 2;
                }
            } else nlt = 0;

            if(nk <= k && !dist[v][nk][1][nlt]){
                q.push({v, nk, 1, nlt});
                dist[v][nk][1][nlt] = dist[cur.u][cur.k][cur.dir][cur.lt] + 1;
                cout << "Agrega D " << v << '\n';
            }
        }

        /// L
        if(arr[cur.u].L && cur.dir != 3){
            int v = arr[cur.u].L;
            int nk = cur.k;
            int nlt = cur.lt;

            if(cur.dir != 2){
                if(cur.dir == 0 && cur.lt != 1){ /// U
                    nk++;
                    nlt = 1;
                } else if(cur.dir == 1 && cur.lt != 2){ /// D
                    nk++;
                    nlt = 2;
                }
            } else nlt = 0;

            if(nk <= k && !dist[v][nk][2][nlt]){
                q.push({v, nk, 2, nlt});
                dist[v][nk][2][nlt] = dist[cur.u][cur.k][cur.dir][cur.lt] + 1;
                cout << "Agrega L" << v << '\n';
            }
        }

        /// R
        if(arr[cur.u].R && cur.dir != 2){
            int v = arr[cur.u].R;
            int nk = cur.k;
            int nlt = cur.lt;

            if(cur.dir != 3){
                if(cur.dir == 0 && cur.lt != 2){ /// U
                    nk++;
                    nlt = 2;
                } else if(cur.dir == 1 && cur.lt != 1){ /// D
                    nk++;
                    nlt = 1;
                }
            } else nlt = 0;

            if(nk <= k && !dist[v][nk][3][nlt]){
                q.push({v, nk, 3, nlt});
                dist[v][nk][3][nlt] = dist[cur.u][cur.k][cur.dir][cur.lt] + 1;
                cout << "Agrega R " << v << '\n';
            }
        }
        cout << '\n';
    }

    if(ans != INT_MAX) cout << ans << '\n';
    else cout << "impossible\n";
}
