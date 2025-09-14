#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int64_t cub[5] = {};
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cub[x % 5]++;
    }

    int64_t ans = cub[0];

    int64_t arr[15][5] = {
        {0, 1, 0, 0, 1},/// 1
        {0, 0, 1, 1, 0},
        {0, 2, 0, 1, 0},
        {0, 1, 2, 0, 0},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 2, 1},
        {0, 3, 1, 0, 0},/// 7
        {0, 0, 3, 0, 1},/// 8
        {0, 1, 0, 3, 0},/// 9
        {0, 0, 0, 1, 3},/// 10
        {0, 5, 0, 0, 0},/// 11
        {0, 0, 5, 0, 0},/// 12
        {0, 0, 0, 5, 0},/// 13
        {0, 0, 0, 0, 5} /// 14
    };

    for(int i = 0; i < 14; ++i){
        int64_t mini = INT_MAX;
        for(int j = 1; j <= 4; ++j){
            if(arr[i][j]){
                mini = min(mini, cub[j] / arr[i][j]);
                //cout << i + 1 << ' ' << j << ": " << cub[j] / arr[i][j] << '\n';
            }
        }

        //cout << mini << '\n';

        ans += mini;

        for(int j = 1; j <= 4; ++j)
            cub[j] -= mini * arr[i][j];
    }

    cout << ans << '\n';

    return 0;
}
