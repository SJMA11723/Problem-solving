/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> lilypads;
    for(int i = 1; i <= 2e6; ++i)
        lilypads.insert(i);

    int n; cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        lilypads.erase(arr[i]);
    }

    int q; cin >> q;

    while(q--){
        int i; cin >> i;
        int n_lily = *(lilypads.upper_bound(arr[i]));
        cout << n_lily << '\n';
        lilypads.erase(n_lily);
        lilypads.insert(arr[i]);
        arr[i] = n_lily;
    }

}
