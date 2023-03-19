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
        int n, q;
        cin >> n >> q;
        long long arr[n + 1];
        arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        while(q--){
            int a, b;
            long long k;
            cin >> a >> b >> k;
            long long sum = arr[n] - arr[b] + arr[a - 1] + k * (b - a + 1);
            if(sum % 2) cout << "yes\n";
            else cout << "no\n";
        }
    }
}
