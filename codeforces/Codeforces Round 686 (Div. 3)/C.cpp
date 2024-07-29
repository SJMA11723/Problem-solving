/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;

    cin >> t;

    while(t--){
        int n, mini = 1e7, seg = 1e7;
        cin >> n;

        int oc[n + 1], arr[n];

        fill(oc, oc + n + 1, 0);

        cin >> arr[0];
        oc[arr[0]]++;

        for(int i = 1; i < n; ++i){
            cin >> arr[i];
            if(arr[i - 1] != arr[i]) oc[ arr[i] ]++;
        }

        for(int i = 1; i <= n; ++i){
            if(oc[i]){
                int ns = oc[i] + 1;
                ns -= (arr[0] == i) + (arr[n - 1] == i);

                if(ns < seg){
                    seg = ns;
                    mini = oc[i];
                }
            }
        }

        cout << seg << '\n';

    }
}
