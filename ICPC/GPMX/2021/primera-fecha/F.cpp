/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char c;
    int n, s, dec;
    cin >> n >> s >> c >> dec;
    while(n--){
        string flecha, subt;
        int hh, mm, ss, ml, num;
        cin >> num;
        cin >> hh >> c >> mm >> c >> ss >> c >> ml >> flecha;
        ml += dec;

        ss += s + ml / 1000;
        ml %= 1000;

        mm += ss / 60;
        ss %= 60;

        hh += mm / 60;
        mm %= 60;

        cout << num << '\n';
        cout << setfill('0') << setw(2) << hh << ':'
        << setfill('0') << setw(2) << mm << ':'
        << setfill('0') << setw(2) << ss << ','
        << setfill('0') << setw(3) << ml << ' '
        << flecha << ' ';

        cin >> hh >> c >> mm >> c >> ss >> c >> ml;
        ml += dec;

        ss += s + ml / 1000;
        ml %= 1000;

        mm += ss / 60;
        ss %= 60;

        hh += mm / 60;
        mm %= 60;

        cout << setfill('0') << setw(2) << hh << ':'
        << setfill('0') << setw(2) << mm << ':'
        << setfill('0') << setw(2) << ss << ','
        << setfill('0') << setw(3) << ml << '\n';

        cin.ignore();
        getline(cin, subt);
        cout << subt << '\n';
        getline(cin, subt);
        cout << subt << '\n';
        if(subt != "") cout << '\n';
    }
}
