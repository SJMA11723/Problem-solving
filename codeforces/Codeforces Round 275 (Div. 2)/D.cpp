/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(S, j) ((S) & (1ll << (j)))
#define set_bit(S, j) (S |= (1ll << (j)))

using namespace std;

struct sparse_table{
    int n, NEUTRO;
    vector<vector<int>> ST;
    vector<int> lg2;
    int f(int a, int b){return a & b;}

    sparse_table(int _n, int data[]){
        n = _n;
        NEUTRO = INT_MAX;
        lg2.resize(n + 1);
        lg2[1] = 0;
        for(int i = 2; i <= n; ++i) lg2[i] = lg2[i / 2] + 1;
        ST.resize(lg2[n] + 1, vector<int>(n + 1, NEUTRO));
        for(int i = 0; i < n; ++i) ST[0][i] = data[i];
        for(int k = 1; k <= lg2[n]; ++k){
            int fin = (1 << k) - 1;
            for(int i= 0; i  + fin < n; ++i)
                ST[k][i] = f(ST[k - 1][i], ST[k - 1][i + (1 << (k - 1))]);
        }
    }

    int query(int l, int r){
         if(l > r) return NEUTRO;
         int lg = lg2[r - l + 1];
         return f(ST[lg][l], ST[lg][r - (1 << lg) + 1]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int l[m], r[m], q[m];
    vector<int> acc[n + 1];
    for(int i = 0; i < m; ++i){
        cin >> l[i] >> r[i] >> q[i];
        l[i]--, r[i]--;
        acc[l[i]].push_back(q[i]);
        acc[r[i] + 1].push_back(-q[i]);
    }

    int ans[n] = {}, cub[30] = {};
    for(int i = 0; i < n; ++i){
        for(int x : acc[i])
            for(int j = 0; j < 30; ++j)
                if(is_on(abs(x), j)) cub[j] += x / abs(x);

        for(int j = 0; j < 30; ++j) if(cub[j]) set_bit(ans[i], j);
    }

    sparse_table ST(n, ans);
    bool ok = true;
    for(int i = 0; i < m; ++i){
        if(ST.query(l[i], r[i]) != q[i]){
            ok = false;
            break;
        }
    }

    if(ok){
        cout << "YES\n";
        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    } else cout << "NO\n";
}
