#include<bits/stdc++.h>
using namespace std;
# define MOD 1'000'000'007


int64_t bin_exp(int64_t a, int64_t b){
    int64_t ans = 1;
    while(b){
        if(b % 2) ans *= a;
        ans %= MOD;
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ans;
}
int64_t entre( int64_t x ){
    x%=MOD;
    return  bin_exp( x, MOD-2 );
}

int64_t fact[1000];
int64_t binom( int64_t n,  int64_t k ){
    if( k > n || k < 0 ) return 0;
    return  (fact[n] * entre( fact[k] * fact[n-k] ) ) %MOD;
    //return fact[n] / () fact[k] * fact[n-k] );
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    fact[0]=1;
    for( int i=1; i<1000; i++ ){
        fact[i] = i* fact[i-1] %MOD;
    }


    int t; cin >> t;

    int64_t n,x;
    while( t-- ){
        cin >> n >> x;

        if( n-x > 364 ){
            cout << "0\n";
            continue;
        }
        // binom(n,x)*365* binom(364,n-x)*(n-x)!


        __int128_t anss =  1;
        //  (n) (n-1) (n-2) . . . (x+1) = binom(n,x) * (n-x)!
        for( int64_t i=n; i > x; i-- ) anss = ( anss * i ) %MOD;

        int64_t ans= anss;

        //  binom(364,n-x)
        ans= ans* binom(364,n-x) %MOD;

        // casos totales 365**n  (pero hay un n en el denominador)
        ans = ans *entre( bin_exp(365, n-1 ) ) %MOD;
        cout << ans << '\n';

    }
}