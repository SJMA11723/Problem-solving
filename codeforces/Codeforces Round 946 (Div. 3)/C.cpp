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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<pair<int, int>, int> cnt_001, cnt_010, cnt_100;
    map<pair<int, int>, unordered_map<int, int>> cub_001, cub_010, cub_100;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;

        int64_t ans = 0;
        for(int i = 0; i + 2 < n; ++i){
            /// 001
            ans += cnt_001[{arr[i], arr[i + 1]}] - cub_001[{arr[i], arr[i + 1]}][ arr[i + 2] ];

            /// 010
            ans += cnt_010[{arr[i], arr[i + 2]}] - cub_010[{arr[i], arr[i + 2]}][ arr[i + 1] ];

            /// 100
            ans += cnt_100[{arr[i + 1], arr[i + 2]}] - cub_100[{arr[i + 1], arr[i + 2]}][ arr[i] ];

            cnt_001[{arr[i], arr[i + 1]}]++;
            cnt_010[{arr[i], arr[i + 2]}]++;
            cnt_100[{arr[i + 1], arr[i + 2]}]++;

            cub_001[{arr[i], arr[i + 1]}][ arr[i + 2] ]++;
            cub_010[{arr[i], arr[i + 2]}][ arr[i + 1] ]++;
            cub_100[{arr[i + 1], arr[i + 2]}][ arr[i] ]++;
        }

        cnt_001.clear();
        cnt_010.clear();
        cnt_100.clear();

        cub_001.clear();
        cub_010.clear();
        cub_100.clear();

        cout << ans << '\n';
    }
}
