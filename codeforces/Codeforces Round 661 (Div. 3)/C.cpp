/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x  : arr) cin >> x;
        sort(arr, arr + n);

        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int s = arr[i] + arr[j], cnt = 1;
                int l = i + 1, r = j - 1;
                while(l < r){
                    if(arr[l] + arr[r] < s) l++;
                    else if(arr[l] + arr[r] == s) cnt++, l++, r--;
                    else if(arr[l] + arr[r] > s) r--;
                }
                ans = max(ans, cnt);
            }
        }
        cout << ans << '\n';
    }
}
