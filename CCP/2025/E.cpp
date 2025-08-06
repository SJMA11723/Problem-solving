#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = INT_MAX;
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    sort(arr, arr + 4);
    do{
        ans = min(ans, abs(arr[0] + arr[1] - (arr[2] + arr[3])));
    }while(next_permutation(arr, arr + 4));
    cout << ans << '\n';
}