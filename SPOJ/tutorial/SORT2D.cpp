/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int, int> arr[n];
        for(auto &p : arr) cin >> p.first >> p.second;
        sort(arr, arr + n, cmp);
        for(auto &p : arr) cout << p.first << ' ' << p.second << '\n';
    }
}
