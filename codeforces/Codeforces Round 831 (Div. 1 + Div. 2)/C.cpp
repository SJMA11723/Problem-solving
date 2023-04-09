#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);
        int ans = 2e9;

        for(int i = n - 1; 0 < i - 1; --i){
            ans = max(ans, 2 * arr[i] - arr[0] - arr[i - 1]);
        }

        cout << ans << '\n';
    }
}
