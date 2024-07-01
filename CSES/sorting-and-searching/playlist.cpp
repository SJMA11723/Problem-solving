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
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int ans = 0, l = 0;
    set<int> mset;
    for(int r = 0; r < n; ++r){
        while(mset.count(arr[r])) mset.erase(arr[l++]);
        mset.insert(arr[r]);
        ans = max(ans, (int)mset.size());
    }
    cout << ans << '\n';
}
