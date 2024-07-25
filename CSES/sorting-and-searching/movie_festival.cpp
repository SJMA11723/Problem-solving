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
    pair<int, int> arr[n];
    for(pair<int, int> &p : arr) cin >> p.second >> p.first;
    sort(arr, arr + n);

    int last = 0, ans = 0;
    for(auto [r, l] : arr){
        if(last <= l){
            last = r;
            ans++;
        }
    }
    cout << ans << '\n';
}

