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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sum += arr[i];
        }

        if(sum % 3 == 0){
            cout << "0\n";
            continue;
        }

        bool ok = false;
        for(int i = 0; i < n; ++i)
            if((sum - arr[i]) % 3 == 0) ok = true;

        if(ok) cout << "1\n";
        else cout << 3 - sum % 3 << '\n';
    }
}
