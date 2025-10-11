#include <bits/stdc++.h>

using namespace std;

int64_t pow10(int x){
    int64_t res = 1;
    while(x-- > 0) res *= 10;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int64_t n, m; cin >> n >> m;

        int64_t num = n * (pow10(b) - 1) + m;
        int64_t den = pow10(a) * (pow10(b) - 1);
        int64_t g = __gcd(num, den);
        num /= g;
        den /= g;
        cout << num << ' ' << den << '\n';
    }
}
