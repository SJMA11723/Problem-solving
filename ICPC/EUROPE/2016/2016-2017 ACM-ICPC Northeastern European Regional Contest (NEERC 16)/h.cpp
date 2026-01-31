#include<bits/stdc++.h>

using namespace std;

char next_word(string &line, string &w){
    w = "";
    while(line.size() && line.back() != ' '){
        w += line.back();
        line.pop_back();
    }
    char ret = 0;
    if(line.size()){
        ret = line.back();
        line.pop_back();
    }
    return ret;
}

bool inter(int a, int b, int c, int d){
    return !(b < c || d < a);
}

const int MINF = -32768;
const int INF = 32767;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream cin("hard.in");
    ofstream cout("hard.out");

    string line;
    int l, r, maxr = MINF;
    char foo;
    bool ok = false;
    set<pair<int, int> > ans;
    while(getline(cin, line)){
        reverse(line.begin(), line.end());

        string str, comp;
        l = MINF;
        r = INF;
        foo = next_word(line, str);
        foo = next_word(line, comp);
        foo = next_word(line, str);
        if(comp == "<=") r = stoi(str);
        else l = stoi(str);

        foo = next_word(line, comp);
        if(comp == "&&"){
            // interseccion de segmentos
            foo = next_word(line, str);
            foo = next_word(line, comp);
            foo = next_word(line, str);
            if(comp == "<=") r = stoi(str);
            else l = stoi(str);
        }

        if(l > r) continue;

        ok = true;
        if(ans.empty()) ans.insert(make_pair(l, r)), maxr = r;
        else {
            auto it = ans.begin();
            while(it != ans.end()){
                if(it->second + 1 == l || r + 1 == it->first || inter(l, r, it->first, it->second)){
                    l = min(l, it->first);
                    r = max(r, it->second);
                    it = ans.erase(it);
                } else it++;
            }
            ans.insert(make_pair(l, r));
        }
    }

    if(!ok){
        cout << "false\n";
        return 0;
    }

    for(pair<int, int> p : ans){
        if(p.first == MINF && p.second == INF){
            cout << "true\n";
            return 0;
        }
        if(p.first == MINF){
            cout << "x <= " << p.second;
        } else if(p.second == INF){
            cout << "x >= " << p.first;
        } else {
            cout << "x >= " << p.first << " && x <= " << p.second;
        }
        if(p.second == ans.rbegin()->second) cout << '\n';
        else cout << " ||\n";
    }
}