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
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);

    int k; cin >> k;
    while(k--){
        int a, b; cin >> a >> b;
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(arr[mid] > b) r = mid;
            else l = mid + 1;
        }
        int up = l - 1;
        l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(arr[mid] >= a) r = mid;
            else l = mid + 1;
        }
        int down = l;
        cout << up - down + 1 << ' ';
    }
    cout << '\n';
}
