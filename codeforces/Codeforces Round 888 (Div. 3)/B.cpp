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
        vector<int> odd, odd_idx, even, even_idx;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x % 2) odd.push_back(x), odd_idx.push_back(i);
            else even.push_back(x), even_idx.push_back(i);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        int arr[n];
        for(int i = 0; i < odd.size(); ++i) arr[odd_idx[i]] = odd[i];
        for(int i = 0; i < even.size(); ++i) arr[even_idx[i]] = even[i];

        cout << (is_sorted(arr, arr + n) ? "YES\n" : "NO\n");
    }
}
