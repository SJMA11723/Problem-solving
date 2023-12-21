/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct op{
    int i, j, x, y;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        vector<op> ans;
        for(int i = 1; i < n; i += 2){
            int mini = min(arr[i], arr[i - 1]);
            ans.push_back({i, i + 1, mini, (int)(1e9 + 7)});
            arr[i] = 1e9 + 7;
        }
        cout << ans.size() << '\n';
        for(op &o : ans) cout << o.i << ' ' << o.j << ' ' << o.x << ' ' << o.y << '\n';
    }
}
