#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    cout << (1ll << n) + (1ll << m) - 2 << '\n';

    return 0;
}
