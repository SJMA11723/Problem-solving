/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 200000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cub[MAXVAL + 1] = {};
    int arr[n];
    bool ok = true;
    for(int &x : arr){
        cin >> x;
        cub[x]++;
        if(cub[x] > 2) ok = false;
    }

    if(!ok){
        cout << "NO\n";
        return 0;
    }

    sort(arr, arr + n);
    vector<int> inc, dec;
    for(int i = 0; i < n; ++i)
        if(inc.empty() || inc.back() < arr[i]) inc.push_back(arr[i]), arr[i] = -1;

    for(int i = 0; i < n; ++i)
        if(arr[i] != -1) dec.push_back(arr[i]);

    reverse(dec.begin(), dec.end());

    cout << "YES\n" << inc.size() << '\n';
    for(int x : inc) cout << x << " \n"[x == inc.back()];

    cout << dec.size() << '\n';
    for(int x : dec) cout << x << " \n"[x == dec.back()];
}
