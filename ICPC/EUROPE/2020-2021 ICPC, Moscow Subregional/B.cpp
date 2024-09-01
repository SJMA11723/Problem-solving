#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string team1, team2;
    set<string> A, B;

    map<string, int> scoreA, scoreB;
    vector<pair<string, bool>> order;

    cin >> team1;
    for(int i = 0; i < 5; ++i){
        string s; cin >> s;
        order.push_back({s, 0});
        A.insert(s);
        scoreA[s] = 0;
    }

    cin >> team2;
    for(int i = 0; i < 5; ++i){
        string s; cin >> s;
        order.push_back({s, 1});
        B.insert(s);
        scoreB[s] = 0;
    }

    int q; cin >> q;
    while(q--){
        string team_name; cin >> team_name >> team_name;
        string action; cin >> action;
        if(action == "scored"){
            int x; cin >> x;
            if(team_name == team1){
                for(string s : A) scoreA[s] += x;
                for(string s : B) scoreB[s] -= x;
            } else {
                for(string s : B) scoreB[s] += x;
                for(string s : A) scoreA[s] -= x;
            }
        } else {
            string player1, player2;
            cin >> player1 >> player2 >> player2;
            if(team_name == team1){
                A.erase(player1);
                A.insert(player2);
                if(!scoreA.count(player2)){
                    order.push_back({player2, 0});
                    scoreA[player2] = 0;
                }
            } else {
                B.erase(player1);
                B.insert(player2);
                if(!scoreB.count(player2)){
                    order.push_back({player2, 1});
                    scoreB[player2] = 0;
                }
            }
        }
    }

    for(auto &[p, t] : order){
        if(t) cout << p << " (" << team2 << ") " << (scoreB[p] <= 0 ? "" : "+") << scoreB[p] << '\n';
        else cout << p << " (" << team1 << ") " << (scoreA[p] <= 0 ? "" : "+") << scoreA[p] << '\n';
    }
}
