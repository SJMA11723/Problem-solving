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
        vector<int> nums;
        int cub[10] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x % 10] = min(3, cub[x % 10] + 1);
        }
        for(int i = 0; i < 10; ++i){
            while(cub[i]--){
                nums.push_back(i);
            }
        }

        bool ok = false;
        n = nums.size();
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
                for(int k = j + 1; k < n; ++k)
                    if((nums[i] + nums[j] + nums[k]) % 10 == 3)
                        ok = true;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
