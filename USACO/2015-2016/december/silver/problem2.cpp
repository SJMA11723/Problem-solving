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

    ifstream cin("highcard.in");
    ofstream cout("highcard.out");

    int n; cin >> n;
    set<int> bessie;
    for(int i = 1; i <= n; ++i) bessie.insert(i), bessie.insert(i + n);
    int arr[n];
    for(int  &x : arr) cin >> x, bessie.erase(x);

    int ans = 0;
    for(int  &x : arr){
        auto it_card = bessie.upper_bound(x);
        if(it_card == bessie.end()){
            bessie.erase(bessie.begin());
        } else {
            ans++;
            bessie.erase(it_card);
        }
    }
    cout << ans << '\n';
}
