/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> primes;
    for(int i = 2; i < 1000; ++i)
        if(is_prime(i)) primes.push_back(i);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int coloring[n] = {};
        int cnt = 1, colored = 0;
        for(int p : primes){
            bool change = false;
            for(int i = 0; i < n; ++i){
                if(coloring[i] || arr[i] % p) continue;
                coloring[i] = cnt;
                colored++;
                change = true;
            }
            if(colored == n) break;
            if(change) cnt++;
        }
        cout << cnt << '\n';
        for(int i = 0; i < n; ++i) cout << coloring[i] << ' ';
        cout << '\n';
    }
}
