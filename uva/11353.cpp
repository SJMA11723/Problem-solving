/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 2000000

using namespace std;

void criba(int n, vector<int> &lp){
    if(n < 2) return;

    lp = vector<int>(n + 1);
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
    vector<int> lp;
    criba(MAXN, lp);

    pair<int, int> arr[MAXN];
    for(int i = 1; i <= MAXN; ++i){
        int cnt_fact = 0;
        int tmp_i = i;
        while(tmp_i > 1){
            cnt_fact++;
            tmp_i /= lp[tmp_i];
        }
        arr[i - 1] = {cnt_fact, i};
    }
    sort(arr, arr + MAXN);

    int tt = 1;
    int n; cin >> n;
    while(n){
        cout << "Case " << tt++ << ": " << arr[n - 1].second << '\n';
        cin >> n;
    }
}
