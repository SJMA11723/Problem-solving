// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <cctype>
using namespace std;


string  toUp(string &s){
    string tmp;
    for(auto c : s){
        if('a' <= c && c<='z')tmp.push_back(toupper(c));
        else tmp.push_back(c);
    }
    return tmp;
}
int main() {
	string s;

    getline(cin, s);

    cout<<"What is the name of your team?\n";
    cout<<"Our name is "<<s<<".\n";
    cout<<"My apologies, I did not understand. What is your team name?\n";
    cout<<"We are team "<<s<<".\n"; 
    cout<<"I am really sorry. Could you please repeat it once again?\n";
    cout<<"WE ARE TEAM "<<toUp(s)<<"!!!\n";
    cout<<"Oh, now I see. Here are your badges. Good luck!\n";    

}
