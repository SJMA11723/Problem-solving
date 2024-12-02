/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

pair<int, pair<int, int>> solve(int l, int r, int arr[]){
    if(l == r) return {0, {arr[l], arr[r]}};

    int mid = l + (r - l) / 2;
    pair<int, pair<int, int>> L = solve(l, mid, arr);
    pair<int, pair<int, int>> R = solve(mid + 1, r, arr);

    int a, b, c, d;
    tie(a, b) = L.second;
    tie(c, d) = R.second;

    int cnt = L.first + R.first + (b + 1 != c);
    bool ok = (b + 1 == c || d + 1 == a) && L.first != -1 && R.first != -1;

    return {ok ? cnt : -1, {min(a, c), max(b, d)}};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int m; cin >> m;
        int arr[m];
        for(int &x : arr) cin >> x;
        cout << solve(0, m - 1, arr).first << '\n';
    }
}
