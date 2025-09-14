#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t,d,m;

    cin >> t >> d >> m;

    int ant = 0, act;
    bool esPosible = false;
    for( int i=0; i<m; i++ ){
        cin >> act;
        if( t <= act - ant ) esPosible = true;
        ant = act;
    }
    if(  t <= d- ant  ) esPosible = true;

    if( esPosible ) cout << "Y\n";
    else cout << "N\n";

}
