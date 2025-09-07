#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int arr[n] = {};
    for(int &x: arr) cin >> x;

    int maxi = 50, pos = 0;
    for(int i = 0; i + 2 < n; ++i){
        if(max(arr[i], arr[i + 2]) < maxi){
            maxi = max(arr[i], arr[i + 2]);
            pos = i + 1;
        }
    }
    cout << pos << ' ' << maxi << '\n';
}