#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        arr[i] -= i;
    }
    sort(arr, arr + n);
    int x;
    if(n % 2) x = arr[n / 2];
    else x = (arr[n / 2] + arr[n / 2 - 1]) / 2;

    int64_t ans = 0;
    for(int i = 0; i < n; ++i) ans += abs(arr[i] - x);
    cout << ans << '\n';
}
