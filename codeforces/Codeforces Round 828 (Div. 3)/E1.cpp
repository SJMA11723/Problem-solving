#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long num = a * b;
        long long x, y;
        x = y = -1;

        for(long long i = a + 1; i <= c; ++i){
            long long gcd = __gcd(num, i);

            long long yy = num / gcd;
            yy *= d / yy;
            if(b < yy && yy <= d){
                x = i;
                y = yy;
                break;
            }
        }

        cout << x << ' ' << y << '\n';
    }
}