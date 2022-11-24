#include <bits/stdc++.h>

using namespace std;

int ordenar(vector<int> &arr, int x){

    int pos = 0;

    for(int i = 0; i < arr.size(); ++i)
        if(arr[i] == x){
            pos = i + 1;
            break;
        }

    int ret = 0;

    if(x <= pos) ret = pos - x;
    else ret = pos;

    //cout << pos << ' ' << ret << ' ' << x << '\n';

    rotate(arr.begin(), arr.begin() + pos % x, arr.begin() + x);

    /*for(int it : arr) cout << it << ' ';
    cout << '\n';*/

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)
            cin >> arr[i];

        vector<int> ans;
        for(int i = n; 0 < i; --i){
            ans.push_back(ordenar(arr, i));
        }

        if(is_sorted(arr.begin(), arr.end())){
            for(int i = ans.size() - 1; 0 <= i; --i)
                cout << ans[i] << ' ';
            cout << '\n';
        } else cout << "-1\n";
    }
}
