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
        int k; cin >> k;
        string str; cin >> str;
        bool ok = false;
        for(char c : str)
            if(c == '1' || c == '4' || c == '6' || c == '8' || c == '9'){
                cout << "1\n" << c  << '\n';
                ok = true;
                break;
            }
        if(ok) continue;

        vector<bool> ap(8);
        cout << "2\n";
        for(char c : str){
            int d = c - '0';
            if(ap[d]){
                cout << c << c << '\n';
                break;
            }
            if(d == 2){
                if(ap[3]) cout << "32\n";
                else if(ap[5]) cout << "52\n";
                else if(ap[7]) cout << "72\n";
                if(ap[3] || ap[5] || ap[7]) break;
            }else if(d == 5){
                if(ap[2]) cout << "25\n";
                else if(ap[3]) cout << "35\n";
                else if(ap[7]) cout << "75\n";
                if(ap[2] || ap[3] || ap[7]) break;
            } else if(d == 7){
                if(ap[2]) cout << "27\n";
                else if(ap[5]) cout << "57\n";
                if(ap[2] || ap[5]) break;
            }
            ap[d] = true;
        }
    }
}
