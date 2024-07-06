/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int arr[], int l, int r, int k){
    if(!k){
        sort(arr + l, arr + r);
        return;
    }
    if(r - l == 1){
        arr[l] = -1;
        return;
    }

    k -= 2;

    int mid = (l + r) / 2;

    swap(arr[mid - 1], arr[mid]);

    if(k % 4){
        solve(arr, l, mid, k / 2 - 1);
        solve(arr, mid, r, k / 2 + 1);
    } else {
        solve(arr, l, mid, k / 2);
        solve(arr, mid, r, k / 2);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    if(k % 2 == 0){
        cout << "-1\n";
        return 0;
    }

    int ans[n];
    for(int i = 0; i < n; ++i) ans[i] = i + 1;
    solve(ans, 0, n, k - 1);

    if(*min_element(ans, ans + n) == -1) cout << "-1\n";
    else for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
