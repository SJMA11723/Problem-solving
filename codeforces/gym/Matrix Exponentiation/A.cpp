#include <bits/stdc++.h>
#define input cin
#define out cout

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    long double p; cin >> p;
    long double ans = 1.0;
    while(n){
        if(n % 2) ans = ans * (1 - p) + (1 - ans) * p;
        p = 2 * p * (1 - p);
        n /= 2;
    }
    cout << fixed << setprecision(15) << ans;
}