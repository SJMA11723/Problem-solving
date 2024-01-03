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
    int arr[n], maxi = 0, mini = INT_MAX;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == maxi){
            ans += i;
            for(int j = i - 1; 0 <= j; --j) swap(arr[j], arr[j + 1]);
            break;
        }
    }

    for(int i = n - 1; 0 <= i; --i){
        if(arr[i] == mini){
            ans += n - i - 1;
            break;
        }
    }
    cout << ans << '\n';
}
