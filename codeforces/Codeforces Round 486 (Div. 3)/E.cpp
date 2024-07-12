/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

/**
    00
    25
    50
    75
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string n; cin >> n;
    if(n.size() == 1){
        cout << "-1\n";
        return 0;
    }

    if(stoll(n) % 25 == 0){
        cout << "0\n";
        return 0;
    }

    int ans = INT_MAX;
    for(int i = 0; i < n.size(); ++i){
        if(n[i] != '0' && n[i] != '2' && n[i] != '5' && n[i] != '7') continue;

        for(int j = 0; j < n.size(); ++j){
            if(i == j) continue;
            if((n[i] == '0' || n[i] == '5') && n[j] != '0' ) continue;
            if((n[i] == '2' || n[i] == '7') && n[j] != '5' ) continue;

            bool move_first = false;
            if(!i && n[i + 1] == '0' && j != i + 1 || (j == i + 1 && i + 2 < n.size() && n[i + 2] == '0')) move_first = true;
            if(!j && n[j + 1] == '0' && i != j + 1 || (i == j + 1 && j + 2 < n.size() && n[j + 2] == '0')) move_first = true;

            int add = 0, ni = i, nj = j;
            if(move_first){
                add = -1;
                for(int k = 0; k < n.size(); ++k){
                    if(k != i && k != j && n[k] != '0'){
                        add = k;
                        if(min(i, j) + 1 == max(i, j)) add -= 2;
                        else {
                            k--;
                            if(ni < k) ni++;
                            if(nj < k) nj++;
                        }
                        break;
                    }
                }
            }
            if(add == -1) continue;

            //cout << i << ' ' << j << '\n';
            //cout << ni << ' ' << nj << ' ' << add << '\n';
            if(ni < nj) ans = min(ans, int(n.size())*2 - nj - ni - 3 + add);
            else ans = min(ans, int(n.size())*2 - nj - ni - 2 + add);
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
