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
    string a, b, c;
    char op, eq;
    cin >> a >> op >> b >> eq >> c;

    bool ok = false;

    string pref1;
    for(int p1 = 0; p1 + 1 < a.size(); ++p1){

        pref1 += string(1, a[p1]);
        string pref2;
        for(int p2 = 0; p2 + 1 < b.size(); ++p2){

            pref2 += string(1, b[p2]);

            string na = pref2 + a.substr(p1 + 1);
            string nb = pref1 + b.substr(p2 + 1);

            __int128_t A = 0, B = 0, C = 0, pot = 1;

            for(int i = (int)na.size() - 1; 0 <= i; --i, pot *= 10) A += pot * (na[i] - '0');
            pot = 1;
            for(int i = (int)nb.size() - 1; 0 <= i; --i, pot *= 10) B += pot * (nb[i] - '0');
            pot = 1;
            for(int i = (int)c.size() - 1; 0 <= i; --i, pot *= 10) C += pot * (c[i] - '0');


            if((op == '+' && A + B == C) || (op == '*' && ((!C && (!A || !B)) || (C % A == 0 && C / A == B)))){
                ok = true;
                a = na;
                b = nb;
                p1 = a.size();
                break;
            }
        }
    }

    if(ok){
        cout << a << ' ' << op << ' ' << b << " = " << c << '\n';
        return 0;
    }

    pref1 = "";
    for(int p1 = 0; p1 + 1 < a.size(); ++p1){

        pref1 += string(1, a[p1]);
        string pref2;
        for(int p2 = 0; p2 + 1 < c.size(); ++p2){

            pref2 += string(1, c[p2]);

            string na = pref2 + a.substr(p1 + 1);
            string nc = pref1 + c.substr(p2 + 1);

            __int128_t A = 0, B = 0, C = 0, pot = 1;

            for(int i = (int)na.size() - 1; 0 <= i; --i, pot *= 10) A += pot * (na[i] - '0');
            pot = 1;
            for(int i = (int)b.size() - 1; 0 <= i; --i, pot *= 10) B += pot * (b[i] - '0');
            pot = 1;
            for(int i = (int)nc.size() - 1; 0 <= i; --i, pot *= 10) C += pot * (nc[i] - '0');


            if((op == '+' && A + B == C) || (op == '*' && ((!C && (!A || !B)) || (C % A == 0 && C / A == B)))){
                ok = true;
                a = na;
                c = nc;
                p1 = a.size();
                break;
            }
        }
    }

    if(ok){
        cout << a << ' ' << op << ' ' << b << " = " << c << '\n';
        return 0;
    }

    pref1 = "";
    for(int p1 = 0; p1 + 1 < b.size(); ++p1){

        pref1 += string(1, b[p1]);
        string pref2;
        for(int p2 = 0; p2 + 1 < c.size(); ++p2){

            pref2 += string(1, c[p2]);

            string nb = pref2 + b.substr(p1 + 1);
            string nc = pref1 + c.substr(p2 + 1);

            __int128_t A = 0, B = 0, C = 0, pot = 1;

            for(int i = (int)a.size() - 1; 0 <= i; --i, pot *= 10) A += pot * (a[i] - '0');
            pot = 1;
            for(int i = (int)nb.size() - 1; 0 <= i; --i, pot *= 10) B += pot * (nb[i] - '0');
            pot = 1;
            for(int i = (int)nc.size() - 1; 0 <= i; --i, pot *= 10) C += pot * (nc[i] - '0');


            if((op == '+' && A + B == C) || (op == '*' && ((!C && (!A || !B)) || (C % A == 0 && C / A == B)))){
                ok = true;
                b = nb;
                c = nc;
                p1 = b.size();
                break;
            }
        }
    }

    cout << a << ' ' << op << ' ' << b << " = " << c << '\n';
}
