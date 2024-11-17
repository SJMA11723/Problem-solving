#include<bits/stdc++.h>

using namespace std;

int id( char c ){
    if( c == 'C' || c == 'N'||  c == 'U' ) return 0;
    if( c == 'A' ) return 1;
    if( c == 'L' ) return 2;
    if( c == 'I' || c == 'H') return 3;
    if( c == 'O' ) return 4;
    return 5;
}
/*
0    C N U
1    A
2    L
3    I H
     C N U
4    O

*/
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t; cin >> t;
    string s;
    while( t-- ){
        cin  >> s;
        bool sePudo = true;
        int cnt[5] = {};
        for( char c:s ){
            if( id(c) == 5 ){
                sePudo = false;
                break;
            }
            cnt[id(c)]++;
        }
        int ans =(cnt[0]+1)/2;
        for( int i=1; i<=4; i++ ) ans = max( ans, cnt[i]);

        if( sePudo ) cout << ans << '\n';
        else cout << "-1\n";

    }

}
