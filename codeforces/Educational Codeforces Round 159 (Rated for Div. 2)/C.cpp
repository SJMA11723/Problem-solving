/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long arr[n];
        set<long long> mset;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            mset.insert(arr[i]);
        }
        if(n == 1){
            cout << "1\n";
            continue;
        }
        sort(arr, arr + n);
        long long gcd = 0;
        for(int i = 0; i < n - 1; ++i)
            gcd = __gcd(gcd, arr[n - 1] - arr[i]);

        long long a_n = arr[n - 1] - gcd;
        while(mset.count(a_n)) a_n -= gcd;

        long long ans = 0;
        for(int i = 0; i < n; ++i) ans += (arr[n - 1] - arr[i]) / gcd;
        ans += (arr[n - 1] - a_n) / gcd;
        cout << ans << '\n';
    }
}
