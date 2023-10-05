/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000][12 * 1000 + 1];
bool processed[1000][12 * 1000 + 1];
int dispensers[1000][12];

int compute(int pos, int k){
    if(pos == n || k < 1) return 0;

    if(processed[pos][k]) return dp[pos][k];

    int maxi = compute(pos + 1, k);
    for(int i = 0; i < 12; ++i){
        if(i + 1 > k) break;
        maxi = max(maxi, dispensers[pos][i] + compute(pos + 1, k - i - 1));
    }

    processed[pos][k] = true;
    return dp[pos][k] = maxi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k; cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int suma = 0;
        for(int j = 0; j < 12; ++j){
            int x; cin >> x;
            suma += x;
            dispensers[i][j] = suma;
        }
    }

    cout << compute(0, k) << '\n';
}
