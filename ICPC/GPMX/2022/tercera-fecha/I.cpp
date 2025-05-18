/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool ok = true;
    for(int i = 0; i < 8; ++i){
        int x; cin >> x;
        ok &= x != 9;
    }
    cout << "FS"[ok] << '\n';
}
