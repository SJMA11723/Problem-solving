/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int64_t ans_neg = 0, ans_pos = 0;
    int cnt_neg = 0, cnt_neg1 = 0, cnt_neg0 = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x < 0) cnt_neg++;

        if(cnt_neg & 1){
            ans_neg += 1 + cnt_neg0;
            ans_pos += cnt_neg1;
        } else {
            ans_neg += cnt_neg1;
            ans_pos += 1 + cnt_neg0;
        }

        if(cnt_neg & 1) cnt_neg1++;
        else cnt_neg0++;
    }

    cout << ans_neg << ' ' << ans_pos << '\n';
}
