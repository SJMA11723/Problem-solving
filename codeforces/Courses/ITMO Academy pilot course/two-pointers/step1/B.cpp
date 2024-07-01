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
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int ptr = 0;
    for(int i = 0; i < m; ++i){
        while(ptr < n && a[ptr] < b[i]) ptr++;
        cout << ptr << " \n"[i + 1 == m];
    }
}
