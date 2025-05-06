
#include<bits/stdc++.h>

using namespace std;

bool comp(pair<string, int> &a, pair<string, int> &b){
    return a.first.size() < b.first.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    pair<string, int> arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n, comp);

    string tmp = "";

    bool ans[n] = {};
    for(int i = 0; i < n; ++i){
        while(tmp.size() < arr[i].first.size()) tmp += s;
        if(tmp == arr[i].first) ans[ arr[i].second ] = true;
    }

    for(int i = 0; i < n; ++i) cout << (ans[i] ? "Yes\n" : "No\n");
}




