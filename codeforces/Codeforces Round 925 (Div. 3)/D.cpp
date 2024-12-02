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
        int n, x, y;
        cin >> n >> x >> y;
        map<int, map<int, int>> cnt;
        int arr[n];
        for(int &v : arr){
            cin >> v;
            cnt[v % x][v % y]++;
        }

        int64_t ans = 0;
        for(int &v : arr){
            int rx = v % x;
            int ry = v % y;
            int crx = (x - rx) % x;

            if(rx == crx) ans--;
            ans += cnt[crx][ry];
        }
        ans >>= 1;
        cout << ans << '\n';
    }
}

