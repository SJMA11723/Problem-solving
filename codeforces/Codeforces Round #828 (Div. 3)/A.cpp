#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        string str;
        cin >> str;

        bool ok = true;
        for(int i = 0; i < n && ok; ++i){
            for(int j = i + 1; j < n && ok; ++j){
                if(arr[i] == arr[j] && str[i] != str[j])
                    ok = false;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
