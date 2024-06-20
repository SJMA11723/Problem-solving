/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 10527451

using namespace std;

void criba(int n, vector<int> &lp){
    if(n < 2) return;
    vector<int> primos;

    for(long long i = 2; i <= n; ++i){
        if(!lp[i]){
            lp[i] = i;
            primos.push_back(i);
        }

        for(int j = 0; i * (long long)primos[j] <= n; ++j){
            lp[i * primos[j]] = primos[j];
            if(primos[j] == lp[i])
                break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> lp(MAXN + 1);
    criba(MAXN, lp);
    vector<int> nums; nums.reserve(2000000);
    int num = 2;
    while(nums.size() < 2000000){
        if( lp[num] != lp[ num / lp[num] ] && num / lp[num] == lp[num / lp[num]] )
            nums.push_back(num);
        num++;
    }

    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        cout << nums[k - 1] << '\n';
    }
}
