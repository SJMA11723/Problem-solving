/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1001

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        int64_t acc[MAXN][MAXN];
        memset(acc, 0, sizeof(acc));
        for(int i = 0; i < n; ++i){
            int64_t a, b; cin >> a >> b;
            acc[a][b] += a * b;
        }

        for(int i = 1; i < MAXN; ++i)
            for(int j = 1; j < MAXN; ++j)
                acc[i][j] += acc[i][j - 1] + acc[i - 1][j] - acc[i - 1][j - 1];

        while(q--){
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            if(hb < hs || wb < ws) cout << "0\n";
            else cout << max(acc[hb - 1][wb - 1] - acc[hs][wb - 1] - acc[hb - 1][ws] + acc[hs][ws], 0ll) << '\n';
        }
    }
}
