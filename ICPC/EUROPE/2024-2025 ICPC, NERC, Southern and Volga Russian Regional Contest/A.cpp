#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int &x : arr) cin >> x;
    int64_t sum = 0;
    for(int i = 0; i < n; ++i){
        int b; cin >> b;
        arr[i] /= b;
        sum += arr[i];
    }

    for(int i = 0; i < n; ++i){
        sum -= arr[i];
        int c = max(0ll, k - sum);

        if(c <= arr[i]) k -= c, cout << c << " \n"[i + 1 == n];
        else cout << 0 << " \n"[i + 1 == n];
    }
}
