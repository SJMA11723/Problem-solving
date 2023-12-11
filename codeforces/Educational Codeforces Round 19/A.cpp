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
    vector<int> factors;
    for(int i = 2; i <= n; ++i){
        while(n % i == 0){
            factors.push_back(i);
            n /= i;
        }
    }

    while(factors.size() > k){
        int p = factors.back();
        factors.pop_back();
        factors.back() *= p;
    }

    if(factors.size() < k){
        cout << "-1\n";
        return 0;
    }
    for(int f : factors) cout << f << ' ';
    cout << '\n';
}
