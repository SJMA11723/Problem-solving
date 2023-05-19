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
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        int l = 0, r = n - 1, sumA = 0, sumB = 0;
        int antA, antB = antA = 0;
        int turno = 0;
        while(l <= r){
            turno++;
            int actA, actB = actA = 0;
            if(turno % 2) while(l <= r && actA <= antB) actA += arr[l++];
            else while(l <= r && actB <= antA) actB += arr[r--];
            antA = actA;
            antB = actB;
            sumA += actA;
            sumB += actB;
            //cout << sumA << ' ' << sumB << '\n';
        }
        cout << turno << ' ' << sumA << ' ' << sumB << '\n';
    }
}
