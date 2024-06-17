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
        for(int i = 0; i < n; ++i) cin >> arr[i];

        if(*max_element(arr, arr + n) == *min_element(arr, arr + n)){
            cout << "NO\n";
            continue;
        }

        sort(arr, arr + n, greater<int>());

        bool printed[n] = {};
        int cnt = 0, ant = 0;
        cout << "YES\n";
        for(int i = 0; i < n; ++i){
            if(ant == arr[i]) continue;
            printed[i] = true;
            ant = arr[i];
            cout << arr[i] << " \n"[++cnt == n];
        }

        for(int i = 0; i < n; ++i){
            if(printed[i]) continue;
            cout << arr[i] << " \n"[++cnt == n];
        }
    }
}
