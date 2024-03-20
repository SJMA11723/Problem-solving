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
    string str; cin >> str;
    int n = str.size();
    str = '0' + str;

    int acc[n + 1][4];
    acc[0][0] = acc[0][1] = acc[0][2] = acc[0][3] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 4; ++j)
            acc[i][j] = acc[i - 1][j];

        if(str[i] == 'A') acc[i][0]++;
        else if(str[i] == 'T') acc[i][1]++;
        else if(str[i] == 'G') acc[i][2]++;
        else acc[i][3]++;
    }

    int m; cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        vector<pair<int, int>> ord;
        for(int i = 0; i < 4; ++i)
            ord.push_back({acc[r][i] - acc[l - 1][i], 3 - i});
        sort(ord.begin(), ord.end(), greater<pair<int,int>>());

        for(int i = 0; i < 4; ++i){
            switch(ord[i].second){
                case 3:
                    cout << 'A';
                    break;
                case 2:
                    cout << 'T';
                    break;
                case 1:
                    cout << 'G';
                    break;
                case 0:
                    cout << 'C';
            }
        }
        cout << '\n';
    }
}
