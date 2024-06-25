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
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");

    int n, q; cin >> n >> q;
    int arr1[n + 1] = {};
    int arr2[n + 1] = {};
    int arr3[n + 1] = {};
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        if(x == 1) arr1[i] = 1;
        else if(x == 2) arr2[i] = 1;
        else arr3[i] = 1;

        arr1[i] += arr1[i - 1];
        arr2[i] += arr2[i - 1];
        arr3[i] += arr3[i - 1];
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << arr1[b] - arr1[a - 1] << ' ' << arr2[b] - arr2[a - 1] << ' ' << arr3[b] - arr3[a - 1] << '\n';
    }
}
