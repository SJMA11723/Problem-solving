/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b){
    return a + b < b + a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string arr[n];
    for(string &s : arr) cin >> s;
    sort(arr, arr + n, cmp);
    for(string &s : arr) cout << s;
    cout << '\n';
}
