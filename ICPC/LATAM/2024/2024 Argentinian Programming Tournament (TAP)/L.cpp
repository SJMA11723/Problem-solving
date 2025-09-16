#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q; cin >> n >>q;
    int64_t a[n+1];


    int64_t agustin[n+1], brian[n+1], unos[n+1];

    agustin[0]=1ll*0, brian[0]=1ll*0, unos[0]==1ll*0;

    for( int i=1; i<=n; i++ ){
        cin >> a[i];

        if( a[i]==1 ){
            unos[i] = unos[i-1]+1;
            brian[i] = brian[i-1];
            agustin[i] = agustin[i-1];

            continue;
        }

        unos[i] = unos[i-1];
        if(   a[i]%2 == 1  ) brian[i] = brian[i-1] +  a[i];
        else brian[i] = brian[i-1];

        if( __builtin_popcount( a[i])==1 ) agustin[i] = agustin[i-1] +  a[i];
        else agustin[i] = agustin[i-1];

    }


    int l,r;
//    cout << '\n';
    while( q-- ){
        cin >> l >> r;
        int64_t A = agustin[r] - agustin[l-1];
        int64_t B = brian[r] - brian[l-1];


        //unos
        A+= ( (unos[r]-unos[l-1])+1)/2;
        B+= ( (unos[r]-unos[l-1]))/2;

//        cout << A << ' ' << B <<'\n';
        if(  A > B ) cout << "A\n";
        else if( A < B ) cout << "B\n";
        else cout << "E\n";

    }
}