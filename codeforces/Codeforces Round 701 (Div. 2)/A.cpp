/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int op(int a, int b, int add){
    int cnt = 0;
    while(a){
        a /= b + add;
        cnt++;
    }
    //cout << add << ' ' << cnt + add << '\n';
    return cnt + add;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int ans = 0;
        if(b == 1){
            ans++;
            b++;
        }
        int add = 1;
        while(op(a, b, add - 1) >= op(a, b, add)) ++add;
        b += add - 1;
        ans += add - 1;
        //cout << b << '\n';
        while(a){
            ans++;
            a /= b;
        }
        cout << ans << '\n';
    }
}
