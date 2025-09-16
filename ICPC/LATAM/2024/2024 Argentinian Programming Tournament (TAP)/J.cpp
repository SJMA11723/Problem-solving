#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    int arr[n], cnt = 0, cnt_mid = 0;
    for(int &a : arr){
        cin >> a;
        if(2*a == x) cnt_mid++;
        else cnt++;

    }
    sort(arr, arr + n);

    bool ok = true;
    for(int i = 1; i < n; ++i)
        if(arr[i] + arr[i - 1] == x) ok = false;

    if(ok){
        for(int i = 0; i < n; ++i) cout << arr[i] << " \n"[i + 1 == n];
        return 0;
    }

    if(!cnt_mid){
        int breakpoint = 0;
        for(int i = 1; i < n; ++i){
            if(arr[i] + arr[i - 1] == x){
                breakpoint = i - 1;
                break;
            }
        }

        if(arr[0] + arr[breakpoint + 1] != x){

            for(int i = 1; i <= breakpoint; ++i) cout << arr[i] << ' ';
            cout << arr[0] << ' ';
            for(int i = breakpoint + 1; i < n; ++i) cout << arr[i] << " \n"[i + 1 == n];

        } else if(arr[n - 1] + arr[breakpoint] != x){

            for(int i = 0; i <= breakpoint; ++i) cout << arr[i] << ' ';
            cout << arr[n - 1] << ' ';
            for(int i = breakpoint + 1; i < n - 1; ++i) cout << arr[i] << " \n"[i + 1 == n - 1];

        } else cout << "*\n";

        return 0;
    }

    if(cnt < cnt_mid - 1){
        cout << "*\n";
        return 0;
    }



    vector<int> nomid;
    for(int i = 0; i < n; ++i){
        if(arr[i] * 2 != x) nomid.push_back(arr[i]);
    }

    int idxNM = 0, idxM = 0;
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(i % 2){
            if(idxNM < nomid.size()) ans.push_back(nomid[idxNM++]);
            else ans.push_back(x / 2);
        } else {
            if(idxM < cnt_mid){
                ans.push_back(x / 2);
                idxM++;
            } else {
                ans.push_back(nomid[idxNM++]);
            }
        }
    }

    //for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];

    int breakpoint = 0;
    for(int i = 1; i < n; ++i)
    if(ans[i] + ans[i - 1] == x){
        breakpoint = i;
        break;
    }

    for(int i = breakpoint; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n && !breakpoint];
    for(int i = 0; i < breakpoint; ++i) cout << ans[i] << " \n"[i + 1 == breakpoint];
}