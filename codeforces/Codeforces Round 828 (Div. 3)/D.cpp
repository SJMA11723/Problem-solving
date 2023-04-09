#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        int factor = 0, ans = 0;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            while(x % 2 == 0){
                factor++;
                x /= 2;
            }

            int tmp = i + 1;
            int f2 = 0;
            while(tmp % 2 == 0){
                f2++;
                tmp /= 2;
            }
            arr[i] = f2;
        }

        sort(arr, arr + n);

        for(int i = n; 0 < i && factor < n; --i){

            if(arr[i - 1]) ans++;
            factor += arr[i - 1];
        }

        if(n <= factor){
            cout << ans << '\n';
        } else cout << "-1\n";
    }
}