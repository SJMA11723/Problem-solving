
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
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    if(n < 3){
        cout << "0\n";
        return 0;
    }

    int ans = INT_MAX;
    for(int c1 = -1; c1 <= 1; ++c1){
        for(int c2 = -1; c2 <= 1; ++c2){
            int d = (arr[1] + c2) - (arr[0] + c1);
            bool ok = true;
            int prv = arr[1] + c2, cnt = (c1 != 0) + (c2 != 0);
            for(int i = 2; i < n; ++i){
                if(arr[i] - d == prv) prv = arr[i];
                else if(arr[i] + 1 - d == prv) prv = arr[i] + 1, cnt++;
                else if(arr[i] - 1 - d == prv) prv = arr[i] - 1, cnt++;
                else {
                    ok = false;
                    break;
                }
            }
            if(ok) ans = min(ans, cnt);
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
