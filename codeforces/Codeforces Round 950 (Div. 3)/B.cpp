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
        int n, f, k; cin >> n >> f >> k;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        int fav = arr[f - 1];
        sort(arr, arr + n, greater<int>());

        if(k == n) cout << "YES\n";
        else if(arr[k - 1] > fav) cout << "NO\n";
        else if(arr[k - 1] < fav) cout << "YES\n";
        else if(arr[k] == fav) cout << "MAYBE\n";
        else cout << "YES\n";
    }
}
