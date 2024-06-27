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
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    while(k--){
        int x; cin >> x;
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(arr[mid] > x) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
