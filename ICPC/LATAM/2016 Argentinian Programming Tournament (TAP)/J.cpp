#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, c; cin >> n >> l >> c;
    int arr[n];
    for(int &x : arr) cin >> x;
    sort(arr, arr + n, greater<int>());

    int rem = c, width = 0, cnt_lines = n;
    for(int i = 0; i < n; ++i){
        if(cnt_lines >= l){
            cnt_lines = 0;
            width = arr[i];
            rem -= width;
        }

        if(rem < 0){
            cout << "N\n";
            return 0;
        }

        cnt_lines++;
    }

    cout << "S\n";
}
