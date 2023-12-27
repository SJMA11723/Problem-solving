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
    int a, b, c; cin >> a >> b >> c;
    int ap[1000001], cnt = 1, ans = -1;
    fill(ap, ap + 1000001, -1);
    a %= b;
    while(ap[a * 10] == -1){
        if(a * 10 / b == c){
            ans = cnt;
            break;
        }
        ap[a * 10] = cnt++;
        a = a * 10 % b;
    }
    cout << ans << '\n';
}
