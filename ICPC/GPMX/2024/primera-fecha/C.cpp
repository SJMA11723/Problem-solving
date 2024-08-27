#include  <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t L, W, H; cin >> L >> W >> H;
    int64_t arr[3]; cin >> arr[0] >> arr[1] >> arr[2];
    int64_t ans = 0;
    int P[3] = {0, 1, 2};

    do{
        ans = max(ans, (L / arr[P[0]]) * (W / arr[P[1]]) * (H / arr[P[2]]) );
    }while(next_permutation(P, P + 3));

    cout << ans << '\n';
}
