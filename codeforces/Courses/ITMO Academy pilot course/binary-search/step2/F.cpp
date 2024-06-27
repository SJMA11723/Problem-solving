/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(string &t, string &p, int arr[], int k){
    int n = t.size(), idx = 0;

    bool valid[n]; fill(valid, valid + n, true);
    for(int i = 0; i < k; ++i) valid[arr[i]] = false;

    for(int i = 0; i < n; ++i){
        if(!valid[i]) continue;
        if(t[i] == p[idx]) idx++;
    }

    return idx == p.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t, p; cin >> t >> p;
    int arr[t.size()];
    for(int i = 0; i < t.size(); ++i){
        cin >> arr[i];
        arr[i]--;
    }
    int l = 1, r = t.size();
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(t, p, arr, mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
}
