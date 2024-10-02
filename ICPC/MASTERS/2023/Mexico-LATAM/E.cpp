#include <bits/stdc++.h>
using namespace std;

int64_t MOD =1e9+7;

int bin_exp( int64_t a, int64_t b ){
    int64_t ans = 1ll;
    while(b){
        if( b%2 ){
            ans*= 1ll*a;
            if(ans >= MOD) ans%=MOD;
        }
        a*=a;
        if(a >= MOD) a%=MOD;
        b/=2;
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n,d,s,k;
    cin >> n >> d >> k >> s;

    if(d == 0){
        cout << k << '\n';
        return 0;
    }

    int64_t p = min( n, 2*d+1 );

    int64_t A = bin_exp( p, k)-1;
    if( A<0 ) A+=MOD;
    int64_t B = bin_exp( p-1, MOD-2 );


//    cout << A/(p-1) << '\n';
    cout << (A*B)%MOD <<'\n';
}
