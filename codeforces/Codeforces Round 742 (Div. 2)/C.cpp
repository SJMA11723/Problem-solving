/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

#define is_on(s, i) ((s) & (1 << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> digits;
        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }

        int N = digits.size();
        int lim = 1 << max(N - 2, 0);
        int64_t ans = 0;
        for(int mask = 0; mask < lim; ++mask){
            int64_t pairs = 1;
            for(int j = 0; j < N; ++j){
                int s = digits[j] - (0 <= j - 2 && is_on(mask, j - 2));
                if(is_on(mask, j)){
                    s += 10;
                    int ways_to_sum = s + 1;
                    ways_to_sum -= 2 * (s - 9);
                    pairs *= ways_to_sum;
                } else {
                    pairs *= s + 1;
                }
            }
            ans += pairs;
        }
        ans -= 2;

        cout << ans << '\n';
    }
}
