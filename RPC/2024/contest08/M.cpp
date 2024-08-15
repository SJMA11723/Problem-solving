#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,w;
    cin >> n >> w;

    int h[n];

    for( int i=0; i<n; i++ ) cin >> h[i];

    if( n<=w ){
        cout << "YES\n";
        return 0;
    }

    sort( h, h+n );

//    cout << h[0] << ' ' << h[1] << ' ' << h[2] << "\n";

    bool sePuede = true;
    for( int i=w; i<n; i++ ){
        if( !(h[i-w]< h[i])  ){
            sePuede = false;
            break;
        }
    }

    if( sePuede )cout << "YES\n";
    else cout << "NO\n";


}
