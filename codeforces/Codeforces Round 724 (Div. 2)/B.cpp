/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXSIZE 20'000

using namespace std;

bool comp(string &a, string &b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> all;
    for(char c = 'a'; c <= 'z'; ++c) all.push_back(string(1, c));

    int init = 0;
    while(all.size() < MAXSIZE){
        int N = all.size();
        for(char c = 'a'; c <= 'z' && all.size() < MAXSIZE; ++c){
            for(int i = init; i < N && all.size() < MAXSIZE; ++i){
                all.push_back(all[i] + c);
            }
        }
        init = N;
    }
    sort(all.begin(), all.end(), comp);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        set<int> next;
        map<string, int> pos;
        for(int i = 0; i <= n * n; ++i){
            next.insert(i);
            if(i < all.size()) pos[all[i]] = i;
        }

        for(int i = 0; i < n; ++i){
            string tmp;
            for(int j = i; j < n; ++j){
                tmp += s[j];
                if(pos.count(tmp)) next.erase(pos[tmp]);
            }
        }

        cout << all[*next.begin()] << '\n';
    }
}
