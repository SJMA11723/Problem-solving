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
        string num; cin >> num;
        if(num.back() == '2') cout << num << ' ' << "2\n";
        else {
            int sum_d = 0;
            int idx_dos = -1;
            for(int i = 0; i < num.size(); ++i){
                sum_d += num[i] - '0';
                if(num[i] == '2') idx_dos = i;
            }

            if(sum_d % 3 == 0 ) cout << num << ' ' << "3\n";
            else if(sum_d % 3 == 1){
                num.pop_back();
                cout << num << ' ' << "3\n";
            } else if( idx_dos != -1 ){
                for(int i = 0; i < idx_dos; ++i) cout << num[i];
                for(int i = idx_dos + 1; i < num.size(); ++i) cout << num[i];
                cout << ' ' << "3\n";
            } else {
                if(num.size() % 2) num.pop_back();
                cout << num << ' ' << "11\n";
            }
        }
    }
}

