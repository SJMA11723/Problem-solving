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
        int a, b, c; cin >> a >> b >> c;
        int ans = INT_MAX, A, B, C;
        for(int i = 1; i <= 1e5; ++i){
            for(int j = i; j <= 1e5; j += i){
                int k = c / j * j;
                if(abs(i - a) + abs(j - b) + abs(k - c) < ans){
                    ans = abs(i - a) + abs(j - b) + abs(k - c);
                    A = i;
                    B = j;
                    C = k;
                }

                k += j;
                if(abs(i - a) + abs(j - b) + abs(k - c) < ans){
                    ans = abs(i - a) + abs(j - b) + abs(k - c);
                    A = i;
                    B = j;
                    C = k;
                }
            }
        }
        cout << ans << '\n' << A << ' ' << B << ' ' << C << '\n';
    }
}
