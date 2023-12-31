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
    int64_t n; cin >> n;
    int k; cin >> k;
    vector<int64_t> div;
    for(int64_t i = 1; i * i <= n; ++i){
        if(n % i == 0){
            div.push_back(i);
            if(i * i != n) div.push_back(n / i);
        }
    }
    if(div.size() < k) cout << "-1\n";
    else nth_element(div.begin(), div.begin() + k - 1, div.end()), cout << div[k - 1] << '\n';
}
