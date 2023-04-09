#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n], con = 1;
        for(int i = 1; i < n; i += 2){
            arr[i] = con++;
        }

        for(int i = 0; i < n; i += 2){
            arr[i] = con++;
        }

        for(int i = 0; i < n; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
    }
}