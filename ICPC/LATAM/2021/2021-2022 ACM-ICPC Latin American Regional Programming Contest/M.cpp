#include <bits\stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    pair<int64_t, int64_t> arr[n];
    int64_t sum = 0;
    int cnt = 1;
    for(int i = 0; i < n; ++i){
        int t, d;
        cin >> t >> d;
        sum += t;
        arr[i] = {t, d};
    }

    bool complete[n] = {};
    int64_t ans[n];
    for(int i = n - 1; 0 <= i; --i){
        bool ok = false;
        for(int j = n - 1; 0 <= j; --j){
            if(complete[j]) continue;

            //cout << i << ' ' << j << ' ' << arr[j].second << ' ' << sum << '\n';
            if(arr[j].second >= sum){
                sum -= arr[j].first;
                complete[j] = true;
                ans[i] = j + 1;
                ok = true;
                //cout << "Elegido " << j + 1 << '\n';
                break;
            }
        }

        if(!ok){
            cout << "*\n";
            return 0;
        }
    }

    sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[ ans[i] - 1 ].first;
        if(sum > arr[ ans[i] - 1 ].second){
            cout << "*\n";
            return 0;
        }
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
