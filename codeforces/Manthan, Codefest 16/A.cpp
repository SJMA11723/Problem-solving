/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int gcdExtendido(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcdExtendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

void cambia_solucion(int &x, int &y, int a, int b, int cnt){
    x += cnt * b;
    y -= cnt * a;
}

bool encuentra_solucion(int a, int b, int c, int &x, int &y){
    int g = gcdExtendido(abs(a), abs(b), x, y);
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;

    a /= g;
    b /= g;

    cambia_solucion(x, y, a, b, - x / b);
    if(x < 0) cambia_solucion(x, y, a, b, 1);
    if(y < 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int x, y;
    if(encuentra_solucion(a, b, c, x, y)) cout << "Yes\n";
    else cout << "No\n";
}
