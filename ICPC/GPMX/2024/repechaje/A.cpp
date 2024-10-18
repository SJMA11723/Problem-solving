#include<bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    pair<string, string> arr[n];
    for(pair<string, string> &p : arr){
        string &s1 = p.first;
        string &s2 = p.second;
        cin >> s2;
        s1 = s2;
        sort(s1.begin(), s1.end());
    }
     sort(arr, arr+n);
    int q; cin >> q;
    while(q--){
        string s1; cin >> s1;
        string s2 = s1;
        sort(s1.begin(), s1.end());
        cout << upper_bound(arr, arr + n, make_pair(s1, s2)) - arr << '\n';
    }
}
