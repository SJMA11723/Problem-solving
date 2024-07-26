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

    ifstream cin("breedflip.in");
    ofstream cout("breedflip.out");

    int n; cin >> n;
    string A, B; cin >> A >> B;
    int ans = 0;
    bool segment = false;
    for(int i = 0; i < n; ++i){
        if(A[i] == B[i]){
            ans += segment;
            segment = false;
        } else segment = true;
    }
    ans += segment;
    cout << ans << '\n';
}
