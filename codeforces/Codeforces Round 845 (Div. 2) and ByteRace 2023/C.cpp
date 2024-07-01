/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXM 100'000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> div[MAXM + 1];
    for(int i = 1; i <= MAXM; ++i)
        for(int j = i; j <= MAXM; j += i) div[j].push_back(i);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int arr[n];
        for(int &x : arr) cin >> x;
        sort(arr, arr + n);

        int cub[m + 1] = {};
        int r = -1, ans = INT_MAX, cnt = 0;

        for(int l = 0; l < n; ++l){
            while(r + 1 < n && cnt < m){
                r++;
                for(int d : div[arr[r]]){
                    if(d > m) break;
                    cnt += ++cub[d] == 1;
                }
            }

            if(cnt == m) ans = min(ans, arr[r] - arr[l]);

            for(int d : div[arr[l]]){
                if(d > m) break;
                cnt -= --cub[d] == 0;
            }
        }

        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }
}
