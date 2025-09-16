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

int id(int i, int j){
    if(i < 0 || j < 0 || i >= 3 || j >= 3) return 0;
    return 3 * i + j + 1;
}

bool check_win(char turn, char vis[]){
    // diagonal
    bool ok = true;
    for(int i = 0; i < 3; ++i) ok = ok && turn == vis[id(i, i)];
    if(ok) return true;

    // antidiagonal
    ok = true;
    for(int i = 0; i < 3; ++i) ok = ok && turn == vis[id(2 - i, i)];
    if(ok) return true;

    // horizontal
    for(int i = 0; i < 3; ++i){
        ok = true;
        for(int j = 0; j < 3; ++j) ok = ok && turn == vis[id(i, j)];
        if(ok) return true;
    }

    // vertical
    for(int i = 0; i < 3; ++i){
        ok = true;
        for(int j = 0; j < 3; ++j) ok = ok && turn == vis[id(j, i)];
        if(ok) return true;
    }

    return false;
}

char rev(char X){
    return X == 'X' ? 'O' : 'X';
}

int play(char turn, char vis[], vi prv[]){
    int res = -1;
    if(check_win(turn, vis)) return 1;
    if(check_win(rev(turn), vis)) return -1;

    bool any = false;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            bool ok = true;
            int u = id(i, j);
            if(vis[u]) continue;
            
            // checo restricciones
            for(int idx : prv[u]){
                if(!vis[idx]){
                    ok = false;
                    break;
                }
            }
            if(!ok) continue;

            any = true;
            vis[u] = turn;
            if(turn == 'X') res = max(res, -play('O', vis, prv));
            else res = max(res, -play('X', vis, prv));
            vis[u] = 0;
        }
    }
    return any ? res : 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    set<pii> rest;
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        rest.insert({a, b});
    }

    vi prv[10];
    for(pii p : rest) prv[p.se].pb(p.fi);

    char vis[10] = {};
    int res = play('X', vis, prv);
    if(res > 0) cout << "X\n";
    else if(res < 0) cout << "O\n";
    else cout << "E\n";
}