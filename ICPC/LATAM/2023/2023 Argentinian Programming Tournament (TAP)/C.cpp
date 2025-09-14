#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int A[n], B[n];
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < n; ++i) cin >> B[i];

    sort(A, A + n, greater<int>());
    sort(B, B + n);

    int maxi = 0, mini = INT_MAX;
    for(int i = 0; i < n; ++i){
        maxi = max(maxi, abs(A[i] + B[i]));
        mini = min(mini, abs(A[i] + B[i]));
    }

    cout << maxi - mini << '\n';

    return 0;
}
