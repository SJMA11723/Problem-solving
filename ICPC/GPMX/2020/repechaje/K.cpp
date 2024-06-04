#include<bits/stdc++.h>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    int bread[N];
    for(int i = 0; i < N; ++i) cin >> bread[i];

    int dutch[M];
    for(int i = 0; i < M; ++i) cin >> dutch[i];

    int idx = 0, ans = 0;
    for(int i = 0; i < N; ++i){
        while(idx < M && dutch[idx] < bread[i]){
            ans += dutch[idx];
            dutch[idx] = 0;
            idx++;
        }

        dutch[idx] -= bread[i];
    }

    while(idx < M) ans += dutch[idx++];

    cout << ans << '\n';

    return 0;
}
