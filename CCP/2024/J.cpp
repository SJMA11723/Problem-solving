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
    int n; cin >> n;

    map<string, int> puntos[8];

    for(int i = 0; i < n; ++i){
        string P;
        char c;
        int pts;
        cin >> P >> c >> pts;

        puntos[c - 'A'][P] = max(puntos[c - 'A'][P], pts);
    }

    vector<pair<int, string>> arr;

    map<string, int> finales;

    for(int i = 0; i < 8; ++i)
        for(auto &it : puntos[i]) finales[it.first] += it.second;

    for(auto &it : finales) arr.push_back({-it.second, it.first});

    sort(arr.begin(), arr.end());

    for(int i = 0; i < min(4, (int)arr.size()); ++i) cout << arr[i].second << '\n';
}
