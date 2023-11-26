/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const string verses[9] = {"99 bottles of beer on the wall, 99 bottles of beer.",
"Take one down and pass it around, 98 bottles of beer on the wall.",
"98 bottles of beer on the wall, 98 bottles of beer.",
"Take one down and pass it around, 97 bottles of beer on the wall.",
"97 bottles of beer on the wall, 97 bottles of beer.",
"Take one down and pass it around, 96 bottles of beer on the wall."};

bool no_quine(char c){
    return c != 'Q' && c != '+' && c != '9' && c != 'H';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cin.ignore();
        vector<string> lines;
        string program;
        for(int i = 0; i < n; ++i){
            string str;
            getline(cin, str);
            lines.push_back(str);
        }

        set<string> quines;
        for(int i = 0; i < n; ++i){
            if(lines[i] == "Hello, world!") program += "H";
            else if(lines[i] == verses[0]){
                bool ok = true;
                bool seis = false;
                for(int j = 0; j < 6 && i < n; ++j, ++i){
                    ok = ok && lines[i] == verses[j];
                    if(j == 5) seis = true;
                }
                if(!ok || !seis){
                    program = "IMPOSSIBLE";
                    break;
                } else program += "9";
                i--;
            } else {
                bool ok = true;
                for(char c : lines[i]){
                    if(no_quine(c)){
                        ok = false;
                        break;
                    }
                }
                if(!ok){
                    program = "IMPOSSIBLE";
                    break;
                } else {
                    quines.insert(lines[i]);
                    program += "Q";
                }
            }
        }

        if(quines.size() > 1) program = "IMPOSSIBLE";
        else if(quines.size() == 1){
            string q = *quines.begin();
            int idx = 0;
            for(int i = 0; i < q.size(); ++i){
                if(idx >= program.size() || ( q[i] != '+' && q[i] != program[idx])){
                    program = "IMPOSSIBLE";
                    break;
                }
                if(q[i] == program[idx]){
                    idx++;
                    continue;
                }
                if(q[i] == '+') continue;
            }
            if(program != "IMPOSSIBLE") program = q;
        }

        cout << program << '\n';
    }
}
