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
        int arr[n];
        bool ok = true;
        cin >> arr[0];
        for(int i = 1; i < n; ++i){
            cin >> arr[i];
            if(arr[i - 1] % 2 != arr[i] % 2) ok = false;
        }
        if(!ok){
            cout << "-1\n";
            continue;
        }

        vector<int> ans;
        for(int k = 0; k < 40; ++k){
            sort(arr, arr + n);
            if(!arr[n - 1]) break;

            int x = arr[n / 2];
            if(x % 2 == 0) x = arr[n - 1] / 2;

            ans.push_back(x);
            for(int i = 0; i < n; ++i) arr[i] = abs(arr[i] - x);
        }

        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
