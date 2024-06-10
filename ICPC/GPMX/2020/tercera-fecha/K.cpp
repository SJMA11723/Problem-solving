#include<bits/stdc++.h>
#define MOD 1000000007
#define nmax 100010
using namespace std;

long long fact[2 * nmax];


long long binExp( long long a, long long b){
    long long ans = 1;
    while(b){
        if(b%2) ans*=a;
        if( ans>=MOD ) ans%=MOD;
        a*=a;
        if( a>=MOD ) a%=MOD;
        b/=2;
    }
    return ans;
}

long long elegir( int n, int k ){
    //cout << n << " en " << k <<"\n";
    if( k>n ) return 0;
    if( k<0 ) return 0;

    long long ans=fact[n];
     //cout << ans << "  " << fact[k] << " " << fact[n-k] << " ";

    ans*=binExp(fact[k],MOD-2);
    if( ans>=MOD ) ans%=MOD;
    //cout << ans << "  ";

    ans*=binExp(fact[n-k],MOD-2);
    if( ans>=MOD ) ans%=MOD;
    //cout << ans << "  ";

    //cout << ans << "\n";
    return ans;
}



int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    fact[0]=1;
    for(long long i=1; i< 2 * nmax; i++ )  fact[i]=i*fact[i-1]%MOD;

    int n,A,B,C,K,c;
    cin >> n;

    while( n-- ){
        cin >> A >> B >> C >> K >> c;

        if(K == c){
            cout << "0\n";
            continue;
        }

        long long ans = elegir( A+B, K-c );

        ans -= elegir( A, K-c ) - MOD;
        if( ans>=MOD ) ans-=MOD;

        ans -= elegir( B, K-c ) - MOD;
        if( ans>=MOD ) ans-=MOD;

        ans*= elegir(C,c);  // \binom{C}{c}
        if( ans>=MOD ) ans%=MOD;

        cout << ans << '\n';
    }


    return 0;
}
