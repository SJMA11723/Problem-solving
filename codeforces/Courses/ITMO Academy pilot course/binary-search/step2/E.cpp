/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long double c; cin >> c;
    long double l = 0, r = 1e5;
    while(r - l > EPS){
        long double mid = l + (r - l) / 2;
        if(mid * mid + sqrt(mid) >= c) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(7) << l << '\n';
}
