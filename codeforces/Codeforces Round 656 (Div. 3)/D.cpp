/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int count_good(string &s, int l, int r, char c){
    if(r - l == 1) return s[l] != c;
    int mid = l + (r - l) / 2;
    int cnt_cl = 0;
    for(int i = l; i < mid; ++i) cnt_cl += s[i] == c;

    int cnt_cr = 0;
    for(int i = mid; i < r; ++i) cnt_cr += s[i] == c;

    return min(mid - l - cnt_cl + count_good(s, mid, r, c + 1),
               r - mid - cnt_cr + count_good(s, l, mid, c + 1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        cout << count_good(s, 0, n, 'a') << '\n';
    }
}
