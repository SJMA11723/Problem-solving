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
        int n, d; cin >> n >> d;
        string num; cin >> num;
        for(int i = 0; i < n; ++i){
            if(num[i] - '0' < d){
                num.insert(num.begin() + i, d + '0');
                break;
            }
        }
        if(num.size() == n) num += d + '0';
        cout << num << '\n';
    }
}
