#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        long long n, res = 0;

        cin >> n;

        long long arr[n];

        for(int i = 0; i < n; ++i) cin >> arr[i];

        sort(arr, arr + n);
        reverse(arr, arr + n);

        for(int i = 0; i < n; ++i){
            if(i % 2){
                if(arr[i] % 2) res -= arr[i];
            } else {
                if(arr[i] % 2 == 0) res += arr[i];
            }
        }

        if(res == 0) cout << "Tie\n";
        else if(res < 0) cout << "Bob\n";
        else cout << "Alice\n";
    }
}