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
    vector<int64_t> dibonacci;
    for(int i = 1; i <= 9; ++i){
        dibonacci.push_back(i);
        for(int j = 0; j <= 9; ++j){
            uint64_t num = i * 10 + j;
            dibonacci.push_back(num);

            int prv1 = i, prv2 = j;
            for(int k = 2; k <= 17; ++k){
                int d = (prv1 + prv2) % 10;
                num = num * 10 + d;
                prv1 = prv2;
                prv2 = d;

                dibonacci.push_back(num);
            }
        }
    }

    sort(dibonacci.begin(), dibonacci.end());

    int t; cin >> t;
    while(t--){
        int64_t l, r; cin >> l >> r;
        cout << upper_bound(dibonacci.begin(), dibonacci.end(), r) - lower_bound(dibonacci.begin(), dibonacci.end(), l) << '\n';
    }
}
