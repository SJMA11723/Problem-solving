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
    int k; cin >> k;
    int n = -1, m;
    for(int i = 5; i * i <= k; ++i){
        if(k % i == 0 && k / i >= 5){
            n = i;
            m = k / i;
            break;
        }
    }
    if(n == -1){
        cout << "-1\n";
        return 0;
    }

    string ans; ans.resize(k);
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            ans[i * m + j] = vowels[(i + j) % 5];
        }
    }
    cout << ans << '\n';
}
