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
    int n; cin >> n;
    int cnt0 = 0, cnt = 0;
    char prv = 0;
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        if(c != prv){
            cnt++;
            if(c == '0') cnt0++;
        }
        prv = c;
    }
    cout << min(cnt0, cnt - cnt0) << '\n';
}
