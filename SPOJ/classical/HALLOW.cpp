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
    int n, c;
    cin >> c >> n;
    while(n || c){
        int arr[n];
        cin >> arr[0]; arr[0] %= c;
        int last[c]; fill(last, last + c, -1);
        last[arr[0]] = 0;
        int l = -1, r, multiple = arr[0] ? 0 : 1;
        for(int i = 1; i < n; ++i){
            cin >> arr[i]; arr[i] %= c;
            if(!arr[i]) multiple = i + 1;

            arr[i] += arr[i - 1];
            if(arr[i] >= c) arr[i] -= c;

            if(last[arr[i]] != -1){
                l = last[arr[i]] + 1;
                r = i;
            } else if(!arr[i]){
                l = 0;
                r = i;
            }
            else last[arr[i]] = i;
        }

        if(multiple) cout << multiple;
        else if(l != -1) for(int i = l; i <= r; ++i) {cout << i + 1; if(i < r) cout << ' ';}
        else cout << "no sweets";
        cin >> c >> n;
        if(c || n) cout << '\n';
    }
}
