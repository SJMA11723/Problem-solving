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
        for(int i = 0; i < n; ++i){
            int k;
            string str;
            cin >> k >> str;
            for(char &c : str){
                if(c == 'U') arr[i] = (arr[i] - 1 + 10) % 10;
                else arr[i] = (arr[i] + 1) % 10;
            }
        }

        for(int i = 0; i < n; ++i) cout << arr[i] << ' ';
        cout << '\n';
    }
}
