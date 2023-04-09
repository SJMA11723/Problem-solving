/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
* LinkedIn: https://www.linkedin.com/in/jorgetzab/
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

        int con = 0;
        for(int i = 0; i < n && con < 2; ++i){
            int j = i;

            while(j + 1 < n && arr[j + 1] == arr[i]) j++;
            if((!i || arr[i - 1] > arr[i]) && (j == n - 1 || arr[j] < arr[j + 1])) con++;
            i = j;
        }

        if(con == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}
