#include <bits/stdc++.h>

using namespace std;

int digit(char c){
    if(c <= 'c') return 2;
    if(c <= 'f') return 3;
    if(c <= 'i') return 4;
    if(c <= 'l') return 5;
    if(c <= 'o') return 6;
    if(c <= 's') return 7;
    if(c <= 'v') return 8;
    return 9;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    map<int64_t, vector<string>> cub;
    for(int i = 0; i < n; ++i){
        int64_t num = 0;
        string s; cin >> s;
        for(char c : s) num = num * 10 + digit(c);
        cub[num].push_back(s);
    }

    for(int i = 0; i < m; ++i){
        int64_t num; cin >> num;
        vector<string> &words = cub[num];
        cout << words.size();
        if(cub[num].size()){
            cout << ' ';
            for(int j = 0; j < words.size(); ++j) cout << words[j] << " \n"[j + 1 == words.size()];
        } else cout << '\n';
    }
}
