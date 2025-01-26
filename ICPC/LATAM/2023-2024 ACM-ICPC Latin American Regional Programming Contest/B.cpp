#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> arr (3*n);
    map<int, int> cnt;
    for( int &x : arr ){
        cin >> x;
        cnt[x]++;
    }
    // si hay alguno numeor con frecuencia no multipl de 3
    // enotnvec Equalizer no puede ganar
    bool Equalizer = true;
    for( int &x : arr ){
        if( cnt[x]%3 != 0 ){
            Equalizer = false;
            break;
        }
    }

    if( Equalizer ) cout << "N\n";
    else cout << "Y\n";
}
