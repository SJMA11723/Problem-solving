#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        l--, r--;
        int ans = 0, sum = 0;
        map<int, int> cnt;
        for(int i = l; i <= r; ++i){
            sum += arr[i];
            if(sum == i - l + 1) ans++;
            ans += cnt[sum - i];
            cnt[sum - (i + 1) + 1]++;
        }
        cout << ans << '\n';
    }
}