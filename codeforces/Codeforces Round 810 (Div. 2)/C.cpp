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
        int64_t n, m;
        int k; cin >> n >> m >> k;
        int64_t arr[k];
        for(int64_t &x : arr) cin >> x;

        if(n * m <= *max_element(arr, arr + k)){
            cout << "Yes\n";
            continue;
        }

        bool ok = false;
        for(int r = 0; r < 2; ++r){
            int64_t cnt = 0;
            bool odd = false;
            for(int64_t x : arr){
                int64_t columns = x / n;
                if(columns == 1) continue;
                if(columns > 2) odd = true;
                cnt += columns;
            }

            if(cnt >= m && (m % 2 == 0 || odd)) ok = true;

            swap(n, m);
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}
