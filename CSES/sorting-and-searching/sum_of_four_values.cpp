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
    int n, x; cin >> n >> x;
    int arr[n];
    for(int &v : arr) cin >> v;

    map<int, vector<pair<int, int>>> cub;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j) cub[arr[i] + arr[j]].push_back({i, j});

    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            for(auto [k, l] : cub[x - arr[i] - arr[j]])
            if(k != i && k != j && l != i && l != j){
                cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << ' ' << l + 1 << '\n';
                return 0;
            }
    cout << "IMPOSSIBLE\n";
}
