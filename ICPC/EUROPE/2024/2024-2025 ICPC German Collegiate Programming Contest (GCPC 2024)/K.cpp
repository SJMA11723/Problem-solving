#include<iostream>
#include<bitset>
#include<vector>
#include<map>

#define pb push_back
using namespace std;

string vec(string s){
    string ans;

    for(auto c : s){
        if(c == 'b')ans.pb('p');
        if(c == 'p')ans.pb('b');
        if(c == 'd')ans.pb('q');
        if(c == 'q')ans.pb('d');
    }

    return ans;
}


string hor(string s){
    string ans;

    for(int x = s.size()-1; x >= 0; x--){
        char c = s[x];
        if(c == 'b')ans.pb('d');
        if(c == 'p')ans.pb('q');
        if(c == 'd')ans.pb('b');
        if(c == 'q')ans.pb('p');
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    string t;
    cin>>s>>t;



    map<char, int> freq;
    for(auto c : t){

        if(c != 'r')
        freq[c]++;
        else {
            freq['v']++;
            freq['h']++;
        }
    }

    int h = freq['h']%2;
    int v = freq['v']%2;

    if(h == 0 && v == 0){
        cout<<s<<"\n";
    }
    else if(h == 1 && v == 0){
        cout<<hor(s)<<"\n";
    }
    else if(h == 0 && v == 1){
        cout<<vec(s)<<"\n";
    }
    else{
        //r
        cout<<hor(vec(s))<<"\n";

    }

}
