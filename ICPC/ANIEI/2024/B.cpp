#include <bits/stdc++.h>
#define MAXVAL 1'000'000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    int ap[MAXVAL + 1] = {};
    for(int &x: arr){
        cin >> x;
        ap[x]++;
    }
    sort(arr, arr + n);

    int ans = 0;
    for(int i = 1; i <= MAXVAL; ++i){
        int cnt = 0;
        for(int m = i; m <= MAXVAL && cnt < 2 && m <= arr[n - 1]; m += i){
            cnt += ap[m];
        }

        if(cnt < 2) continue;

        int cnt_divs = 0;
        for(int d = 1; d * d <= i; ++d){
            if(i % d) continue;

            cnt_divs++;
            if(d * d != i) cnt_divs++;
        }

        ans = max(ans, cnt_divs);
    }
    cout << ans << '\n';
}
