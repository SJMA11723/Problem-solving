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
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        arr.push_back(arr[i]);
    }

    n <<= 1;
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i]) cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
    }
    ans = max(ans, cnt);
    cout << ans << '\n';
}
