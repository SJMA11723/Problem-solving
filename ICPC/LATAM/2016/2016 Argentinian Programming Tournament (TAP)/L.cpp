#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[k], cnt12 = 0;
    for(int &x : arr){
        cin >> x;
        cnt12 += x <= 2;
    }
    if(k == 1){
        cout << "S\n";
        return 0;
    }

    if(n == 2){
        cout << "N\n";
        return 0;
    }

    if(cnt12 == 2 && k == 2){
        cout << "N\n";
        return 0;
    }

    int pos = max_element(arr, arr + k) - arr;
    cnt12 -= arr[0] <= 2;
    cnt12 -= arr[k - 1] <= 2;

    bool ok = (pos && pos  + 1 < k ? arr[pos - 1] != arr[pos + 1] : true) && (k <= 2 * (n - 1)) && !cnt12;
    for(int i = pos - 1; 0 <= i; --i) ok &= arr[i + 1] - 2 <= arr[i] && arr[i] < arr[i + 1];
    for(int i = pos + 1; i < k; ++i) ok &= arr[i - 1] - 2 <= arr[i] && arr[i] < arr[i - 1];
    cout << (ok ? "S\n" : "N\n");
}
