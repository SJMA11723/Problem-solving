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
    int64_t n, k, s; cin >> n >> k >> s;
    if((n - 1) * k < s || k > s){
        cout << "NO\n";
        return 0;
    }

    int64_t add = k - (s + n - 2) / (n - 1);

    cout << "YES\n";
    bool nxt = true;
    int64_t ptr = 1;
    for(int64_t i = 0; i < k; ++i){
        if(s - (n - 1) >= k - i){
            if(nxt) ptr += n - 1;
            else ptr -= n - 1;
            s -= n - 1;
        } else if(s > k - i){
            if(nxt) ptr += s - (k - i - 1);
            else ptr -= s - (k - i - 1);
            s = k - i - 1;
        } else {
            if(nxt) ptr++;
            else ptr--;
            s--;
        }

        if(ptr == 1) nxt = true;
        else nxt = false;
        cout << ptr << " \n"[i + 1 == k];
    }
}
