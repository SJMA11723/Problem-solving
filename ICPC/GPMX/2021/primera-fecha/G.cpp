/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int m;
unordered_map<int, bool> dp, processed;

bool gana_actual(int n){
    if(n <= m || __builtin_popcount(n) % 2) return true;

    if(processed[n]) return dp[n];
    processed[n] = true;

    bool gana = false;
    for(int x = m; 1 <= x && !gana; --x){
        gana = gana || !gana_actual(n - x);
    }
    return (dp[n] = gana);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n >> m;

    for(int i = 1; i <= 50; ++i){
        cout << setw(2) << setfill('0') << i << ": ";
        for(int j = 5; 0 <= j; --j)
            cout << (bool)(i & (1 << j) );
        cout << '\n';
    }

    if(gana_actual(n)) cout << "Pay the bill\n";
    else cout << "Free snacks!\n";
}
