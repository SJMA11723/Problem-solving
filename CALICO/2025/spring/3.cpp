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
        vector<string> names(n);
        vector<int64_t> power(n);
        for(string &s : names) cin >> s;
        for(int64_t &p : power) cin >> p;

        while(n > 1){
            for(int i = 0; i < n; ++i){
                if(power[i] < power[i + 1]){
                    power[i + 1] += power[i];
                    names.erase(names.begin() + i);
                    power.erase(power.begin() + i);
                } else if(power[i] > power[i + 1]){
                    power[i] += power[i + 1];
                    names.erase(names.begin() + i + 1);
                    power.erase(power.begin() + i + 1);
                } else {
                    names[i] += names[i + 1];
                    power[i] += power[i + 1];
                    names.erase(names.begin() + i + 1);
                    power.erase(power.begin() + i + 1);
                }
                n--;
            }
        }
        cout << names[0] << '\n';
    }
}
