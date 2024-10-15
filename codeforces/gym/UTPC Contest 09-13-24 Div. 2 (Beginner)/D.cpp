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
    int n, m; cin >> n >> m;
    int64_t arr[n];
    cin >> arr[0];
    for(int i = 1; i < n; ++i){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    while(m--){
        int q; cin >> q;
        if(!q){
            cout << "0\n";
            continue;
        }
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(arr[mid] < q) l = mid + 1;
            else r = mid;
        }
        if(l == n) cout << "-1\n";
        else cout << l + 1 << '\n';
    }
}
