/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 10000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int64_t min_lcm = LLONG_MAX, l = 0, r = 0;
    set<int> nums;
    vector<int> ap(MAXVAL + 1);
    for(int i = 1; i <= n; ++i){
        int64_t x; cin >> x;
        if(nums.count(x)){
            if(x < min_lcm){
                min_lcm = x;
                l = ap[x];
                r = i;
            }
        } else nums.insert(x);
        ap[x] = i;
    }

    int lim = *nums.rbegin();
    for(int g = 1; g <= lim; ++g){
        int64_t first = -1;
        for(int m = g; m <= lim; m += g){
            if(!ap[m]) continue;
            if(first == -1) first = m;
            else {
                int64_t new_lcm = first / g * m;
                if(new_lcm < min_lcm){
                    min_lcm = new_lcm;
                    l = min(ap[first], ap[m]);
                    r = max(ap[first], ap[m]);

                }
                break;
            }
        }
    }
    cout << l << ' ' << r << '\n';
}
