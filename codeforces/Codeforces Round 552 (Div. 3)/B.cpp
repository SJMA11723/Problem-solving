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
    int mini = INT_MAX, maxi = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int ans = INT_MAX;
    for(int target = 1; target <= 100; ++target){
        bool ok = true;
        int D = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] == target) continue;
            if(!D) D = abs(target - arr[i]);
            ok = ok && D == abs(target - arr[i]);
        }
        if(ok) ans = min(ans, D);
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
