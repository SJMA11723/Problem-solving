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
    int n;
    float n1, n2;
    cin >> n >> n1 >> n2;
    float arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n, greater<float>());

    float mean1 = 0, mean2 = 0;
    for(int i = 0; i < min(n1, n2); ++i) mean1 += arr[i];
    mean1 /= min(n1, n2);

    for(int i = min(n1, n2); i < n1 + n2; ++i) mean2 += arr[i];
    mean2 /= max(n1, n2);
    cout << fixed << setprecision(10) << mean1 + mean2 << '\n';
}
