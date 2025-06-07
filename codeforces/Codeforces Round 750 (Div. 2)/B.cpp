/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int64_t bin_exp(int a, int b){
    if(!b) return 1;
    int64_t tmp = bin_exp(a, b / 2);
    if(b & 1) return tmp * tmp * a;
    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x == 0) cnt0++;
            else if(x == 1) cnt1++;
        }
        cout << bin_exp(2, cnt0) * cnt1 << '\n';
    }
}
