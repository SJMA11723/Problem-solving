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
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); ++i)
            while(i + 1 < arr.size() && arr[i + 1] - arr[i] <= 1) arr.erase(arr.begin() + i);
        cout << (arr.size() == 1 ? "YES\n" : "NO\n");
    }
}
