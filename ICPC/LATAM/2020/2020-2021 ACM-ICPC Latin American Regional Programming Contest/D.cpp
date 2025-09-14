#include<bits/stdc++.h>
#define MAXVAL 100000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt[MAXVAL + 102] = {};
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cnt[x]++;
    }

    if(n == 1){
        cout << "N\n";
        return 0;
    }

    for(int i = 0; i <= MAXVAL + 100; ++i){
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;
    }

    int cnt_res = 0;
    for(int i = 0; i <= MAXVAL + 101; ++i) cnt_res += cnt[i];
    cout << (cnt_res <= 2 ? 'Y' : 'N') << '\n';
}



