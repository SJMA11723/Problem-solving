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
    int cnt_M = 0, cnt_C = 0;
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        if(a < b) cnt_C++;
        else if(a > b) cnt_M++;
    }
    if(cnt_M > cnt_C) cout << "Mishka\n";
    else if(cnt_M < cnt_C) cout << "Chris\n";
    else cout << "Friendship is magic!^^\n";
}
