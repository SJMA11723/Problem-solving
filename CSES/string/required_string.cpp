/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct aho_corasick{
    const static int K = 26;
    const char index = 'A';

    struct vertex{
        int next[K];
        bool terminal = false;
        int p = -1;
        char p_edge;
        int link = -1;
        int terminal_link = -1;
        int go[K];
        vertex(int p = -1, char c = '$') : p(p), p_edge(c){
            fill(next, next + K, -1);
            fill(go, go + K, -1);
        }
    };

    vector<vertex> aho;

    aho_corasick(){
        aho.resize(1);
    }

    aho_corasick(int n){
        aho.resize(1);
        aho.reserve(n + 1);
    }

    void add_string(const string &s){
        int u = 0;
        for(char c : s){
            int e = c - index;
            if(aho[u].next[e] == -1){
                aho[u].next[e] = aho.size();
                aho.emplace_back(u, c);
            }
            u = aho[u].next[e];
        }
        aho[u].terminal = true;
    }

    int get_link(int u){
        if(aho[u].link == -1){
            if(!u || !aho[u].p) aho[u].link = 0;
            else aho[u].link = go(get_link(aho[u].p), aho[u].p_edge);
        }
        return aho[u].link;
    }

    int go(int u, char c){
        int e = c - index;
        if(aho[u].go[e] == -1){
            if(aho[u].next[e] != -1) aho[u].go[e] = aho[u].next[e];
            else aho[u].go[e] = !u ? 0 : go(get_link(u), c);
        }
        return aho[u].go[e];
    }

    int get_terminal_link(int u){
        if(aho[u].terminal_link == -1){
            if(!u || !aho[u].p) aho[u].terminal_link = 0;
            else aho[u].terminal_link = get_terminal_link(get_link(u));
        }
        return aho[u].terminal_link;
    }

    bool terminal(int u){
        return aho[u].terminal;
    }
};

struct matrix{
    int n;
    vector<vector<int>> mat;

    matrix(int _n, bool I = false){
        n = _n;
        mat.resize(n, vector<int>(n));
        if(I) for(int i = 0; i < n; ++i) mat[i][i] = 1;
    }

    vector<int> & operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix &b){
        matrix res(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                res[i][j] = 0;
                for(int k = 0; k < n; ++k){
                    res[i][j] += 1ll * mat[i][k] * b[k][j] % MOD;
                    if(res[i][j] >= MOD) res[i][j] -= MOD;
                }
            }
        }

        return res;
    }
};

matrix bin_exp(matrix &A, int n){
    if(!n) return matrix(A.n, 1);
    matrix tmp = bin_exp(A, n / 2);
    if(n & 1) return tmp * tmp * A;
    return tmp * tmp;
}

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    aho_corasick aho(s.size());
    aho.add_string(s);

    int N = aho.aho.size();
    matrix adj(N);
    for(int i = 0; i < N; ++i){
        for(char c = 'A'; c <= 'Z'; ++c){
            if(!aho.terminal(aho.go(i, c)) && !aho.get_terminal_link(aho.go(i, c))){
                adj[i][aho.go(i, c)] += 1;
            }
        }
    }

    matrix res = bin_exp(adj, n);
    int ans = bin_exp(26, n);
    for(int i = 0; i < N; ++i){
        ans += MOD - res[0][i];
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << '\n';
}
