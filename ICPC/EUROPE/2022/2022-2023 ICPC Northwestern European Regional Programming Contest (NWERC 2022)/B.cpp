#include <bits/stdc++.h>

using namespace std;

int main() {
    int h,r,da,dw;

    cin >> h >> r >> da >> dw;
    long double div = 1.0 * dw / da;
    //cout << div << "   ";
    long double ans =  1.0 * h / (1 + sqrt(div));
    cout << fixed << setprecision(8) << ans << '\n';

}
