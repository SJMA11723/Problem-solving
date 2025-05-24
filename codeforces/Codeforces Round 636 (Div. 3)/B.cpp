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
        if(n % 4){
            cout << "NO\n";
            continue;
        }

        vector<int> even, odd;
        for(int i = 1; 2 * even.size() < n; i += 6){
            even.push_back(i + 1);
            even.push_back(i + 3);
            odd.push_back(i);
            odd.push_back(i + 4);
        }

        cout << "YES\n";
        for(int e : even) cout << e << ' ';
        for(int i = 0; i < odd.size(); ++i) cout << odd[i] << " \n"[i + 1 == odd.size()];
    }
}
