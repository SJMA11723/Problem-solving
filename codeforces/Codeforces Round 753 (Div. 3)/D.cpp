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
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        string str; cin >> str;
        pair<char, int> nums[n];
        for(int i = 0; i < n; ++i){
            nums[i] = {str[i], arr[i]};
        }
        sort(nums, nums + n);

        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(!(nums[i].first == 'B' && nums[i].second >= i + 1) && !(nums[i].first == 'R' && nums[i].second <= i + 1))
                ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
