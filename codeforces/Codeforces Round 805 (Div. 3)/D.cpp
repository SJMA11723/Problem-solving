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
        string s; cin >> s;
        int n = s.size();
        int p; cin >> p;
        pair<int, int> arr[n];
        int sum = 0;
        for(int i = 0; i < n; ++i){
            arr[i] = {s[i], i};
            sum += s[i] - 'a' + 1;
        }
        sort(arr, arr + n);
        while(sum > p){
            n--;
            sum -= arr[n].first - 'a' + 1;
        }
        for(int i = 0; i < n; ++i) swap(arr[i].first, arr[i].second);
        if(n) sort(arr, arr + n);
        for(int i = 0; i < n; ++i) cout << (char)arr[i].second;
        cout << '\n';
    }
}
