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
    int n, k; cin >> n >> k;
    int cores[k], arr[n];
    int ans = 0;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    for(int i = 0; i < min(k, n); ++i)
        cores[i] = arr[i];

    int vacios = 0, idx = min(k, n), cnt = 0;
    while(vacios < min(k, n)){
        cnt++;
        for(int c = 0; c < min(k, n); ++c){
            cores[c]--;
            if(cores[c] == 0){
                ans = max(ans, cnt);
                cnt = 0;
                vacios++;

                if(idx < n){
                    cores[c] = arr[idx++];
                    vacios--;
                }
            }
        }
    }

    cout << ans << '\n';
}
