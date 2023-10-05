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
    long long n, tam;
    char c;
    cin >> n >> tam >> c;

    if(c == 'G') tam *= 1024ll;
    else if(c == 'T') tam *= 1024ll * 1024ll;

    long long arr[n + 1]; arr[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int r = 0;
    while(r <= n && arr[r] < tam) r++;
    if(r > n || arr[r] > tam) r--;

    for(int i = r; i <= n; ++i){
        while(arr[i] - arr[i - r] > tam) r--;
    }

    cout << r << ' ';
    bool ok = false;
    for(int i = r + 1; i <= n; ++i){
        //cout << i << ' ' << i - r - 1 << '\n';
        if(arr[i] - arr[i - r - 1] > tam){
            cout << i - r << '\n';
            ok = true;
            break;
        }
    }
    if(!ok) cout << "-1\n";
}
