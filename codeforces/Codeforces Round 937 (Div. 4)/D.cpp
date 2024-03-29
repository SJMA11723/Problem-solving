/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100'001

using namespace std;

bool dp[MAXN], processed[MAXN];
vector<int> decimals;

bool compute(int n){
    if(processed[n]) return dp[n];
    processed[n] = true;
    int res = false;
    for(int d : decimals){
        if(n % d) continue;
        res = res || compute(n / d);
        if(res) break;
    }
    return dp[n] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i < (1 << 5); ++i){
        int pot = 1, tmp = i;
        int num = 0;
        for(int j = 0; j < 5; ++j){
            num += (tmp % 2) * pot;
            pot *= 10;
            tmp /= 2;
        }
        decimals.push_back(num);
    }
    processed[1] = dp[1] = true;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(compute(n)) cout << "YES\n";
        else cout << "NO\n";
    }
}
