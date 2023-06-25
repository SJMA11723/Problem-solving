/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int cub[31][300], maxi[31];
vector<char> letras[31];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int maxSize = 0;
    int n; cin >> n;
    while(n--){
        string str; cin >> str;
        maxSize = max(maxSize, (int)str.size());
        for(int i = 0; i < str.size(); ++i){
            cub[i][str[i]]++;
            if(maxi[i] <= cub[i][str[i]]){
                if(maxi[i] < cub[i][str[i]]) letras[i].clear();
                letras[i].push_back(str[i]);
                maxi[i] = cub[i][str[i]];
            }
        }
    }

    for(int i = 0; i < maxSize; ++i){
        sort(letras[i].begin(), letras[i].end());
        cout << i + 1 << ": ";
        for(int j = 0; j < letras[i].size(); ++j){
            cout << letras[i][j];
            if(j + 1 == letras[i].size()) cout << '\n';
            else cout << ' ';
        }
    }
}
