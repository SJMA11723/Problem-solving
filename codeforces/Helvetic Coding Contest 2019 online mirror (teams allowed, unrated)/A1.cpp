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
    long long r; cin >> r;
    r--;
    vector<long long> div;
    for(long long d = 1; d * d <= r; ++d){
        if(r % d == 0){
            div.push_back(d);
            if(d * d != r) div.push_back(r / d);
        }
    }
    sort(div.begin(), div.end());
    for(long long x : div){
        long long y = (r - x * x - x) / (2 * x);
        if(r == x * x + 2 * x * y + x && y > 0){
            cout << x << ' ' << y << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}
