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
    int cnt_e = 0, cnt_o = 0;
    while(n--){
        int x; cin >> x;
        if(x % 2) cnt_o++;
        else cnt_e++;
    }
    cout << min(cnt_e, cnt_o) << '\n';
}
