/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int compute(int n, int k){
    if(k <= (n + 1) / 2) return 2 * k - 1;
    return 2 * compute(n / 2, k - (n + 1) / 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        cout << compute(n, k) << '\n';
    }
}
