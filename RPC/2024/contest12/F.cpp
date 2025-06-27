#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<string, int> prediction;
    string arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        prediction[ arr[i] ] = i;
    }

    string ans = "suspicious";
    int diff = 0, top = 0;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        int p = prediction[s];
        if(i - p < diff){
            diff = i - p;
            top = i;
            ans = s;
        } else if(i - p == diff && i < top){
            ans = s;
            top = i;
        }
    }
    cout << ans << '\n';
}
