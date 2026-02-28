/**
* Author: Mäthgic Crüe
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

int idx(string www){
    if(www == "Mon") return 0;
    if(www == "Tue") return 1;
    if(www == "Wed") return 2;
    if(www == "Thu") return 3;
    if(www == "Fri") return 4;
    if(www == "Sat") return 5;
    return 6;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string www;
    int xx;
    int m1 = 0;
    cin >> www;
    m1 += idx(www) * 1440;
    cin >> xx;
    m1 += xx * 60;
    char foo;
    cin >> foo >> xx;
    m1 += xx;


    int m2 = 0;
    cin >> www;
    m2 += idx(www) * 1440;
    cin >> xx;
    m2 += xx * 60;
    cin >> foo >> xx;
    m2 += xx;

    int M = m2 - m1;
    if(M <= 0) M += 10080;

    int DD, HH, MM;
    MM = M % 60;
    M /= 60;
    HH = M % 24;
    M /= 24;
    DD = M;

    int no0 = bool(MM);
    no0 += bool(HH);
    no0 += bool(DD);
    

    if(no0 == 3){
        cout << DD << ' ';
        if(DD == 1) cout << "day, ";
        else cout << "days, ";

        cout << HH << ' ';
        if(HH == 1) cout << "hour, ";
        else cout << "hours, ";

        cout << MM << ' ';
        if(MM == 1) cout << "minute\n";
        else cout << "minutes\n";
    } else if(no0 == 2){
        int tmp = no0;
        if(DD){
            cout << DD << ' ';
            if(DD == 1) tmp--, cout << "day and ";
            else tmp--, cout << "days and ";
        }

        if(HH){
            cout << HH << ' ';
            if(HH == 1) tmp--, cout << "hour";
            else tmp--, cout << "hours";
            
            if(tmp == 1) cout << " and ";
            else cout << '\n';
        }

        if(MM){
            cout << MM << ' ';
            if(MM == 1) tmp--, cout << "minute\n";
            else tmp--, cout << "minutes\n";
        }
    } else {
        if(DD){
            cout << DD << ' ';
            if(DD == 1) cout << "day\n";
            else cout << "days\n";
        }

        if(HH){
            cout << HH << ' ';
            if(HH == 1) cout << "hour\n";
            else cout << "hours\n";
        }

        if(MM){
            cout << MM << ' ';
            if(MM == 1) cout << "minute\n";
            else cout << "minutes\n";
        }
    }
}