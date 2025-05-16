/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int64_t INF = 1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    int arr[n];
    for(int &x : arr) cin >> x;
    sort(arr, arr + n);


    int64_t dp[2][3];
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = INF;

    for(int i = 1; i <= n; ++i){
        bool i1 = i & 1, i0 = !i1;
        for(int j = 0; j < 3; ++j){
            /// lo compro individual
            dp[i1][j] = dp[i0][j] + arr[i - 1] / 100 * (100 - q);

            /// lo agrego a un grupo
            if(j < 2){ /// aqui estoy agregando el más caro o segundo más caro del grupo
                dp[i1][j] = min(dp[i1][j], dp[i0][j + 1] + arr[i - 1]);
            } else { /// aqui lo estoy eligiendo como el mas barato del grupo
                dp[i1][j] = min(dp[i1][j], dp[i0][0]);
            }
        }
    }

    cout << dp[n & 1][0] << '\n';
}
