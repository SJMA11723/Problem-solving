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
        if(n % 2){
            if(n < 26){
                cout << "-1\n";
                continue;
            }

            int ans[n];
            ans[0] = ans[9] = ans[25] = 1;
            ans[22] = ans[26] = 2;
            int next = 3;
            for(int i = 2; i < 9; i += 2) ans[i] = ans[i - 1] = next++;
            for(int i = 11; i < 22; i += 2) ans[i] = ans[i - 1] = next++;
            ans[23] = ans[24] = next++;
            for(int i = 28; i < n; i += 2) ans[i] = ans[i - 1] = next++;

            for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];

        } else for(int i = 0; i < n; ++i) cout << i / 2 + 1 << " \n"[i + 1 == n];
    }
}
