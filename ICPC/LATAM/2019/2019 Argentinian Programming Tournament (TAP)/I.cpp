#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<bool> diag[n];
    for(int i = 0; i < n; ++i) diag[i].resize(n - i);

    for(int i = 0; i < m; ++i){
        int k, a, b; cin >> k >> a >> b;
        a--, b--;
        int d = abs(a - b);
        diag[d][min(a, b)] = !diag[d][min(a, b)];
        if(min(a, b) + k < diag[d].size()) diag[d][min(a, b) + k] = !diag[d][min(a, b) + k];
    }

    for(int i = 0; i < n; ++i){
        bool acc = false;
        for(int j = 0; j < diag[i].size(); ++j){
            if(diag[i][j]) acc = !acc;
            diag[i][j] = acc;
        }
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
        //cout << abs(a - b) << ' ' << min(a, b) << ' ' << diag[abs(a - b)].size() << endl;
        cout << (diag[abs(a - b)][min(a, b)] ? "SI\n" : "NO\n");
        //cout << endl;
    }
}
