#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t n; cin  >> n;

    int bits = __builtin_popcountll(n);
//    cout << "numero de 1  " << bits << '\n';
    int64_t ans = (1ll <<  (bits));
    cout << ans  << '\n';
}
