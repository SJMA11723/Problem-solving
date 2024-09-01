/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int hex_to_dec(string B){
    int dec = 0;
    if('0' <= B[0] && B[0] <= '9') dec += 16 * (B[0] - '0');
    else dec += 16 * (B[0] - 'a' + 10);

    if('0' <= B[1] && B[1] <= '9') dec += (B[1] - '0');
    else dec += (B[1] - 'a' + 10);

    return dec;
}

bool in_range(string &s){
    int dec = hex_to_dec(s);
    if(hex_to_dec("20") <= dec && dec <= hex_to_dec("7f")) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> arr;
    string s;
    while(cin >> s) arr.push_back(s);

    bool C = false;
    bool PASCAL = false;

    /// Comprueba C
    for(string &s : arr){
        if(!hex_to_dec(s)){
            C = true;
            break;
        }

        if(!in_range(s)){
            C = false;
            break;
        }
    }

    /// Comprueba Pascal
    int l = hex_to_dec(arr[0]);
    if(arr.size() >= l + 1){
        PASCAL = true;
        for(int i = 1; i <= l; ++i) PASCAL &= in_range(arr[i]);
    }

    if(C && PASCAL) cout << "Both\n";
    else if(C) cout << "C\n";
    else if(PASCAL) cout << "Pascal\n";
    else cout << "None\n";
}
