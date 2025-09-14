#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n], maxi = 0;
    for(int &x : arr){
        cin >> x;
        maxi = max(maxi, x);
    }
    if(maxi == arr[0]) cout << "S\n";
    else cout << "N\n";
}
