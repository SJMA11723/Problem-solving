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
    string A, B;
    cin >> A >> B;
    int pts_A = 0, pts_B = 0;

    for(char c : A){
        if('0' <= c && c <= '9') pts_A += c - '0';
        if('a' <= c && c <= 'z') pts_A += 10 + c - 'a';
        if('A' <= c && c <= 'Z') pts_A += 2 * (10 + c - 'A');
    }

    for(char c : B){
        if('0' <= c && c <= '9') pts_B += c - '0';
        if('a' <= c && c <= 'z') pts_B += 10 + c - 'a';
        if('A' <= c && c <= 'Z') pts_B += 2 * (10 + c - 'A');
    }

    if(pts_A > pts_B) cout << "Ana " << pts_A << '\n';
    else cout << "Carolina " << pts_B << '\n';
}
