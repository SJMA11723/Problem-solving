#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n; cin >> n;

    int64_t c=0;
    int64_t v[n];
    for( int64_t & i : v ){
        cin >> i;
        c = max( c,i );
    }


    int64_t ans = 0;
    for( int64_t a: v ){
        for( int64_t b: v) {
            ans = max( ans, a*a + b*b + c*c - a*b - a*c - b*c  );
        }
    }
    cout << ans << '\n';


}