#include<bits/stdc++.h>

using namespace std;

bool is_capitalized(string &s){
    if(s.size() <= 1) return false;

    if(islower(s[0])) return false;
    for(int i = 1; i < s.size(); ++i)
        if(isupper(s[i])) return false;
    return true;
}

char next_word(string &line, string &w){
    w = "";
    while(line.size() && isalpha(line.back())){
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

bool add_abbr(string &abbr, vector<string> &desc, string &ans){
    if(abbr.empty()) return false;
    if(abbr.size() > 1){
        ans += abbr + " (";
        for(string &s : desc){
            if(ans.back() == '('){
                ans += s;
            } else {
                ans += " " + s;
            }
        }
        ans += ')';
    } else {
        ans += desc[0];
    }
    abbr = "";
    desc.clear();
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream cin("abbreviation.in");
    ofstream cout("abbreviation.out");

    string line;
    while(getline(cin, line)){
        reverse(line.begin(), line.end());
        string ans, abbr, cur_word;
        vector<string> description;
        char sep;
        do{
            sep = next_word(line, cur_word);
            cerr << cur_word << ' ';
            if(is_capitalized(cur_word)){
                abbr += cur_word[0];
                description.push_back(cur_word);
                if(sep != ' '){
                    add_abbr(abbr, description, ans);
                    if(sep) ans += sep;
                }
            } else {
                cerr << "no cap ";
                bool ok = add_abbr(abbr, description, ans);
                if(ok) ans += ' ';
                ans += cur_word;
                if(sep) ans += sep;
            }
            cerr << '\n';
        }while(sep);

        cout << ans << '\n';
    }
}