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
        double sum = 0, maxi = -1e10;
        for(int i = 0; i < n; ++i){
            double x; cin >> x;
            maxi = max(maxi, x);
            sum += x;
        }
        cout << fixed << setprecision(7) << (sum - maxi) / (n - 1) + maxi << '\n';
    }
}
