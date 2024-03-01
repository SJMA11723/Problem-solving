/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 15

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = INT_MAX;
        for(int i = 0; i <= 2; ++i){
            for(int j = 0; j <= 1; ++j){
                for(int k = 0; k <= 4; ++k){
                    for(int l = 0; l <= 29; ++l){
                        int n2 = n - i - j * 3 - k * 6 - l * 10;
                        if(n2 < 0 || n2 % 15 ) continue;
                        ans = min(ans, i + j + k + l + n2 / 15);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
