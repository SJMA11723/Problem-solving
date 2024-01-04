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
        vector<int> five;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            while(arr[i] % 10 != 2 && arr[i] % 10) arr[i] += arr[i] % 10;
            if(arr[i] % 10 == 0) five.push_back(arr[i]);
            arr[i] %= 20;
        }
        bool ok1 = *min_element(arr, arr + n) == *max_element(arr, arr + n);
        bool ok2 = five.empty() || *min_element(five.begin(), five.end()) == *max_element(five.begin(), five.end());
        cout << (ok1 && ok2 ? "YES\n" : "NO\n");
    }
}
