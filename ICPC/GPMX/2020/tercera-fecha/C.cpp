#include<bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int64_t n, k;
        cin >> n >> k;

        cout << (n + 1) * (n + 2) / 2 % MOD * (k + 1) % MOD << '\n';
    }

    return 0;
}
