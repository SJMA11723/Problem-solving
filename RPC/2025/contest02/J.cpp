#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);


    int n; cin >> n;
    int a[n], b[n];

    for(int i=0; i<n; i++) cin >> a[i] >> b[i];


    bool sePuede = true;
    for(int i=1; i<n; i++){
        if( !( a[i-1]<=a[i] ) ) sePuede=false;
        if( !( b[i-1]<=b[i] ) ) sePuede=false;
    }

    if( sePuede ) cout << "yes\n";
    else cout << "no\n";


}

