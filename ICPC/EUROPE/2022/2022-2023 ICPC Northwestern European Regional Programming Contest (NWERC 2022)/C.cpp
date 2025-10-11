#include <bits/stdc++.h>
#define eps 10e-8
using namespace std;

int64_t cch( long double r ){
    int64_t ans =0;

    for( int x=1; 1.0 * x * x <= r ;  x++ ){
        ans += sqrt( r - x*x );
    }
    return ans*4;
}

int main() {
    int64_t s; cin >> s;
    
    long double L=0, R=350000000;
    long double ansr = 0;
    while( abs(R-L) >= eps ){
        
        long double mid= (L+R)*(long double)0.5;
        if( cch(mid) > s ) {
            ansr = mid;
            R = mid;
        }
        else {
            L = mid;
        }

    }
    long double ans = sqrt(1.0* ansr );
    cout << fixed << setprecision(11) << ans << '\n';
}