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
        map<long long, int> cub;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x]++;
        }
        int ans = 0;
        vector<int> nums;

        nums.push_back(cub.begin()->first);
        long long sum = cub.begin()->first;
        cub.begin()->second--;
        if(cub.begin()->second == 0) cub.erase(cub.begin());

        for(int i = 1; i < n; ++i){
            auto upb = cub.upper_bound(sum);
            if(upb == cub.end()){
                upb--;
                ans++;
            }
            sum += upb->first;
            upb->second--;
            nums.push_back(upb->first);
            if(upb->second == 0) cub.erase(upb);
        }
        cout << ans << '\n';
        for(int i = 0; i < n; ++i) cout << nums[i] << ' ';
        cout << '\n';
    }
}
