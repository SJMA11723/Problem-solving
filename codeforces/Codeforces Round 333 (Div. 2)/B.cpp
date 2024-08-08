/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 100000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int first, second, ans = 2;
    int l = 0, prv;
    int arr[n], last[MAXVAL + 1] = {};
    cin >> second >> first; prv = first;
    last[first] = 1;
    for(int r = 2; r < n; ++r){
        cin >> arr[r];
        last[arr[r]] = r;
        if(arr[r] == prv){
            ans = max(ans, r - l + 1);
            continue;
        }

        if(abs(arr[r] - first) > 1) l = last[first] + 1;
        else if(abs(arr[r] - second) > 1) l = last[second] + 1;

        second = first;
        first = arr[r];

        ans = max(ans, r - l + 1);

        prv = arr[r];
    }
    cout << ans << '\n';
}
