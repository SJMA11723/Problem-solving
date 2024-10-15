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
    int x0, y0; cin >> x0 >> y0;


    int x, y, x_ans, y_ans;
    n--;
    cin >> x_ans >> y_ans;
    while(n--){
        cin >> x >> y;
        int64_t dx1 = x0 - x;
        int64_t dy1 = y0 - y;
        int64_t dx2 = x0 - x_ans;
        int64_t dy2 = y0 - y_ans;
        if(dx1 * dx1 + dy1 * dy1 < dx2 * dx2 + dy2 * dy2){
            x_ans = x;
            y_ans = y;
        } else if(dx1 * dx1 + dy1 * dy1 == dx2 * dx2 + dy2 * dy2){
            tie(x_ans, y_ans) = min(make_pair(x_ans, y_ans), make_pair(x, y));
        }
    }
    cout << x_ans << ' ' << y_ans << '\n';
}
