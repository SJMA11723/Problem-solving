/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<char, int>> letters;
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        letters.push_back({c, i});
    }
    sort(letters.begin(), letters.end(), greater<pair<char, int>>());

    while(k--) letters.pop_back();

    sort(letters.begin(), letters.end(), comp);

    for(auto [c, i] : letters) cout << c;
    cout << '\n';
}
