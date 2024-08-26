/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 5'000'000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    pair<int, int> cub[MAXVAL + 1];
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int S = arr[i] + arr[j];
            if(!cub[S].first) cub[S] = {i + 1, j + 1};
            else if(cub[S].first != i + 1 && cub[S].second != j + 1 && cub[S].second != i + 1 && cub[S].second != j + 1){
                cout << "YES\n";
                cout << cub[S].first << ' ' << cub[S].second << ' ' << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
}
