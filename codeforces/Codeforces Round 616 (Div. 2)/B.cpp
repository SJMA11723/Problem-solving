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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int posCreciente = 0, posDecreciente = n - 1;
        for(int i = 0; i < n; ++i){
            if(i <= arr[i]) posCreciente = i;
            else break;
        }

        for(int i = n - 1; 0 <= i; --i){
            if(n - 1 - i <= arr[i]) posDecreciente = i;
            else break;
        }

        if(posDecreciente <= posCreciente) cout << "Yes\n";
        else cout << "No\n";
    }
}
