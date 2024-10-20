#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

void add_string(const string &s, int trie[][26], int &n){
    int u = 0;
    for(char c : s){
        int e = c - 'a';
        if(!trie[u][e]) trie[u][e] = n++;
        u = trie[u][e];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int P, S; cin >> P >> S;
    while(P && S){
        int trie_es[MAXN][26], trie_pt[MAXN][26];
        memset(trie_es, 0, sizeof(trie_es));
        memset(trie_pt, 0, sizeof(trie_pt));
        int n_es = 1, n_pt = 1;
        for(int i = 0; i < P; ++i){
            string s; cin >> s;
            add_string(s, trie_pt, n_pt);
        }

        for(int i = 0; i < S; ++i){
            string s; cin >> s;
            reverse(s.begin(), s.end());
            add_string(s, trie_es, n_es);
        }

        int ending_pt[26] = {};
        int starting_es[26] = {};

        queue<pair<int, pair<int, int>>> q;
        for(int e = 0; e < 26; ++e) if(trie_pt[0][e]) q.push({trie_pt[0][e], {e, 1}});
        while(q.size()){
            int u, e_from, d;
            tie(e_from, d) = q.front().second;
            u = q.front().first; q.pop();

            if(d > 1) ending_pt[e_from]++;

            for(int e = 0; e < 26; ++e)
                if(trie_pt[u][e]) q.push({trie_pt[u][e], {e, d + 1}});
         }


        for(int e = 0; e < 26; ++e) if(trie_es[0][e]) q.push({trie_es[0][e], {e, 1}});
        while(q.size()){
            int u, e_from, d;
            tie(e_from, d) = q.front().second;
            u = q.front().first; q.pop();

            if(d > 1) starting_es[e_from]++;

            for(int e = 0; e < 26; ++e)
                if(trie_es[u][e]) q.push({trie_es[u][e], {e, d + 1}});
         }

         int64_t ans = 1ll * (n_pt - 1) * (n_es - 1);

         for(int i = 0; i < 26; ++i) ans -= 1ll * ending_pt[i] * starting_es[i];

         cout << ans << '\n';
         cin >> P >> S;
    }
}
